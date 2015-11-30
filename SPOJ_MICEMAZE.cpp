//Floyd-Warshall soultion

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000

int main()
{
	int n,e,t,m,a,b,c, opt[MAX][MAX];

	scanf("%d%d%d%d", &n, &e, &t, &m);
	memset(opt, 32, sizeof(opt));

	int i,j,k;

	for(i=opt[e][e]=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		opt[a][b] = c;
	}
	for(k=1; k<=n; k++){
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				//opt-for package-solution
				opt[i][j] = min(opt[i][j], opt[i][k] + opt[k][j]);
			}
		}
	}

	for(i=1,k=0; i<=n; i++){
		if(opt[i][e] <= t){
			k++;
		}
	}

	printf("%d\n", k);
	return 0;
}
