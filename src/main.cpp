#include <iostream>
#include <stdio.h>
#include "random_vector.hpp"
#include "base_vector_sum.hpp"
#include "kahan_vector_sum.hpp"
#include "kahan_babushka_klein_vector_sum.hpp"

int main() {
    auto vector = idm::generate_random_normal_vector(5e7);
    VectorSumCalculator<AccumulateSum<std::plus<double>>>().evaluate(vector);
    VectorSumCalculator<AccumulateSum<KahanVectorSum>>().evaluate(vector);
    VectorSumCalculator<ForEachSum<KahanBabushkaKleinVectorSum>>().evaluate(vector);
}
