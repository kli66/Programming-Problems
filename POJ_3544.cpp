#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    long long int val;
    int pos;
    bool operator < (const Node a) const{
        return val > a.val;
    }
}weight[1001], earning[1001];

int main(){
    long long int dis[1001], ans[1001];
    int n;
    long long int t;
    while(scanf("%d%lld", &n, &t)){
        for (int i=0; i<n; i++){
            scanf("%lld", &weight[i].val);
            weight[i].pos =i;
        }
        for(int i =0; i<n; i++){
            scanf("%lld", dis[i]);
        }
        for(int i=0; i<n; i++){
            long long int pj;
            scanf("%lld", pj);
            earning[i].val = pj - dis[i]*t;
            earning[i].pos = i;
        }
        sort(weight, weight+n);
        sort(earning, earning+n);
        for(int i =0; i<n; i++){
            ans[earning[i].pos]= weight[i].pos;
        }
        for(int i=1; i<n; i++){
            printf("%lld ",ans[i]);
        }
        //satiisfying output guidelines
        printf("%lld", ans[n]);
    }
    return 0;
}
