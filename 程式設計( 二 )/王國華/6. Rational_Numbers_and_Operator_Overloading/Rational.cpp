#include "Rational.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <numeric>
using namespace std;

int Rational::getnum(){
    return numerator;
}
int Rational::getden(){
    return denominator;
}

istream &operator>>( istream &input, Rational& r ){
    string str;
    input >> str;

    int now = 1;
    int pos = str.find('/', now);
    r.numerator = stol(str.substr(now, now - pos));
    now = pos + 1;
    pos = str.find(')', now);
    r.denominator = stol(str.substr(now, now - pos));

    r.gcd();
    return input;
}

ostream &operator<<( ostream &output, Rational r ){
    output << r.numerator << "/" << r.denominator;
    return output;
}

Rational::Rational(long long int numer, long long int denom ){
    numerator = numer;
    denominator = denom;
    gcd();
}
Rational Rational::operator+( const Rational& operand2) const{
    long long int numer_ans = this->numerator * operand2.denominator + operand2.numerator * this->denominator;
    long long int denom_ans = this->denominator * operand2.denominator;
    return Rational(numer_ans, denom_ans); 
}
Rational Rational::operator-( const Rational& operand2 ) const{
    long long int numer_ans = this->numerator * operand2.denominator - operand2.numerator * this->denominator;
    long long int denom_ans = this->denominator * operand2.denominator;
    return Rational(numer_ans, denom_ans);
}
Rational Rational::operator*( const Rational& operand2 ) const{
    long long int numer_ans = this->numerator * operand2.numerator;
    long long int denom_ans = this->denominator * operand2.denominator;
    return Rational(numer_ans, denom_ans);
}
Rational Rational::operator/( const Rational& operand2 ) const{
    long long int numer_ans = this->numerator * operand2.denominator;
    long long int denom_ans = this->denominator * operand2.numerator;
    return Rational(numer_ans, denom_ans);
}
/*Rational& Rational::operator+=( const Rational& operand2 ){

}
Rational& Rational::operator-=( const Rational& operand2 ){

}
Rational& Rational::operator*=( const Rational& operand2 ){

}
Rational& Rational::operator/=( const Rational& operand2 ){

}
bool Rational::operator==(const Rational& operand2 ){

}
bool Rational::operator!=(const Rational& operand2 ){

}*/
string Rational::toString() const{
    return to_string((double)this->numerator / (double)this->denominator);
}

void Rational::gcd(){
    int divisor = std::gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}