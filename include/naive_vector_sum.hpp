#ifndef NAIVE_VECTOR_SUM
#define NAIVE_VECTOR_SUM

#include "base_vector_sum.hpp"

class NaiveVectorSum {
private:
    double _current = 0;

public:

    void sum(double input) {
        _current += input;
    }

    double resolve() const {
        return _current;
    } 
};

#endif // NAIVE_VECTOR_SUMM
