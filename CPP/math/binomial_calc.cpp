#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>

namespace math
{
namespace binomial
{
/**
 * size_t can store the maximum size of a theoretically possible object of any type
 * int32_t signed integer with 32 bit width
 */

size_t calc(int32_t n, int32_t k)
{
    if (k > (n / 2))
        k = n - k;
    if (k == 1)
        return n;
    if (k == 0)
        return 1;

    size_t result = 1;

    for (int32_t i = 1; i <= k; i++)
    {
        result *= n - k + i;
        result /= i;
    }

    return result;
}
} // namespace binomial
} // namespace math

static void tests()
{
    // tests for calc function
    assert(math::binomial::calc(1, 1) == 1);
    assert(math::binomial::calc(57, 57) == 1);
    assert(math::binomial::calc(6, 3) == 20);
    assert(math::binomial::calc(10, 5) == 252);
    assert(math::binomial::calc(20, 10) == 184756);
    assert(math::binomial::calc(30, 15) == 155117520);
    assert(math::binomial::calc(40, 20) == 137846528820);
    assert(math::binomial::calc(50, 25) == 126410606437752);
    assert(math::binomial::calc(60, 30) == 118264581564861424);
    assert(math::binomial::calc(62, 31) == 465428353255261088);

    std::cout << "[+] Binomial coefficients calc test completed" << std::endl;
}

int main()
{
    tests();

    int32_t n, k;

    std::cout << "Enter N Value: ";
    std::cin >> n;
    std::cout << "Enter K Value: ";
    std::cin >> k;

    std::cout << math::binomial::calc(n, k) << std::endl;
    return 0;
}
