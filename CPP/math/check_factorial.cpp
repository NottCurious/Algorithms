#include <cassert>
#include <iostream>

namespace math
{
namespace factorial
{
bool is_factorial(uint64_t n)
{
    if (n <= 0)
        return false;

    for (uint32_t i = 1;; i++)
    {
        if (n % i != 0)
            break;

        n /= i;
    }
    if (n == 1)
        return true;
    else
        return false;
}
} // namespace factorial
} // namespace math

void tests()
{
    std::cout << "Test 1:\t n=50\n";
    assert(math::factorial::is_factorial(50) == false);
    std::cout << "passed\n";

    std::cout << "Test 2:\t n=720\n";
    assert(math::factorial::is_factorial(720) == true);
    std::cout << "passed\n";

    std::cout << "Test 3:\t n=0\n";
    assert(math::factorial::is_factorial(0) == false);
    std::cout << "passed\n";

    std::cout << "Test 4:\t n=479001600\n";
    assert(math::factorial::is_factorial(479001600) == true);
    std::cout << "passed\n";

    std::cout << "Test 5:\t n=-24\n";
    assert(math::factorial::is_factorial(-24) == false);
    std::cout << "passed\n";
}

int main()
{
    tests();
    return 0;
}