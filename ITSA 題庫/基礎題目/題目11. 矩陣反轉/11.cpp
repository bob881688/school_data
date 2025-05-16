#include <iostream>
using namespace std;

int main(){
    int r, c;

    while ( cin >> r >> c ){
        int **arr = new int*[r];
        for ( int i = 0; i < r; i++ ){
            arr[i] = new int[c];
        }

        for ( int i = 0; i < r; i++ ){
            for ( int j = 0; j < c; j++ ){
                cin >> arr[i][j];
            }
        }

        for ( int i = 0; i < c; i++ ){
            for ( int j = 0; j < r; j++ ){
                if ( j != r - 1 ){
                    cout << arr[j][i] << " ";
                }else{
                    cout << arr[j][i];
                }
            }

            cout << endl;
        }
    }
}