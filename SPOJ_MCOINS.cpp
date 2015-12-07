#include <cstdio>
#define SIZE 1000100
using namespace std;

int main(){
	int k,l,m,n,i;
	bool OPT[SIZE];

	OPT[0] = false;
	scanf("%d %d %d",&k,&l,&m);

	//DP Soln, Idea: if can win with c coins, then can win with c+k or c+l coins
	for(i=1;i<SIZE;i++){
		if( i-1 >=0 && OPT[i-1]==false){
			OPT[i]=true;
		}
		else if( i-k >=0 && OPT[i-k]==false){
			OPT[i]=true;
		}
		else if( i-l >=0 && OPT[i-l]==false){
			OPT[i]=true;
		}
		else{
			OPT[i] = false;
		}
	}

	for(i=0;i<m;i++){
		scanf("%d",&n);
		(OPT[n])?printf("A"):printf("B");
	}
	return 0;
}
