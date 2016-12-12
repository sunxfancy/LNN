#ifndef LAYER_HPP
#define LAYER_HPP

class BoolVec;

class ILayer {
public:
    virtual void setInOutSize(int input, int output = 0) {
        input_size = input; output_size = output;
    }
    virtual int getInputSize() { return input_size; }
    virtual int getOutputSize() { return output_size; }

    virtual BoolVec* forward(BoolVec* input, BoolVec* output) = 0;
    virtual BoolVec* backward(BoolVec* output, BoolVec* input) = 0;

protected:
    int input_size;
    int output_size;
};

#endif /* end of include guard: LAYER_HPP */
