#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while ( cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 ){
        double mid_x, mid_y;
        if ( x1 == x3 && y1 == y3 ){
            mid_x = ( x2 + x4 ) / 2;
            mid_y = ( y2 + y4 ) / 2;

            cout << fixed << setprecision(3) << mid_x * 2 - x1 << " " << mid_y * 2 - y1 << endl;
        }else if ( x1 == x4 && y1 == y4 ){
            mid_x = ( x2 + x3 ) / 2;
            mid_y = ( y2 + y3 ) / 2;

            cout << fixed << setprecision(3) << mid_x * 2 - x1 << " " << mid_y * 2 - y1 << endl;
        }else if ( x2 == x3 && y2 == y3 ){
            mid_x = ( x1 + x4 ) / 2;
            mid_y = ( y1 + y4 ) / 2;

            cout << fixed << setprecision(3) << mid_x * 2 - x2 << " " << mid_y * 2 - y2 << endl;
        }else{
            mid_x = ( x1 + x3 ) / 2;
            mid_y = ( y1 + y3 ) / 2;

            cout << fixed << setprecision(3) << mid_x * 2 - x2 << " " << mid_y * 2 - y2 << endl;
        }
        
    }
}