#include <stdio.h>
#include <string.h>
#define SIZE 200



int main(){
	int d,n,k,m;
	//DP approach,f[i][j] is the number of arrangements with j*'['
	//unpaired in the first i positions.
	int OPT[SIZE][SIZE];
	bool OPEN[SIZE];

	scanf("%d", &d);
	while(d--){
		scanf("%d%d", &n, &k);

		memset(OPEN, 0, sizeof OPEN);
		memset(OPT, 0, sizeof OPT);

		for(int i = 1; i <= k; i++){
			scanf("%d", &m);
			OPEN[m] = true;
		}

		OPT[0][0] = 1;
		for(int i = 1; i <= 2 * n; i++){
			for(int j = 0; j <= 2 * n; j++){
				if(OPEN[i]){
					//specified to be '[' at ith position
					if(j != 0){
						OPT[i][j] = OPT[i-1][j-1];
					}
					else{
						OPT[i][j] =  0;
					}
				}
				else{
					//if not necessarily open, two cases are possible
					if(j != 0){
						OPT[i][j] = OPT[i-1][j-1] + OPT[i-1][j+1];
					}
					else{
						OPT[i][j] = OPT[i-1][j+1];
					}
				}
			}
		}
		printf("%d\n", OPT[2*n][0]);
	}
	return 0;
}
