#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> s;
    int input;
    for ( int i = 0; i < n; i++ ){
        cin >> input;
        s.push_back(input);
    }

    int r, c;
    cin >> r >> c;

    vector<vector<int>> storage;

    for ( int i = 0; i < r; i++ ){
        vector<int> temp;

        for ( int j = 0; j < c; j++ ){
            cin >> input;
            temp.push_back(input);
        }

        storage.push_back(temp);
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
}