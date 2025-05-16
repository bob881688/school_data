#include <iostream>
using namespace std;

int main(){
    int n;
    int check = 0;

    while ( cin >> n ){
        for ( int i = 2; i < n - 1; i++ ){
            if ( n % i == 0 ){
                cout << "NO\n";
                check = 0;
                break;
            }else{
                check = 1;
            }
        }

        if ( check == 1 ){
            cout << "YES\n";
        }
    }
}