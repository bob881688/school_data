#include <iostream>
using namespace std;

int convert( string s );
int gcd( int a, int b );

int main(){
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ){
        string s1, s2;
        cin >> s1 >> s2;

        int t1 = convert(s1);
        int t2 = convert(s2);

        if ( gcd(t1, t2) != 1 ){
            cout << "Pair #" << i + 1 << ": All you need is love!\n";
        }else{
            cout << "Pair #" << i + 1 << ": Love is not all you need!\n";
        }
    }
}

int convert( string s ){
    int decimal = 0;
    int n = 1; // ...8 4 2 1

    for ( int i = s.length() - 1; i >= 0; i-- ){
        decimal += ( s[i] - '0' ) * n;
        n *= 2;
    }

    return decimal;
}

int gcd( int a, int b ){
    if ( b == 0 ){
        return a;
    }else{
        return gcd(b, a % b);
    }
}