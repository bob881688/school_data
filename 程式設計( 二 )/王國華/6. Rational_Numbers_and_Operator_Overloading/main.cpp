#include "Rational.h"
#include "Rational.cpp"
#include <iostream>

int main(){
    Rational a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout <<  a + b << " = " <<  (a + b).toString() << endl;

    cout << endl;

    cout << a << " - " << b << " = " << a - b << endl;
    cout <<  a - b << " = " <<  (a - b).toString() << endl;

    cout << endl;

    cout << a << " x " << b << " = " << a * b << endl;
    cout <<  a * b << " = " <<  (a * b).toString() << endl;

    cout << endl;

    cout << a << " / " << b << " = " << a / b << endl;
    cout <<  a / b << " = " <<  (a / b).toString() << endl;
}