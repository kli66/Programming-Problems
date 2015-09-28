#include <cstdio>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    unsigned int N, L, U, M, temp, m;
    int i;
    while (~scanf("%u%u%u", &N, &L, &U))
    {
        m = 0;
        for (i = 31; i >= 0; i--)
        {
            temp = m | (1u << i);
            if (((N >> i) & 1) == 0 && temp <= U || ((L >> i) & 1) && m < L)
                m = temp;
        }
        printf("%u\n", m);
    }
    return 0;
}
