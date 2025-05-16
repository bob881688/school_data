#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ){
        int k;
        cin >> k;
        int *s = new int[k];
        vector<int> permutation;
        for ( int i = 0; i < k; i++ ){
            cin >> s[i];
            permutation.push_back(i + 1);
        }

        for ( int i = 0; i < k; i++ ){
            cout << permutation[s[i]];
            if ( i != k - 1 ){
                cout << " ";
            }

            permutation.erase( permutation.begin() + s[i] );
        }

        cout << endl;

        for ( int i = 0; i < k; i++ ){
            cin >> s[i];
            permutation.push_back(i + 1);
        }

        for ( int i = 0; i < k; i++ ){
            for ( int j = 0; j < k - i; j++ ){
                if ( permutation[j] == s[i] ){
                    cout << j;
                    permutation.erase( permutation.begin() + j );
                }
            }
            if ( i != k - 1 ){
                cout << " ";
            }
        }
        

        cout << endl;
        delete[] s;
    }
}