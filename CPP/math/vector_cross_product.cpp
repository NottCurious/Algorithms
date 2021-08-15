#include <array>
#include <cassert>
#include <cmath>
#include <iostream>

namespace math
{
namespace vector
{
std::array<double, 3> cross(const std::array<double, 3> &A, const std::array<double, 3> &B)
{
    std::array<double, 3> product;

    product[0] = (A[1] * B[2]) - (A[2] * B[1]);
    product[1] = -((A[0] * B[2]) - (A[2] * B[0]));
    product[2] = (A[0] * B[1]) - (A[1] * B[0]);

    return product;
}

double mag(const std::array<double, 3> &vec)
{
    double magnitude = sqrt((vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]));
    return magnitude;
}
} // namespace vector
} // namespace math

// ---------------Below this Line was Copy Pasted from
// https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/math/vector_cross_product.cpp#L90
// ----------------------------

/**
 * @brief test function.
 * @details test the cross() and the mag() functions.
 */
static void test()
{
    /// Tests the cross() function.
    std::array<double, 3> t_vec = math::vector::cross({1, 2, 3}, {4, 5, 6});
    assert(t_vec[0] == -3 && t_vec[1] == 6 && t_vec[2] == -3);

    /// Tests the mag() function.
    double t_mag = math::vector::mag({6, 8, 0});
    assert(t_mag == 10);
}

/**
 * @brief Main Function
 * @details Asks the user to enter the direction ratios for each of the two mathematical vectors using std::cin
 * @returns 0 on exit
 */
int main()
{

    /// Tests the functions with sample input before asking for user input.
    test();

    std::array<double, 3> vec1;
    std::array<double, 3> vec2;

    /// Gets the values for the first vector.
    std::cout << "\nPass the first Vector: ";
    std::cin >> vec1[0] >> vec1[1] >> vec1[2];

    /// Gets the values for the second vector.
    std::cout << "\nPass the second Vector: ";
    std::cin >> vec2[0] >> vec2[1] >> vec2[2];

    /// Displays the output out.
    std::array<double, 3> product = math::vector::cross(vec1, vec2);
    std::cout << "\nThe cross product is: " << product[0] << " " << product[1] << " " << product[2] << std::endl;

    /// Displays the magnitude of the cross product.
    std::cout << "Magnitude: " << math::vector::mag(product) << "\n" << std::endl;

    return 0;
}