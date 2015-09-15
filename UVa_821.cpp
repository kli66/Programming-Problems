//using Floyd Warshall
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

long adj_mat [100][100];

int main(){
 int a , b , i , j , x, y  ,largest ; int kase = 0;
  while ( scanf("%d %d",&a,&b)) {
        if ( a == 0 && b == 0)
            break ;
        largest = 0 ;
         if ( a > largest || b > largest )
             largest = max ( a , b) ;
         for ( i = 0 ; i < 100 ; i++)
             for ( j = 0 ; j < 100 ; j++)
             adj_mat [i] [j] = 100000;

         adj_mat [a-1][b-1] = 1;

         while ( scanf("%d %d",&x,&y) ){
               if ( x == 0 && y == 0)
               break ;

               adj_mat [x-1][y-1] = 1 ;

               if ( x > largest || y > largest )
                   largest = max( x , y) ;
         }

         // FLOYD WARSHALL
         for ( int k = 0 ; k < largest ; k++)
             for ( i = 0 ; i < largest ; i++)
             for ( j = 0 ; j < largest ; j++ )
                 adj_mat [i][j] = min ( adj_mat [i][j] , adj_mat [i][k] + adj_mat [k][j]) ;

             float ans = 0 ; int paths = 0;
             for ( i = 0 ; i < largest ; i++)
             for ( j = 0 ; j < largest ; j++)
                 if ( i != j  && adj_mat[i][j] < 100000)
                 ans += adj_mat [i][j] , paths++;

             printf( "Case %d: average length between pages = %0.3f clicks\n", ++kase , ans/paths );
  }
  return 0;

}
