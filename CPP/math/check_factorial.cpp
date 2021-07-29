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
    assert(math::factorial::is_factorial(50) == false);
    assert(math::factorial::is_factorial(720) == true);
    assert(math::factorial::is_factorial(0) == false);
    assert(math::factorial::is_factorial(479001600) == true);
    assert(math::factorial::is_factorial(-24) == false);
}

int main()
{
    tests();
    return 0;
}