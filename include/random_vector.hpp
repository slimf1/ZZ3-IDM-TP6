#ifndef RANDOM_VECTOR_HPP
#define RANDOM_VECTOR_HPP

#include <vector>
#include <iostream>

namespace idm {

std::vector<double> generate_random_normal_vector(size_t size, double mu = 0., double sigma = 1.);
void pretty_print(const std::vector<double>& vector, std::ostream& stream = std::cout);
double naive_vector_sum(const std::vector<double>& vector); // template vector sum?
double kahan_vector_sum(const std::vector<double>& vector);
double kahan_babushka_klein_vector_sum(const std::vector<double>& vector);

} // namespace idm

#endif // RANDOM_VECTOR_HPP
