#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational{
    friend istream &operator>>( istream &, Rational& );
    friend ostream &operator<<( ostream &, Rational );

    public:
        int getnum();
        int getden();
        Rational(long long int = 0,long long int = 1 ); // default constructor
        Rational operator+( const Rational& operand2 ) const; // function addition
        Rational operator-( const Rational& operand2 ) const; // function subtraction
        Rational operator*( const Rational& operand2 ) const; // function multiplication
        Rational operator/( const Rational& operand2 ) const; // function division
        /*Rational& operator+=( const Rational& operand2 );  // function addition assignment
        Rational& operator-=( const Rational& operand2 ); // function subtraction assogment
        Rational& operator*=( const Rational& operand2 ); // function multiplication assignment
        Rational& operator/=( const Rational& operand2 ); // function division assignment
        bool operator==( const Rational& operand2 );
        bool operator!=( const Rational& operand2 );*/
        string toString() const;    // return a string to represent a Relational object in the form N/D = d, where d is a double value 

    private:
        long long int numerator; 
        long long int denominator;
        void gcd(); // gcd unction
}; // end class Rational

#endif