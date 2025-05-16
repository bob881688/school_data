#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <iostream>
using namespace std;

class HugeInt{

    friend istream &operator>>( istream &, HugeInt & );
    friend ostream &operator<<( ostream &, HugeInt );

    public:

        HugeInt();
        HugeInt( const string & );

        HugeInt operator+( const HugeInt & ) const;
        HugeInt operator-( const HugeInt & ) const;
        HugeInt operator*( const HugeInt & ) const;
        HugeInt operator/( const HugeInt & ) const;
        HugeInt operator%( const HugeInt & ) const;

        bool operator<( const HugeInt & ) const;
        bool operator>( const HugeInt & ) const;
        bool operator==( const HugeInt & ) const;
        bool operator!=( const HugeInt & ) const;
        bool operator>=( const HugeInt & ) const;

        void Print();
        void convert( string );
        void shiftLeft( int );

    private:
        short number[40] = {0};
        bool isNeg = false;
};

#endif