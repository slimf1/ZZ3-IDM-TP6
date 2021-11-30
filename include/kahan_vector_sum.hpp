#ifndef KAHAN_VECTOR_SUM
#define KAHAN_VECTOR_SUM

#include "base_vector_sum.hpp"

class KahanVectorSum {
private:
    double _sum = 0.0;
    double _c = 0.0;
    double _t, _y;

public:

    void sum(double input) {
        _y = input - _c;
        _t = _sum + _y;
        _c = (_t - _sum) - _y;
        _sum = _t; 
    }

    double resolve() const {
        return _sum;
    } 
};

#endif // KAHAN_VECTOR_SUM
