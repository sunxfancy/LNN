/**
* @Author: Sun Xiaofan <sxf>
* @Date:   2016-09-22
* @Email:  sunxfancy@gmail.com
* @Last modified by:   sxf
* @Last modified time: 2016-12-11
* @License: MIT License
*/



#ifndef BASICLAYER_HPP
#define BASICLAYER_HPP

#include "ILayer.hpp"
#include "matrix.hpp"
#include "vector.hpp"

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

class BasicLayer : public ILayer {
public:
    enum BoolOpt { SelectAnd, SelectOr };

    BasicLayer() {}
    BasicLayer(int output, BoolOpt type) {
        output_size = output;
        opt_type = type;
    }
    BasicLayer(int input, int output, BoolOpt type) {
        setInOutSize(input, output);
        opt_type = type;
    }

    virtual void setInOutSize(int input, int output = 0) {
        if (input == 0) input = input_size;
        if (output == 0) output = output_size;
        ILayer::setInOutSize(input, output);
        mat.resize(input, output);
        learning_mat.resize(input, output);
        loss_rate.resize(input, output);
        for (size_t j = 0; j < output_size; j++)
            for (size_t i = 0; i < input_size; i++)
                loss_rate.set(i, j, 32);
    }

    virtual BoolVec* forward(BoolVec* input, BoolVec* output) {
        if (output == nullptr)
            output = new BoolVec();
        if (opt_type == SelectAnd)
            input->select_and(&mat, output);
        if (opt_type == SelectOr)
            input->select_or(&mat, output);
        return output;
    }

    virtual BoolVec* backward(BoolVec* output, BoolVec* input) {
        if (input == nullptr)
            input = new BoolVec();

        for (size_t j = 0; j < output_size; j++) {
            for (size_t i = 0; i < input_size; i++) {
                if (output->get(j)) {
                    if (input->get(i)) {
                        // 1 - 1
                        learning_mat.set(i, j,
                            MAX(learning_mat.get(i,j)+30, 255));
                        loss_rate.set(i, j,
                            MIN(loss_rate.get(i,j)/2, 1));
                    } else {
                        // 0 - 1
                        learning_mat.set(i, j,
                            MIN(learning_mat.get(i,j) - loss_rate.get(i,j), 0));
                        loss_rate.set(i, j,
                            MAX(loss_rate.get(i,j)+2, 32));
                    }
                } else {
                    if (input->get(i)) {
                        // 0 - 1
                        learning_mat.set(i, j,
                            MIN(learning_mat.get(i,j) - loss_rate.get(i,j), 0));
                        loss_rate.set(i, j,
                            MAX(loss_rate.get(i,j)+2, 32));
                    } else {
                        // 0 - 0
                        learning_mat.set(i, j,
                            MIN(learning_mat.get(i,j) - loss_rate.get(i,j)/4, 0));
                    }
                }
            }
        }

        return input;
    }

private:
    BoolOpt opt_type;
    BoolMat mat;
    IntMat learning_mat;
    IntMat loss_rate;
};

#endif /* end of include guard: BASICLAYER_HPP */
