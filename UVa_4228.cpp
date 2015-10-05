#include <iostream>
#include <cstdio>
using namespace std;


int main(){
	int n;
	
	int ip;
	int sum = 0;
	while(scanf("%d", &n) && n){
		int org[49]={0};
		while(n--){
			for(int i=0; i<6; i++){
				scanf("%d", &ip);
				org[ip]=1;
			}
		}
		for(int j=0; j<=49; j++){
			sum+=org[j];
		}
		if(sum == 49){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		sum = 0;
	}
	return 0;
}
