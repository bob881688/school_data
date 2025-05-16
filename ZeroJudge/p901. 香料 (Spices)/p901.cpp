#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int *s = new int[n];
    for ( int i = 0; i < n; i++ ){
        cin >> s[i];
    }

    int r, c;
    cin >> r >> c;

    int **storage = new int*[r];
    for ( int i = 0; i < r; i++ ){
        storage[i] = new int[c];
    }

    for ( int i = 0; i < r; i++ ){
        for ( int j = 0; j < c; j++ ){
            cin >> storage[i][j];
        }
    }

    for ( int i = 0; i < n; i++ ){
        int flag = 0;

        for ( int row = 0; row < r; row++ ){
            for ( int col = 0; col < c; col ++ ){
                if ( storage[row][col] == s[i] ){
                    cout << row + 1 <<  " " << col + 1 << endl;
                    flag = 1;
                    break;
                }
            }

            if ( flag == 1 ){
                break;
            }
        }

        if ( flag == 0 ){
            cout << "-1" << endl;
        } 
    }

    for ( int i = 0; i < r; i++ ){
        delete[] storage[i];
    }
    delete[] storage;

    delete[] s;
}