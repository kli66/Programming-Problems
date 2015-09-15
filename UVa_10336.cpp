
#include<stdio.h>
#include<string.h>

char map[1000][1000] = {0};
int maparea[1000][1000] = {0};

void DFS( int number, int x, int y )
{
    maparea[y][x] = 1;
    if( map[y][x+1] == number && !maparea[y][x+1] )
        DFS( number, x+1, y );
    if( map[y][x-1] == number && !maparea[y][x-1] )
        DFS( number, x-1, y );
    if( map[y+1][x] == number && !maparea[y+1][x] )
        DFS( number, x, y+1 );
    if( map[y-1][x] == number && !maparea[y-1][x] )
        DFS( number, x, y-1 );
}

int main()
{
    int N;
    while( scanf( "%d", &N ) != EOF )
    {
        int H, W;
        int i;
        char s[1000] = {0};
        char maxdata = 0;
        for( i = 1 ; i <= N ; i++ )
        {
            scanf( "%d%d", &H, &W );
            int j, k;
            for( j = 1 ; j <= H ; j++ )
            {
                scanf( "%s", s );
                for( k = 0 ; k < W ; k++)
                {
                    map[j][k+1] = s[k];
                    maparea[j][k+1] = 0;
                    maxdata = ( s[k] > maxdata )? s[k] : maxdata;
                }
            }

            int ASCII[256] = {0}, maxarea = 0;
            for( j = 1 ; j <= H ; j++ )
                for( k = 1 ; k <= W ; k++ )
                    if( !maparea[j][k] )
                    {
                        DFS( map[j][k], k, j );
                        ASCII[map[j][k]]++;
                        maxarea = ( ASCII[map[j][k]] > maxarea )? ASCII[map[j][k]] : maxarea;
                    }
            printf( "World #%d\n", i );
            for( j = maxarea ; j >= 1 ; j-- )
                for( k = 0 ; k <= maxdata ; k++ )
                    if( j == ASCII[k] )
                        printf( "%c: %d\n", k, j );
        }
    }
    return 0;
}
