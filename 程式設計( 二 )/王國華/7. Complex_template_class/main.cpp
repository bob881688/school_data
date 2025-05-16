#include <iostream>
#include "MyComplex.h"
using namespace std;

int main(){
    double r1, i1, r2, i2;
    cin >> r1 >> i1 >> r2 >> i2;
    MyComplex<double> c1(r1, i1), c2(r2, i2);

    MyComplex<double> sum = c1 + c2 + c1;
    cout << "c1 + c2 = ";
    sum.display();

    MyComplex<double> sub = c1 - c2;
    cout << "c1 - c2 = ";
    sub.display();
    MyComplex<double> mul = c1 * c2;
    cout << "c1 * c2 = ";
    mul.display();
    MyComplex<double> div = c1 / c2;
    cout << "c1 / c2 = ";
    div.display();

    MyComplex<double> c3 = c1;
    cout << "c3 (after assignment) = ";
    c3.display();

    c3 += c2;
    cout << "c3 += c2 = ";
    c3.display();

    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;

    cout << "Magnitude of c1: " << c1.magnitude() << endl;
    cout << "Phase of c1: " << c1.phase() << endl;

    MyComplex<double> conj_c1 = c1.conjugate();
    cout << "Conjugate of c1: ";
     conj_c1.display();
}