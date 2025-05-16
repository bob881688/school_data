#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m;
    cin >> m;

    double x, y;
    for ( int i = 0; i < m; i++ ){
        cin >> x >> y;

        double distance = sqrt( (x - 10) * (x - 10) + (y - 10) * (y - 10) );

        if ( distance <= 1 ){
            cout << "10\n";
        }else if ( distance > 1 && distance <= 2 ){
            cout << "9\n";
        }else if ( distance > 2 && distance <= 3 ){
            cout << "8\n";
        }else if ( distance > 3 && distance <= 4 ){
            cout << "7\n";
        }else if ( distance > 4 && distance <= 5 ){
            cout << "6\n";
        }else if ( distance > 5 && distance <= 6 ){
            cout << "5\n";
        }else if ( distance > 6 && distance <= 7 ){
            cout << "4\n";
        }else if ( distance > 7 && distance <= 8 ){
            cout << "3\n";
        }else if ( distance > 8 && distance <= 9 ){
            cout << "2\n";
        }else if ( distance > 9 && distance <= 10 ){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
    
}