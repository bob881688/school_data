#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;

    double fastest = 10000;
    for ( int i = 0; i < n; i++ ){
        int m, k;
        cin >> m >> k;

        if ( m / k < fastest ){
            fastest = m / k;
        }
    }

    cout << fixed << setprecision(1) << fastest / 60 << endl;
}