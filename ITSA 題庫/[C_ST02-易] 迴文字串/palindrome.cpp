#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string str;
    for ( int i = 0; i < n; i++ ){
        cin >> str;
        for ( int j = str.length() - 1; j >= 0; j-- ){
            cout << str[j];
        }

        cout << endl;
    }
}