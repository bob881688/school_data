#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    while( 1 ){
        char arr[ 40 ];
        char ans[ 20 ];
        fgets( arr, 40, stdin );

        int count = 0;
        for ( int i = 0; i < 40; i++ ){
            if ( arr[ i ] != ' ' ){
                if ( arr[ i ] == '-' ){
                    ans[ count ] = '-';
                    ans[ count + 1 ] = arr[ i + 1 ];
                    count += 2;
                }else{
                    ans[ count ] = arr[ i ];
                    count ++;
                }
            }
        }
        int str_size = strlen( ans ) - 1;

        printf( "Pass 0: " );
        for ( int i = 0; i < str_size; i++ ){
            printf( "%c ", ans[ i ] );
        }
        printf( "/" );
        printf( "\n" );

        for ( int i = 0; i < str_size - 1; i++ ){
            int check = 0;
            for ( int j = 0; j < str_size - i - 1; j++ ){
                if( ans[ j ] > ans[ j + 1 ] ){
                    char tmp;
                    tmp = ans[ j ];
                    ans[ j ] = ans[ j + 1 ];
                    ans[ j + 1 ] = tmp;
                    check = 1;
                }
            }

            if( check == 0 ){
                break;
            }else{
                check = 0;
            }

            printf( "Pass %d: ", i + 1 );
            for( int k = 0; k < str_size; k++ ){
                if( k == str_size - i - 1 ){
                    printf( "/ %c ", ans[ k ] );
                }else{
                    printf( "%c ", ans[ k ] );
                } 
            }
            printf( "\n" );
        }
    }
}