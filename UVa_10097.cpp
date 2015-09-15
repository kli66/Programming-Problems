//Using BFS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int g[105][105];
int N1, N2, N3;
int bfs() {
    int dist[105][105] = {};
    int token1, token2;
    queue<int> T1, T2;//token;
    T1.push(N1), T2.push(N2);
    dist[N1][N2] = 1;
    while(!T1.empty()) {
        token1 = T1.front(), T1.pop();
        token2 = T2.front(), T2.pop();
        if(token1 == N3 || token2 == N3)
            return dist[token1][token2];
        if(g[token1][token2]) {//move token1
            if(dist[g[token1][token2]][token2] == 0) {
                dist[g[token1][token2]][token2] = dist[token1][token2]+1;
                T1.push(g[token1][token2]);
                T2.push(token2);
            }
        }
        if(g[token2][token1]) {//move token2
            if(dist[g[token2][token1]][token1] == 0) {
                dist[g[token2][token1]][token1] = dist[token1][token2]+1;
                T1.push(g[token2][token1]);
                T2.push(token1);
            }
        }
    }
    return 0;
}
int main() {
    int n, cases = 0;
    int i, j;
    while(scanf("%d", &n) == 1 && n) {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                scanf("%d", &g[i][j]);
        scanf("%d %d %d", &N1, &N2, &N3);
        int mn = bfs();
        printf("Game #%d\n", ++cases);
        if(mn == 0)
            puts("Destination is Not Reachable !");
        else
            printf("Minimum Number of Moves = %d\n", mn-1);
        puts("");
    }
    return 0;
}
