#include <iostream>
using namespace std;

typedef struct robot{
    int x, y;
    int fuel;
} robot;

int main(){
    int m, n, e1, n1, e2, n2;
    robot robot_a, robot_b;
    cin >> m >> n >> robot_a.x >> robot_a.y >> e1 >> n1 >> robot_a.fuel >> robot_b.x >> robot_b.y >> e2 >> n2 >> robot_b.fuel;
    
    int **map = new int*[m];
    for ( int i = 0; i < m; i++ ){
        map[i] = new int[n];
    }

    


}