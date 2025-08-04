#include <iostream>
#include <cmath>
using namespace std;

int digits( int number ){
    int result = 0;
    while ( number != 0 ){
        number /= 10;
        result++;
    }

    return result;
}

bool isArmstrongNumber( int number ){
    int total = 0;
    int n = digits(number);
    int origin = number;

    for ( int i = 0; i < n; i++ ){
        total += pow(number % 10, n);
        number /= 10;
    }

    if ( total == origin ){
        return true;
    }else{
        return false;
    }
}

int main(){
    int a, b;
    cin >> a >> b;

    int flag = 0;
    bool hasFound = false;
    for ( int i = a; i <= b; i++ ){
        if ( isArmstrongNumber(i) ){
            if ( flag == 0 ){
                cout << i;
                flag = 1;
            }else{
                cout << " " << i;
            }

            hasFound = true;
        }
    }

    if ( !hasFound ){
        cout << "none";
    }
}