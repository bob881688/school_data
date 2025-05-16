#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int delta = a * e - b * d;
    int delta_x = c * e - b * f;
    int delta_y = a * f - c * d;

    if ( delta == 0 ){
        if ( delta_x == 0 && delta_y == 0 ){
            cout << "Too many\n";
        }else{
            cout << "No answer\n";
        }
    }else{
        cout << fixed << setprecision(2);
        cout << "x=" << (double)delta_x / delta << endl;
        cout << "y=" << (double)delta_y / delta << endl;
    }
}