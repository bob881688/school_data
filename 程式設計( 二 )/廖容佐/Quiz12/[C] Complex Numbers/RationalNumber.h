#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
#include <stdexcept>
#include <cmath>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class RationalNumber {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcdValue = gcd(abs(numerator), abs(denominator));
        numerator /= gcdValue;
        denominator /= gcdValue;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    RationalNumber(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    friend std::istream& operator>>(std::istream& in, RationalNumber& r);
    friend std::ostream& operator<<(std::ostream& out, const RationalNumber& r);

    RationalNumber operator+(const RationalNumber& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return RationalNumber(newNumerator, newDenominator);
    }

    RationalNumber operator-(const RationalNumber& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return RationalNumber(newNumerator, newDenominator);
    }

    RationalNumber operator*(const RationalNumber& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return RationalNumber(newNumerator, newDenominator);
    }

    RationalNumber operator/(const RationalNumber& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return RationalNumber(newNumerator, newDenominator);
    }
};

std::istream& operator>>(std::istream& in, RationalNumber& r) {
    int num, denom;
    char slash;
    in >> num >> slash >> denom;
    if (slash != '/') {
        in.setstate(std::ios::failbit);
    } else {
        r = RationalNumber(num, denom);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const RationalNumber& r) {
    if (r.denominator == 1) {
        out << r.numerator;
    } else {
        out << r.numerator << "/" << r.denominator;
    }
    return out;
}

#endif // RATIONALNUMBER_H