#include <iostream>
using namespace std;

bool *Prime_array( int n );

int main(){
    int a, b;
    bool *arr = Prime_array(100000000);

    while ( cin >> a >> b ){

        int count = 0;
        for ( int i = a; i <= b; i++ ){
            if ( arr[i] ){
                count++;
            }
        }

        cout << count << endl;
    }
}

bool *Prime_array( int n ){
    bool *result = new bool[n + 1];

    for ( int i = 0; i < n + 1; i++ ){
        result[i] = true;
    }

    result[0] = false;
    result[1] = false;

    for ( int p = 2; p * p <= n + 1; p++ ){
        if ( result[p] ){
            for ( int index = p * p; index <= n + 1; index += p ){
                result[index] = false;
            }
        }
    }

    return result;
}