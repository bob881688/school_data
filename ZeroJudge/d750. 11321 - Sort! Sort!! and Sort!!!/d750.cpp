#include <iostream>
#include <algorithm>
using namespace std;

bool cmp( int a, int b );
int m;

int main(){
    int n;

    while ( cin >> n >> m ){
        cout << n << " " << m << endl;
        if ( n == 0 && m == 0 ){
            break;
        }

        int *arr = new int[n];
        for ( int i = 0; i < n; i++ ){
            cin >> arr[i];
        }

        sort( arr, arr + n, cmp );
    
        for ( int i = 0; i < n; i++ ){
            cout << arr[i] << endl;
        }
    }
}

bool cmp( int a, int b ){
    if ( a % m < b % m ){
        return true;
    }else if ( ( a % 2 == 1 && b % 2 == 0 ) && ( a % m == b % m ) ){
        return true;
    }else if ( ( a % 2 == 1 && b % 2 == 1 ) && ( a % m == b % m ) ){
        if ( a > b ){
            return true;
        }else{
            return false;
        }
    }else if ( ( a % 2 == 0 && b % 2 == 0 ) && ( a % m == b % m ) ){
        if ( a < b ){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}