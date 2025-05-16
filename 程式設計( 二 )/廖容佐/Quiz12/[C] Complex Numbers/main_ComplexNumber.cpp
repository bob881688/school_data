#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main()
{
    RationalNumber real1(1, -3), real2(2, 4), imaginary1(-5, 6), imaginary2(-9, -4);
    ComplexNumber cplx1(real1, imaginary1), cplx2(real2, imaginary2);

    cout << "(" << cplx1 << ") + (" << cplx2 << ") = " << cplx1 + cplx2 << endl;
    cout << "(" << cplx1 << ") - (" << cplx2 << ") = " << cplx1 - cplx2 << endl;
    cout << "(" << cplx1 << ") * (" << cplx2 << ") = " << cplx1 * cplx2 << endl;
    cout << "(" << cplx1 << ") / (" << cplx2 << ") = " << cplx1 / cplx2 << endl;
    cout << endl;

    for ( unsigned int n = 1; n < 250; ++n )
    {
        cin >> cplx1;
        cin >> cplx2;

        cout << "(" << cplx1 << ") + (" << cplx2 << ") = " << cplx1 + cplx2 << endl;
        cout << "(" << cplx1 << ") - (" << cplx2 << ") = " << cplx1 - cplx2 << endl;
        cout << "(" << cplx1 << ") * (" << cplx2 << ") = " << cplx1 * cplx2 << endl;
        cout << "(" << cplx1 << ") / (" << cplx2 << ") = " << cplx1 / cplx2 << endl;
        cout << endl;
    }

    return 0;
}
