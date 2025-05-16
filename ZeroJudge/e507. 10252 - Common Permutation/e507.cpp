#include <iostream>
using namespace std;

int main(){
    string a, b;
    int check_a[26][2];
    int check_b[26][2];

    while ( cin >> a >> b ){
        for ( int i = 0; i < 26; i++ ){
            check_a[i][0] = 'a' + i;
            check_a[i][1] = 0;

            check_b[i][0] = 'a' + i;
            check_b[i][1] = 0;
        }

        for ( int i = 0; i < a.length(); i++ ){
            check_a[a[i] - 'a'][1]++;
        }
        for ( int i = 0; i < b.length(); i++ ){
                check_b[b[i] - 'a'][1]++;
        }

        for ( int i = 0; i < 26; i++ ){
            if ( check_a[i][1] > check_b[i][1] ){
                for ( int j = 0; j < check_b[i][1]; j++ ){
                    cout << (char)check_b[i][0];
                }

            }else if ( check_a[i][1] < check_b[i][1] ){
                for ( int j = 0; j < check_a[i][1]; j++ ){
                    cout << (char)check_a[i][0];
                }

            }else if ( check_a[i][1] == check_b[i][1] && check_a[i][1] != 0 && check_b[i][1] != 0 ){
                for ( int j = 0; j < check_a[i][1]; j++ ){
                    cout << (char)check_a[i][0];
                }
            }
        }

        cout << endl;
    }
}