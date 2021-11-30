#include <iostream>
#include <stdio.h>
#include "random_vector.hpp"
#include "base_vector_sum.hpp"
// #include "naive_vector_sum.hpp"
// #include "kahan_vector_sum.hpp"
// #include "kahan_babushka_klein_vector_sum.hpp"

int main() {
    auto vector = idm::generate_random_normal_vector(1e5);

    BaseVectorSum<std::plus<double>>{}.evaluate(vector);

    // idm namespace !!!
    
    // NaiveVectorSum s;
    // s.evaluate(vector); // méthode pour init

    // KahanVectorSum v;
    // v.evaluate(vector);

    // KahanBabushkaKleinVectorSum b;
    // b.evaluate(vector);

    // // 1500003897.00309705734252929688 (3e9)
    // // 1500003897.00322484970092773438
    // printf("%.20lf\n", idm::naive_vector_sum(vector));
    // printf("%.20lf\n", idm::kahan_vector_sum(vector));
    // printf("%.20lf\n", idm::kahan_babushka_klein_vector_sum(vector));

    

    // float f = 0.1f;
    // float sum = 0 ;
    // for (int i = 0; i < 11; ++i) sum += f;
    // float product = f * 11;
    // printf("sum = %1.15f, mul = %1.15f, mul2 = %1.15f\n", sum, product, f * 11);
}