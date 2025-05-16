#include <stdio.h>
#include <stdlib.h>

int main(){
    char password[ 7 ];

    for ( int i = 0; i < 7; i++ ){
        scanf( "%c", &password[i] );
    }
    
    for ( int i = 0; i < 7 - 1; i++ ){
        if ( password[ i ] - password[ i + 1 ] > 0 ){
            printf( "%d", password[ i ] - password[ i + 1 ] );
        }else{
            printf( "%d", ( password[ i ] - password[ i + 1 ] ) * -1 );
        }
    }
}