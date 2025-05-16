#include <iostream>
using namespace std;

int main(){
    string number;

    while ( cin >> number ){
        int check = 0;
        for ( int i = 0; i < number.length() / 2; i++ ){
            if ( number[i] != number[number.length() - 1 - i ] ){
                cout << "NO\n";
                check = 1;
                break;
            }
        }

        if ( check == 0 ){
            cout << "YES\n";
        }
    }
}