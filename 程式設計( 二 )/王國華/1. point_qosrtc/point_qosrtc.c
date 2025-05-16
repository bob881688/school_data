#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};

int cmp( const void *a, const void *b );

int main(){
    int n;
    int flag = 0;
    while ( scanf("%d", &n) != EOF ){
        if ( flag != 0 ){
            printf( "\n" );
        }else{
            flag = 1;
        }
        struct Point *point = (struct Point *)malloc(n * sizeof(struct Point));
        for ( int i = 0; i < n; i++ ){
            scanf( "%d %d", &point[i].x, &point[i].y );
        }

        qsort(point, n, sizeof(struct Point), cmp);

        for ( int i = 0; i < n; i++ ){
            printf( "(%d,%d)\n", point[i].x, point[i].y );
        }

        printf( "max num:%d\n", point[n-1].x + point[n-1].y );
        printf( "point:(%d,%d)\n", point[n-1].x, point[n-1].y );
        free(point);
    }
}

int cmp( const void *a, const void *b ){
    struct Point *p_a = (struct Point *)a;
    struct Point *p_b = (struct Point *)b;
    if ( p_a -> x  > p_b -> x ){
        return 1;
    }
    if ( p_a -> x  < p_b -> x ){
        return -1;
    }
    if ( p_a -> x == p_b -> x ){
        if ( p_a -> y > p_b -> y ){
            return 1;
        }else{
            return -1;
        }
    }
    return 0;
}