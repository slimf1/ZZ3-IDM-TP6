#ifndef BASE_VECTOR_SUM
#define BASE_VECTOR_SUM

#include <algorithm>
#include <numeric>
#include <chrono>
#include <iostream>
#include <vector>

namespace idm {

template <typename BinaryOperation>
struct AccumulateSum {
    double operator()(const std::vector<double>& vector) const {
        return std::accumulate(vector.cbegin(), vector.cend(), 0.0, BinaryOperation());
    }
};

template <typename SumManager>
struct ForEachSum {
    double operator()(const std::vector<double>& vector) const {
        SumManager sumManager;
        std::for_each(vector.cbegin(), vector.cend(), [&sumManager](double value){
            sumManager.sum(value);
        });
        return sumManager.resolve();
    }
};

template <typename SumOperation>
struct VectorSumCalculator {
    void evaluate(const std::vector<double>& vector) const {
        auto t1 = std::chrono::high_resolution_clock::now();
        double result = SumOperation()(vector);
        auto t2 = std::chrono::high_resolution_clock::now();   
        std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
        printf("Result : %.20lf, Time : %dms\n", result, static_cast<int>(fp_ms.count()));
    }
};

}

#endif // BASE_VECTOR_SUM
