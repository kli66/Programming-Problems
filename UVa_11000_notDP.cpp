#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
long long f[60],m[60];

int main(){
	m[1] = 1LL,m[0] = 0LL;
	for (int i = 2 ; i < 60 ; ++ i){
        m[i] = m[i-2]+m[i-1]+1LL;
    }
	int n;
	while (~scanf("%d",&n) && n != -1){
        printf("%lld %lld\n",m[n],m[n+1]);
    }
    return 0;
}
