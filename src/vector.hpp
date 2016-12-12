/**
* @Author: Sun Xiaofan <sxf>
* @Date:   2016-09-22
* @Email:  sunxfancy@gmail.com
* @Last modified by:   sxf
* @Last modified time: 2016-12-11
* @License: MIT License
*/



#ifndef BOOLVEC_HPP
#define BOOLVEC_HPP

#include "boost/dynamic_bitset.hpp"
typedef boost::dynamic_bitset<size_t> boolvec;
#include "matrix.hpp"

class BoolVec {
public:
    BoolVec() {}
    BoolVec(int x) : data(x) {}

    BoolVec* add(bool x) {
        data.push_back(x);
        return this;
    }
    BoolVec* set(int p, bool x) {
        data[p] = x;
        return this;
    }

    bool get(int p) const{
        return data[p];
    }

    int size() const{
        return data.size();
    }

    BoolVec* select_and_ans(BoolMat* mat, BoolVec* ans) {
        return mul(mat, true, ans);
    }

    BoolVec* select_or_ans(BoolMat* mat, BoolVec* ans) {
        return mul(mat, false, ans);
    }

    BoolVec* select_and(BoolMat* mat) {
        return mul(mat, true, nullptr);
    }

    BoolVec* select_or(BoolMat* mat) {
        return mul(mat, false, nullptr);
    }

    BoolVec* mul(BoolMat* mat, bool is_and, BoolVec* ans) {
        if (ans == nullptr) ans = new BoolVec(mat->size_y());
        for (auto vec : mat->data) {
            if (is_and) {
                boolvec p = data | ~vec;
                ans->add(p.all());
            } else {
                boolvec p = data & vec;
                ans->add(p.any());
            }
        }
        return ans;
    }

    std::string to_string() const {
        std::string ans;
        ans += std::to_string(data.size());
        ans += '{';
        for (int i = 0; i < data.size(); ++i) {
            if (get(i)) ans += " 1";
            else ans += " 0";
        }
        ans += " }\n";
        return ans;
    }

private:
    boolvec data;
};


#endif /* end of include guard: BOOLVEC_HPP */
