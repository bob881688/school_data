#include <iostream>
using namespace std;

int mul( int n );

int main(){
    int t;
    cin >> t;

    for ( int i = 0; i < t; i++ ){
        int n;
        cin >> n;

        cout << mul(n) << endl;
    }
}

int mul( int number ){
    int result = 1;

    if ( number == 0 ){
        result = 0;
    }

    while ( number > 0 ){
        result *= number % 10;
        number /= 10; 
    }

    return result;
}