#include <iostream>
#include <algorithm>
using namespace std;

class Rational{
    friend istream& operator>>( istream& input, Rational &r ){
        input >> r.numer >> r.denom;

        return input;
    }

    friend ostream& operator<<( ostream& output, Rational r ){
        if ( r.numer == 0 ){
            output << "0";
        }else if ( r.numer % r.denom == 0 ){
            output << r.numer / r.denom;
        }else{
            output << r.numer << "/" << r.denom;
        }

        return output;
    }

    public:
        Rational(){};
        Rational( int n, int d ){
            numer = n;
            denom = d;
            gcd();
        }

        Rational operator+( const Rational &other ) const{
            int n = numer * other.denom + other.numer * denom;
            int d = denom * other.denom;

            return Rational(n, d);
        }
        Rational operator-( const Rational &other ) const{
            int n = numer * other.denom - other.numer * denom;
            int d = denom * other.denom;

            return Rational(n, d);
        }
        Rational operator*( const Rational &other ) const{
            int n = numer * other.numer;
            int d = denom * other.denom;

            return Rational(n, d);
        }
        Rational operator/( const Rational &other ) const{
            int n = numer * other.denom;
            int d = denom * other.numer;

            return Rational(n, d);
        }

    private:
        int numer;
        int denom;
        void gcd(){
            int divisior = __gcd(numer, denom);
            
            numer /= divisior;
            denom /= divisior;

            if ( denom < 0 ){
                numer *= -1;
                denom *= -1;
            }
        }

};

int main(){
    Rational a, b;
    char op;

    while ( cin >> a >> b ){
        cin >> op;

        switch (op){
            case '+':
                cout << a + b << endl;
                break;

            case '-':
                cout << a - b << endl;
                break;

            case '*':
                cout << a * b << endl;
                break;

            case '/':
                cout << a / b << endl;
                break;
        }
    }
}