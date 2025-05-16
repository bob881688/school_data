#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Point{
    int x;
    int y;
} Point;

bool cmp( Point a, Point b );


int main(){
    int n;
    cin >> n;

    Point *point = new Point[n];
    for ( int i = 0; i < n; i++ ){
        cin >> point[i].x >> point[i].y;
    }

    sort(point, point + n, cmp);

    for ( int i = 0; i < n; i++ ){
        cout << point[i].x << " " << point[i].y << endl;
    }
}

bool cmp( Point a, Point b ){
    if ( a.x != b.x ){
        return a.x < b.x;
    }

    if ( a.y != b.y ){
        return a.y < b.y;
    }

    return 1;
}