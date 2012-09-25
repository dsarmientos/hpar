#include <algorithm>
#include <cstdio>

int main()
{
    char xs[] = "1122";
    do
    {
        std::puts(xs);
    }
    while (std::next_permutation(xs, xs + sizeof(xs) - 1));
    return 0;
}
