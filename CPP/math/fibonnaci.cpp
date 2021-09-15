#include <cinttypes>
#include <cstdio>
#include <iostream>

#define MAX 93

uint64_t fib(uint64_t n)
{
    static uint64_t f1 = 1, f2 = 1;

    if (n <= 2)
        return f2;
    if (n >= MAX)
    {
        std::cerr << "Cannot computer for n > 93";
        return 0;
    }

    uint64_t temp = f2;
    f2 += f1;
    f1 = temp;

    return f2;
}

/** Main function */
int main()
{
    // Main Function
    for (uint64_t i = 1; i < 93; i++)
    {
        std::cout << i << " th fibonacci number is " << fib(i) << std::endl;
    }
    return 0;
}