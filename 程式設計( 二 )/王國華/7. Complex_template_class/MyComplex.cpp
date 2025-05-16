#include <iostream>
#include <cmath>
#include "MyComplex.h"
using namespace std;

template<typename T>
MyComplex<T>::MyComplex( T real, T imag ){
    this->real = real;
    this->imag = imag;
}

template<typename T>
T MyComplex<T>::getreal(){
    return real;
}
template<typename T>
T MyComplex<T>::getimag(){
    return imag;
}
template<typename T>
MyComplex<T> MyComplex<T>::operator+( const MyComplex &other ) const {
    return MyComplex( real + other.real, imag + other.imag );
}
template<typename T>
MyComplex<T> MyComplex<T>::operator-( const MyComplex &other ) const {
    return MyComplex( real - other.real, imag - other.imag );
}
template<typename T>
MyComplex<T> MyComplex<T>::operator*( const MyComplex &other ) const {
    T r = this->real * other.real - this->imag * other.imag;
    T i = this->imag * other.real + this->real * other.imag;
    return MyComplex( r, i );
}
template<typename T>
MyComplex<T> MyComplex<T>::operator/( const MyComplex &other ) const {
    T denom = other.real * other.real + other.imag * other.imag;
    T real_numer = this->real * other.real + this->imag * other.imag;
    T imag_numer = this->imag * other.real - this->real * other.imag;
    return MyComplex( real_numer / denom, imag_numer / denom );
}
template<typename T>
MyComplex<T>& MyComplex<T>::operator=(const MyComplex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}
template<typename T>
MyComplex<T> MyComplex<T>::operator+=( const MyComplex &other ){
    real += other.real;
    imag += other.imag;
    return *this;
}
template<typename T>
bool MyComplex<T>::operator==( const MyComplex &other ) const{
    return (this->real == other.real && this->imag == other.imag);
}
template<typename T>
bool MyComplex<T>::operator!=( const MyComplex &other ) const{
    return (this->real != other.real || this->imag != other.imag);
}

template<typename T>
T MyComplex<T>::magnitude() const{
    return sqrt(real * real + imag * imag);
}
template<typename T>
T MyComplex<T>::phase() const{
    return atan2(imag, real);
}
template<typename T>
MyComplex<T> MyComplex<T>::conjugate() const{
    return MyComplex(real, -imag);
}

template<typename T>
void MyComplex<T>::display(){
    cout << real;
    if ( imag >= 0 ){
        cout << " + " << imag << "i" << endl;
    }else{
        cout << " - " << -imag << "i" << endl;
    }
}

template class MyComplex<int>;
template class MyComplex<double>;