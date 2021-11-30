#include <algorithm>
#include <random>
#include <stdio.h>
#include "random_vector.hpp"

namespace idm {

std::vector<double> generate_random_normal_vector(size_t size, double mu, double sigma) {
    std::vector<double> result(size);
    std::mt19937 rng;
    std::uniform_real_distribution<double> normDist(mu, sigma);

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

double naive_vector_sum(const std::vector<double>& vector) {
    return std::accumulate(vector.cbegin(), vector.cend(), 0.);
}

double kahan_vector_sum(const std::vector<double>& vector) {
    double sum = 0.0;
    double c = 0.0;
    double t, y;

    for(size_t i = 0; i < vector.size(); ++i) {
        y = vector[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t; 
    }

    return sum;
}

double kahan_babushka_klein_vector_sum(const std::vector<double>& vector) {
    double sum = 0.0;
    double cs = 0.0;
    double ccs = 0.0;
    double c = 0.0;
    double cc = 0.0;
    double t;

    for(size_t i = 0; i < vector.size(); ++i) {
        t = sum + vector[i];
        if (std::fabs(sum) >= std::fabs(vector[i])) {
            c = (sum - t) + vector[i];
        } else {
            c = (vector[i] - t) + sum;
        }
        sum = t;
        t = cs + c;
        if (std::fabs(cs) >= std::fabs(c)) {
            cc = (cs - t) + c;
        } else {
            cc = (c - t) + cs;
        }
        cs = t;
        ccs = ccs + cc;
   }

   return sum + cs + ccs;
}

}