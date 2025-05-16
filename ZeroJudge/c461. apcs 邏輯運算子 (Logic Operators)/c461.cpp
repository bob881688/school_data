#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if ( a == 0 && b == 0 ){
        if ( c == 0 ){
            cout << "AND\nOR\nXOR\n";
        }else{
            cout << "IMPOSSIBLE\n";
        }
    }

    if ( a != 0 && b == 0 ){
        if ( c == 0 ){
            cout << "AND\n";
        }else{
            cout << "OR\nXOR\n";
        }
    }

    if ( a == 0 && b != 0 ){
        if ( c == 0 ){
            cout << "AND\n";
        }else{
            cout << "OR\nXOR\n";
        }
    }

    if ( a != 0 && b != 0 ){
        if ( c == 0 ){
            cout << "XOR\n";
        }else{
            cout << "AND\nOR\n";
        }
    }
}