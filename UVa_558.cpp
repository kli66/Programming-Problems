#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define N 2005
const int INF = 0x3f3f3f;
int n, m, flag;
int x[N], y[N], v[N], d[N];
void bellmanFord() {
    flag = 0;
    for (int i = 0; i < n; i++) d[i] = INF;
    d[0] = 0;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a = x[j], b = y[j];
            if (d[a] < INF) {
                d[b] = min(d[a] + v[j], d[b]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        a = x[i], b = y[i];
        if (d[b] > d[a] + v[i])
        {
            flag = 1;
            return;
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x[i], &y[i], &v[i]);
        }
        bellmanFord();
        if (flag) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
