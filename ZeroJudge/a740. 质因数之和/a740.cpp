#include <iostream>
using namespace std;

int factor( int n ){
    int sum_of_factor = 0;

    for ( int i = 2; i * i <= n; i++ ){
        while ( n % i == 0 ){
            sum_of_factor += i;
            n /= i;
        }
    }

    if ( n == 1 ){
        return sum_of_factor;
    }else{
        return sum_of_factor + n;
    }
}

int main(){
    int n;
    while ( cin >> n ){
        cout << factor(n) << endl;
    }
    
}