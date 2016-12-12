/**
* @Author: Sun Xiaofan <sxf>
* @Date:   2016-09-22
* @Email:  sunxfancy@gmail.com
* @Last modified by:   sxf
* @Last modified time: 2016-12-11
* @License: MIT License
*/



#ifndef LNN_HPP
#define LNN_HPP

#include <vector>
#include "ILayer.hpp"

class lnn : public ILayer {
public:
    lnn() {}

    lnn* add(ILayer* layer) {
        ctr.push_back(layer);
        return this;
    }

    virtual BoolVec* forward(BoolVec* input, BoolVec* output) {

        return output;
    };

    virtual BoolVec* backward(BoolVec* output, BoolVec* input) {

        return input;
    };

private:
    std::vector<ILayer*> ctr;
};

#endif /* end of include guard: LNN_HPP */
