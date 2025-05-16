#include <iostream>
using namespace std;

int main(){
    int cases;
    cin >> cases;

    for ( int i = 0; i < cases; i++ ){
        int code;
        cin >> code;

        int n = 0;
        while ( code > 0 ){
            n += code % 10;
            code /= 10;
        }

        int s = 0;
        for ( int j = 1; j <= n / 2; j++ ){
            if ( n % j == 0 ){
                s += j;
            }
        }

        if ( s > n ){
            cout << "-1";
        }else if ( s == n ){
            cout << "0";
        }else{
            cout << n - s;
        }
        cout << endl;
    }
}