#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Rectangle{
    int length;
    int width;
    int area;
    double diagonal;
}Rectangle;

int cmp( const void *a, const void *b );

int main(){
    int n;
    scanf( "%d", &n );
    Rectangle *rectangle = (Rectangle *)malloc(n * sizeof(Rectangle));
    for ( int i = 0; i < n; i++ ){
        scanf( "%d %d", &rectangle[i].length, &rectangle[i].width );
        rectangle[i].area = rectangle[i].length * rectangle[i].width;
        rectangle[i].diagonal = sqrt(rectangle[i].length * rectangle[i].length + rectangle[i].width * rectangle[i].width);
    }

    qsort(rectangle, n, sizeof(Rectangle), cmp);

    for ( int i = 0; i < n; i++ ){
        printf( "%d:(%d,%d) area= %d diagonal= %.3lf\n", i + 1, rectangle[i].length, rectangle[i].width, rectangle[i].area, rectangle[i].diagonal );
    }

    free(rectangle);
}

int cmp( const void *a, const void *b ){
    Rectangle *ra = (Rectangle *)a;
    Rectangle *rb = (Rectangle *)b;
    if ( ra->area < rb->area ){
        return -1;
    }
    if ( ra->area > rb->area ){
        return 1;
    }
    if ( ra->diagonal > rb->diagonal ){
        return -1;
    }
    if ( ra->diagonal < rb->diagonal ){
        return 1;
    }
    return 0;
}