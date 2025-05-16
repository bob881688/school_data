#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <iostream>
using namespace std;

template<typename T>
class MyComplex{
    public:
        MyComplex( T = 0, T = 0 );

        T getreal();
        T getimag();

        MyComplex operator+( const MyComplex &other ) const;
        MyComplex operator-( const MyComplex &other ) const;
        MyComplex operator*( const MyComplex &other ) const;
        MyComplex<T> operator/( const MyComplex &other ) const;
        MyComplex& operator=(const MyComplex& other);

        MyComplex operator+=( const MyComplex &other );

        bool operator==( const MyComplex &other ) const;
        bool operator!=( const MyComplex &other ) const;

        T magnitude() const;
        T phase() const;
        MyComplex conjugate() const;

        void display();

    private:
        T real;
        T imag;
};

#endif