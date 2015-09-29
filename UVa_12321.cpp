#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int L, n, x, r;
    int i, j, k;
    pair<int, int> range[10000];
    while(scanf("%d %d", &L, &n) == 2 && L){
        for(i = 0; i < n; i++) {
            scanf("%d %d", &x, &r);
            range[i] = make_pair(x-r, x+r);
        }
        sort(range, range+n);

        int tr, r = 0, ret = n;
        i = 0;
        while(r < L){
            tr = r;
            while(i < n && range[i].first <= r){
                if(tr < range[i].second)
                    tr = range[i].second;
                i++;
            }
            if(tr == r){
                break;
            }
            r = tr;
            ret--;
        }
        if(r < L){
            puts("-1");
        }
        else{
            printf("%d\n", ret);
        }
    }
    return 0;
}
