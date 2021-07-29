#include <cassert>
#include <iostream>

namespace math
{
namespace prime
{
template <typename T>

bool is_prime(T num)
{
    bool result = true;

    if (num <= 1)
        return 0;
    else if (num == 2)
        return 1;
    else if ((num & 1) == 0)
        return 0;

    if (num >= 3)
    {
        for (T i = 3; (i * i) <= num; i += 2)
        {
            if ((num % i) == 0)
            {
                result = false;
                break;
            }
        }
    }

    return result;
}
} // namespace prime
} // namespace math

int main()
{
    assert(math::prime::is_prime(50) == false);
    assert(math::prime::is_prime(115249) == true);

    int num;
    std::cout << "Enter the number to check if it is prime or not" << std::endl;
    std::cin >> num;
    bool result = math::prime::is_prime(num);
    if (result)
    {
        std::cout << num << " is a prime number" << std::endl;
    }
    else
    {
        std::cout << num << " is not a prime number" << std::endl;
    }

    return 0;
}