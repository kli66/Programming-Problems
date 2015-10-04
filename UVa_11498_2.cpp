#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int TC, x, y, search_x, search_y;
  while( scanf( "%d", &TC ) != EOF && TC ){
    scanf( "%d%d", &x, &y );
    for( int i = 0 ; i < TC ; i++ ){
      scanf( "%d%d", &search_x, &search_y );
      if( x == search_x || y == search_y ) printf( "divisa\n" );
      else{
        if( y > search_y ) printf( "S" );
        else printf( "N" );
        if( x > search_x ) printf( "O" );
        else printf( "E" );
        printf( "\n" );
      }
    }
  }
  return 0;
}
