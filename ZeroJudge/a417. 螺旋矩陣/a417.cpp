#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool check( int row, int col, int n, const vector<vector<int>> &matrix ){
    if ( row < 0 || col < 0 || row > n - 1 || col > n - 1 ){
        return false;
    }

    if ( matrix[row][col] != -1 ){
        return false;
    }

    return true;
}

int main(){
    int t;
    cin >> t;

    for ( int i = 0; i < t; i++ ){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(n, -1));

        int count = 1;
        int row = 0, col = 0;
        matrix[row][col] = count;

        while ( count < n * n ){
            while ( check(row, col + 1, n, matrix) ){
                col++;
                count++;
                matrix[row][col] = count;
            }

            while ( check(row + 1, col, n, matrix) ){
                row++;
                count++;
                matrix[row][col] = count;
            }

            while ( check(row, col - 1, n, matrix) ){
                col--;
                count++;
                matrix[row][col] = count;
            }

            while ( check(row - 1, col, n, matrix) ){
                row--;
                count++;
                matrix[row][col] = count;
            }
        }

        if ( m == 2 ){
            for ( int j = 0; j < n; j++ ){
                for ( int k = j + 1; k < n; k++ ){
                    swap(matrix[j][k], matrix[k][j]);
                }
            }
        }

        for ( int j = 0; j < n; j++ ){
            for ( int k = 0; k < n; k++ ){
                cout << setw(5)<< matrix[j][k];
            }
            cout << endl;
        }

        cout << endl;
    }
}