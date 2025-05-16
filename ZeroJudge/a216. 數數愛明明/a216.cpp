#include <iostream>
using namespace std;

long long int f( int n );
long long int g( int n );

int main(){
    int n;

    while ( cin >> n ){
        cout << f(n) << " " << g(n) << endl;
    }
}

long long int f( int n ){
    if ( n == 1 ){
        return 1;
    }

    return n + f(n - 1);
}

long long int g( int n ){
    if ( n == 1 ){
        return 1;
    }

    return f(n) + g(n - 1);
}