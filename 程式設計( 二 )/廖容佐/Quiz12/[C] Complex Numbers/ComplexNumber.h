#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include "RationalNumber.h"

class ComplexNumber {
private:
    RationalNumber real;
    RationalNumber imaginary;

public:
    // Constructor with default values
    ComplexNumber(RationalNumber r = RationalNumber(0, 1), RationalNumber i = RationalNumber(0, 1))
        : real(r), imaginary(i) {}

    // Overloaded stream extraction operator
    friend std::istream& operator>>(std::istream& in, ComplexNumber& c);

    // Overloaded stream insertion operator
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& c);

    // Overloaded addition operator
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // Overloaded subtraction operator
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    // Overloaded multiplication operator
    ComplexNumber operator*(const ComplexNumber& other) const {
        RationalNumber realPart = real * other.real - imaginary * other.imaginary;
        RationalNumber imaginaryPart = real * other.imaginary + imaginary * other.real;
        return ComplexNumber(realPart, imaginaryPart);
    }

    // Overloaded division operator
    ComplexNumber operator/(const ComplexNumber& other) const {
        RationalNumber denominator = other.real * other.real + other.imaginary * other.imaginary;
        RationalNumber realPart = (real * other.real + imaginary * other.imaginary) / denominator;
        RationalNumber imaginaryPart = (imaginary * other.real - real * other.imaginary) / denominator;
        return ComplexNumber(realPart, imaginaryPart);
    }
};

// Overloaded stream extraction operator for ComplexNumber
std::istream& operator>>(std::istream& in, ComplexNumber& c) {
    char ch;
    in >> ch >> c.real >> ch >> c.imaginary >> ch;
    return in;
}

// Overloaded stream insertion operator for ComplexNumber
std::ostream& operator<<(std::ostream& out, const ComplexNumber& c) {
    if (c.imaginary.getNumerator() == 0) {
        out << c.real;
    } else if (c.real.getNumerator() == 0) {
        out << c.imaginary << "i";
    } else {
        out << c.real;
        if (c.imaginary.getNumerator() < 0) {
            out << " - " << RationalNumber(-c.imaginary.getNumerator(), c.imaginary.getDenominator()) << "i";
        } else {
            out << " + " << c.imaginary << "i";
        }
    }
    return out;
}

#endif // COMPLEXNUMBER_H