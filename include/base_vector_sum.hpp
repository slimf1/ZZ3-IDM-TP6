#ifndef BASE_VECTOR_SUM
#define BASE_VECTOR_SUM

#include <algorithm>
#include <numeric>
#include <chrono>
#include <iostream>
#include <vector>

template <typename BinaryOperation>
struct BaseVectorSum {
    void evaluate(const std::vector<double>& vector) {
        auto t1 = std::chrono::high_resolution_clock::now();
        double result = std::accumulate
                            <std::vector<double>::const_iterator, double, BinaryOperation>
                            (vector.cbegin(), vector.cend(), 0.0, BinaryOperation());
        auto t2 = std::chrono::high_resolution_clock::now();   
        std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
        printf("Result : %.20lf, Time : %dms\n", result, static_cast<int>(fp_ms.count()));
    }
};

#endif // BASE_VECTOR_SUM
