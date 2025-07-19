#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for ( int i = 0; i < n; i++ ){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int races = 0;
    for ( int i = 0; i < n; i++ ){
        if ( k <= arr[i] ){
            races++;
        }
    }

    cout << races;
}