#include <cstdio>
#include <cmath>
using namespace std;

int a[100001];

int main()
{
    int n;
    while(scanf("%d",&n)){
        if (n==0) break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);

        long long int ans=0;
        for(int i=0;i<n-1;i++){
            ans += abs(a[i]);
            a[i+1] += a[i];
        }

        printf("%lld\n",ans);
    }
    return 0;
}
