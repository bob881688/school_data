#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a, b, c, d;
    
    for ( int i = 0; i < n; i++ ){
        cin >> a >> b >> c >> d;

        int delta = c - d;
        int delta_x = a - b * d;
        int delta_y = b * c - a;

        cout << delta_x / delta << " " << delta_y / delta << endl;
    }

}