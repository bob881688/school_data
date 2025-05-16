#include <iostream>
using namespace std;

int main(){
    int n;
    int flag = 0;
    while ( cin >> n ){
        if ( flag != 0 ){
            cout << endl;
        }else{
            flag = 1;
        }
        if ( n % 2 == 0 ){
            cout << "It is not an odd number." << endl;
        }else{
            int **square = new int*[n];
            for ( int i = 0; i < n; i++ ){
                square[i] = new int[n];
            }

            int row = n - 1, col = n / 2;
            for ( int num = 1; num <= n * n; num++ ){
                if ( row >= n ){
                    row = 0;
                }
                if ( col >= n ){
                    col = 0;
                }
                if ( row < 0 ){
                    row = n - 1;
                }
                if ( col < 0 ){
                    col = n - 1;
                }

                square[row][col] = num;
                if ( num % n == 0 ){
                    row --;
                }else{
                    row++;
                    col++;
                }
            }

            cout << square[n / 2][n / 2] * n << endl;
            for ( int i = 0; i < n; i++ ){
                for ( int j = 0; j < n; j++ ){
                    if ( j == n - 1 ){
                        cout << square[i][j];
                    }else{
                        cout << square[i][j] << " ";
                    }
                }
                cout << endl;
            }
            for ( int i = 0; i < n; i++ ){
                delete[] square[i];
            }
            delete square;
        }
    }
}