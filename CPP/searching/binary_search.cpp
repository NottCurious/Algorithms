#include <iostream>

namespace search
{
int binary_search(int a[], int r, int key)
{
    int l = 0;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (key == a[m])
            return m;
        else if (key < a[m])
            r = m - 1;
        else
            l = m + 1;
    }

    return -1;
}
} // namespace search

int main()
{
    int n, key;

    std::cout << "Enter Size of Array: ";
    std::cin >> n;

    int *a = new int[n];

    std::cout << "Enter Array Elements";

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int k;

    std::cout << "Enter Value to be Searched for: ";
    std::cin >> k;

    std::cout << search::binary_search(a, n - 1, k);

    delete[] a;
    return 0;
}