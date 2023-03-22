#include "Math.hpp"

namespace Utility::Math {

double cosine_similarity(const std::vector<double>& first_vector, const std::vector<double>& second_vector)
{
    if (first_vector.size() != second_vector.size() || first_vector.empty() || second_vector.empty()) {
        throw std::invalid_argument("Vectors must have the same length. And must be more than zero");
    }

    const double dot_product = std::inner_product(first_vector.begin(), first_vector.end(), second_vector.begin(), 0.0);
    const double first_vector_lengh = std::sqrt(std::inner_product(first_vector.begin(), first_vector.end(), first_vector.begin(), 0.0));
    const double second_vector_lengh = std::sqrt(std::inner_product(second_vector.begin(), second_vector.end(), second_vector.begin(), 0.0));

    return dot_product / (first_vector_lengh * second_vector_lengh);
}

}