#include <iostream>
#include "HugeInteger.h"
#include "HugeInteger.cpp"
using namespace std;

int main(){
    HugeInt a, b;
    int flag = 0;
    
    while ( cin >> a >> b ){
        if ( flag != 0 ){
            cout << endl << endl;
        }else{
            flag = 1;
        }

        if ( a > b ){
            cout << a << " > " << b << endl;
        }else if ( a == b ){
            cout << a << " = " << b << endl;
        }else{
            cout << a << " < " << b << endl;
        }

        cout << a << " + " <<  b << " = " <<  a + b << endl;
        cout << a << " - " <<  b << " = " <<  a - b << endl;
        cout << a << " * " <<  b << " = " <<  a * b << endl;
        cout << a << " / " <<  b << " = " <<  a / b << endl;
        cout << a << " % " <<  b << " = " <<  a % b;
    }
}