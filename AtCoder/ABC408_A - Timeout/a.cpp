#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;

    vector<int> taps(n + 1);
    taps.push_back(0);
    for ( int i = 0; i < n; i++ ){
        cin >> taps[i + 1];
    }

    int check = 0;
    for ( int i = 1; i < n + 1; i++ ){
        if ( taps[i] - taps[i - 1] > s + 0.5 ){
            cout << "No";
            check = 1;
            break;
        }
    }

    if ( check == 0 ){
        cout << "Yes";
    }
}