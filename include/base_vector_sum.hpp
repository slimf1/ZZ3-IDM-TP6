#ifndef BASE_VECTOR_SUM
#define BASE_VECTOR_SUM

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

struct BaseVectorSum {
    virtual void sum(double input) = 0;
    virtual double resolve() const = 0;

    void evaluate(const std::vector<double>& vector) {
        auto t1 = std::chrono::high_resolution_clock::now();

        std::for_each(vector.cbegin(), vector.cend(), [&](double value){
            sum(value);
        });

        auto t2 = std::chrono::high_resolution_clock::now();   
        std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
        printf("Result : %.20lf, Time : %dms\n", resolve(), static_cast<int>(fp_ms.count()));
    }
};

#endif // BASE_VECTOR_SUM
