#include <algorithm>
#include <random>
#include <stdio.h>
#include "random_vector.hpp"

namespace idm {

std::vector<double> generate_random_normal_vector(size_t size, double mu, double sigma) {
    std::vector<double> result(size);
    std::mt19937 rng;
    std::normal_distribution normDist(mu, sigma);

    std::generate(result.begin(), result.end(), [&rng, &normDist](){
        return normDist(rng);
    });

    return result;
}

void pretty_print(const std::vector<double>& vector, std::ostream& stream) {
    for(size_t i = 1u; i <= vector.size(); ++i) {
        stream << vector[i] << ' ';

        if (i % 10 == 0) {
            stream << '\n';
        }
    }
}

}