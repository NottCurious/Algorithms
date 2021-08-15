#include <iostream>

namespace math
{
namespace pow
{
double fastpow(int a, int b)
{
    if (b < 0)
    {
        return 1 / fastpow(a, -b);
    }

    if (b == 0)
    {
        return 1;
    }

    double bottom = fastpow(a, b >> 1);

    double result;

    if ((b & 1) == 0)
    {
        result = bottom * bottom;
    }
    else
    {
        result = bottom * bottom * a;
    }

    return result;
}
} // namespace pow
} // namespace math

int main()
{
    int a, b;

    std::cout << "Enter A Value: ";
    std::cin >> a;
    std::cout << "Enter B Value: ";
    std::cin >> b;

    std::cout << std::endl << "Pow(" << a << ", " << b << ") = " << math::pow::fastpow(a, b);
}