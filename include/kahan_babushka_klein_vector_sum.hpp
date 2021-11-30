#ifndef KAHAN_BABUSHKA_KLEIN_VECTOR_SUM
#define KAHAN_BABUSHKA_KLEIN_VECTOR_SUM

#include <cmath>
#include "base_vector_sum.hpp"

class KahanBabushkaKleinVectorSum : public BaseVectorSum {
private:
    double _sum = 0.0;
    double _cs = 0.0;
    double _ccs = 0.0;
    double _c = 0.0;
    double _cc = 0.0;
    double _t;
    
public:

    void sum(double input) override {
        _t = _sum + input;
        if (std::fabs(_sum) >= std::fabs(input)) {
            _c = (_sum - _t) + input;
        } else {
            _c = (input - _t) + _sum;
        }
        _sum = _t;
        _t = _cs + _c;
        if (std::fabs(_cs) >= std::fabs(_c)) {
            _cc = (_cs - _t) + _c;
        } else {
            _cc = (_c - _t) + _cs;
        }
        _cs = _t;
        _ccs = _ccs + _cc;
    }

    double resolve() const {
        return _sum + _cs + _ccs;
    } 
};

#endif // KAHAN_BABUSHKA_KLEIN_VECTOR_SUM
