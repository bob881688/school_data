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
            if ( i == k - 1 ){
                cout << permutation[s[i]];
            }else{
                cout << permutation[s[i]] << " ";
            }
            permutation.erase( permutation.begin() + s[i] );
        }
        cout << endl;
        delete[] s;
    }
}