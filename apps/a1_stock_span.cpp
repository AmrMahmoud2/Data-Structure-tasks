#include <iostream>
#include "MGY.hpp"
#include "Amr.hpp"
int main()
{
    int n;
    std::cout << "Put Your Data Number : ";
    std::cin >> n;
    int p[n];
    int s[n];
    for (int k = 0; k < n; k++)
    {
        std::cin >> p[k];
    }
    stack::IntegersStackArray N;

    s[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ++N.top;
        while (!(isEmpty(N)) && p[i] >= p[N.top])
            pop(N);

        if (isEmpty(N))

        {
            s[i] = i + 1;
            ++N.top;
        }

        else
            s[i] = i - N.top;

        push(N, i);
    }
    for (int h = 0; h < n; h++)
    {
        std::cout << s[h] << ",";
    }

    return 0;
}