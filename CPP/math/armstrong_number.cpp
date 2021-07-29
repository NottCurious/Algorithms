#include <cassert>
#include <cmath>
#include <iostream>

namespace math
{
namespace armstrong
{
int num_digits(int num)
{
    int digits = 0;

    while (num > 0)
    {
        num /= 10;
        digits++;
    }

    return digits;
}

bool check_armstrong(int num)
{
    if (num < 0)
        return false;

    int sum = 0, temp = num, digits = num_digits(num);

    while (temp > 0)
    {
        int rem = temp % 10;

        sum = sum + std::pow(rem, digits);
        temp = temp / 10;
    }

    return num == sum;
}
} // namespace armstrong
} // namespace math

void test()
{
    // math::armstrong::check_armstrong(370) returns true.
    assert(math::armstrong::check_armstrong(370) == true);
    // math::armstrong::check_armstrong(225) returns false.
    assert(math::armstrong::check_armstrong(225) == false);
    // math::armstrong::check_armstrong(-23) returns false.
    assert(math::armstrong::check_armstrong(-23) == false);
    // math::armstrong::check_armstrong(0) returns true.
    assert(math::armstrong::check_armstrong(0) == true);
    // math::armstrong::check_armstrong(12) returns false.
    assert(math::armstrong::check_armstrong(12) == false);
}

int main()
{
    test();
    return 0;
}