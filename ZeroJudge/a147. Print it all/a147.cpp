#include <iostream>
using namespace std;

int main(){
    int n;

    while ( cin >> n && n != 0 ){
        for ( int i = 0; i < n; i++ ){
            if ( i % 7 != 0 ){
                cout << i << " ";
            }
        }

        cout << endl;
    }
}