#ifndef KAHAN_VECTOR_SUM
#define KAHAN_VECTOR_SUM

namespace idm {

class KahanVectorSum {
private:
    double _c = 0.0;
    double _t, _y;

public:
    double operator()(double sum, double value) {
        _y = value - _c;
        _t = sum + _y;
        _c = (_t - sum) - _y;
        return _t;
    }
};

}

#endif // KAHAN_VECTOR_SUM
