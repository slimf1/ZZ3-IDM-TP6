#ifndef KAHAN_VECTOR_SUM
#define KAHAN_VECTOR_SUM

#include "base_vector_sum.hpp"
#include <iostream>

class KahanVectorSum {
private:
    double _c = 0.0;
    double _t, _y;

public:
    double operator()(double sum, double value) {
        // std::cout << "sum : " << sum << ", value = " << value << '\n';
        _y = value - _c;
        _t = sum + _y;
        _c = (_t - sum) - _y;
        // std::cout << "sum: " << sum << "\n";
        return _t;
    }
};

#endif // KAHAN_VECTOR_SUM
