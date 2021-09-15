#include <cassert>
#include <iostream>

uint64_t double_factorial_iterative(uint64_t n)
{
    uint64_t res = 1;

    for (uint64_t i = n;; i -= 2)
    {
        if (i == 0 || i == 1)
            return res;
        res *= i;
    }

    return res;
}

uint64_t double_factorial_recursive(uint64_t n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * double_factorial_recursive(n - 2);
}

/** Wrapper to run tests using both recursive and iterative implementations.
 * The checks are only valid in debug builds due to the use of `assert()`
 * statements.
 * \param [in] n number to check double factorial for
 * \param [in] expected expected result
 */
void test(uint64_t n, uint64_t expected)
{
    assert(double_factorial_iterative(n) == expected);
    assert(double_factorial_recursive(n) == expected);
}

/**
 * Test implementations
 */
void tests()
{
    std::cout << "Test 1:\t n=5\t...";
    test(5, 15);
    std::cout << "passed\n";

    std::cout << "Test 2:\t n=15\t...";
    test(15, 2027025);
    std::cout << "passed\n";

    std::cout << "Test 3:\t n=0\t...";
    test(0, 1);
    std::cout << "passed\n";
}

/**
 * Main function
 */
int main()
{
    tests();
    return 0;
}