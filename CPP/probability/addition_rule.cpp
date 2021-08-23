#include <iostream>

namespace math
{
namespace addition_rule
{
double addition_rule_independent(double a, double b)
{
    return (a + b) - (a * b);
}

double addition_rule_dependent(double a, double b, double b_given_a)
{
    return (a + b) - (a * b_given_a);
}
} // namespace addition_rule
} // namespace math

int main()
{
    double a = 0.5;
    double b = 0.25;
    double b_given_a = 0.05;

    std::cout << "independent P(a or b) = " << math::addition_rule::addition_rule_independent(a, b) << std::endl;

    std::cout << "dependent P(a or b) = " << math::addition_rule::addition_rule_dependent(a, b, b_given_a) << std::endl;

    return 0;
}