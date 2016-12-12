/**
* @Author: Sun Xiaofan <sxf>
* @Date:   2016-09-22
* @Email:  sunxfancy@gmail.com
* @Last modified by:   sxf
* @Last modified time: 2016-12-11
* @License: MIT License
*/



#ifndef BOOLMATRIX_HPP
#define BOOLMATRIX_HPP

#include "boost/dynamic_bitset.hpp"
typedef boost::dynamic_bitset<size_t> boolvec;
#include <vector>
#include <string>

class BoolMat {
public:
    BoolMat() {}
    BoolMat(int x, int y) {
        resize(x, y);
    }

    void resize(int x, int y) {
        data.resize(y);
        for (int i = 0; i < y; ++i) {
            data[i].resize(x);
        }
        this->x = x;
        this->y = y;
    }

    BoolMat* set(int x, int y, bool a) {
        data[x][y] = a;
        return this;
    }

    bool get(int x, int y) const {
        return data[x][y];
    }

    int size_x() const {
        return x;
    }
    int size_y() const {
        return y;
    }

    std::string to_string() const {
        std::string ans;
        ans += "BoolMat";
        ans += std::to_string(x);
        ans += " x ";
        ans += std::to_string(y);
        ans += "'\n[";
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (get(i, j)) ans += " 1";
                else ans += " 0";
            }
            ans += '\n';
        }
        ans += "]\n";
        return ans;
    }

private:
    int x, y;

    friend class BoolVec;
    std::vector<boolvec> data;
};


class IntMat {
public:
    IntMat() {}
    IntMat(int x, int y) {
        resize(x, y);
    }

    void resize(int x, int y) {
        data.resize(y);
        for (int i = 0; i < y; ++i) {
            data[i].resize(x);
        }
        this->x = x;
        this->y = y;
    }

    IntMat* set(int x, int y, unsigned char a) {
        data[x][y] = a;
        return this;
    }

    unsigned char get(int x, int y) const {
        return data[x][y];
    }

    int size_x() const {
        return x;
    }
    int size_y() const {
        return y;
    }

private:
    int x, y;
    std::vector<std::vector<char> > data;
};

#endif /* end of include guard: BOOLMATRIX_HPP */
