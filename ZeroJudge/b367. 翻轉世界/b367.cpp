#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    for ( int i = 0; i < t; i++ ){
        int n, m;
        cin >> n >> m;

        int *r = new int[n * m];
        for ( int j = 0; j < n * m; j++ ){
            cin >> r[j];
        }

        int flag = 0;
        for ( int j = 0; j < n * m / 2; j++ ){
            if ( r[j] != r[n * m - j - 1] ){
                cout << "keep defending" << endl;
                flag = 1;
                break;
            }
        }

        if ( flag == 0 ){
            cout << "go forward" << endl;
        }
    }
}