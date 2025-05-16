#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ){
        int d, a, b, c;
        cin >> d >> a >> b >> c;

        double time = (double)d / ( a + b );

        cout << fixed << setprecision(2) << c * time << endl;
    }
}