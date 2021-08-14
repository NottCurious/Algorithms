#include <cstring>
#include <fstream>
#include <iostream>

const int mxN = 1e8;

char prime[mxN];

namespace math
{
namespace primes
{
void Sieve(int64_t n)
{
    memset(prime, '1', sizeof(prime));
    prime[0] = '0';
    prime[1] = '1';

    for (int64_t p = 2; p * p <= n; p++)
    {
        if (prime[p] == '1')
        {
            for (int64_t i = p * p; i <= n; i += p)
                prime[i] = '0';
        }
    }
}
} // namespace primes
} // namespace math

int main()
{
    math::primes::Sieve(100000000);
    int64_t n = 100, count = 0;
    std::cout << "Enter Max Value: ";
    std::cin >> n;
    std::cout << std::endl;
    std::ofstream file;
    file.open("putabout.txt");

    for (int i = 0; i < n; i++)
    {
        if (prime[i] == '1')
        {
            // std::cout << i << std::endl;
            file << i << std::endl;
            count++;
        }
    }

    std::cout << "Number of Primes: " << count << std::endl;
}
