#ifndef BASE_VECTOR_SUM
#define BASE_VECTOR_SUM

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

template <typename SumMethod>
struct BaseVectorSum : public SumMethod {
    void evaluate(const std::vector<double>& vector) {
        auto t1 = std::chrono::high_resolution_clock::now();

        std::for_each(vector.cbegin(), vector.cend(), [this](double value){
            this->sum(value);
        });

        // std::accumulate (au dessus) & std::plus

        auto t2 = std::chrono::high_resolution_clock::now();   
        std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
        printf("Result : %.20lf, Time : %dms\n", this->resolve(), static_cast<int>(fp_ms.count()));
    }
};

#endif // BASE_VECTOR_SUM
