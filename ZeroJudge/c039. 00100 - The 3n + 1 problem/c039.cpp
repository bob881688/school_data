#include <iostream>
using namespace std;

int recursive( int n, int count ){
    if ( n == 1 ){
        count++;
        return count;
    }

    if ( n % 2 == 1 ){
        count++;
        return recursive( 3 * n + 1, count );
    }

    if ( n % 2 == 0 ){
        count++;
        return recursive( n / 2, count );
    }

    return 0;
}

int main(){
    int i, j;
    
    while ( cin >> i >> j ){
        cout << i << " " << j << " ";

        if ( i > j ){
            swap(i, j);
        }
        
        int max = 0;
        for ( int k = i; k <= j; k++ ){
            int calculate = recursive(k, 0);
            if ( calculate > max ){
                max = calculate;
            }
        }

        cout << max << endl;
    }
}