#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore();

    for ( int i = 0; i < s.length(); i++ ){
        if ( ( s[i] >= 'A' && s[i] <= 'Z' ) || ( s[i] >= 'a' && s[i] <= 'z' ) ){
            if ( ( s[i] + k > 'Z' && s[i] < 'a' ) || s[i] + k > 'z' ){
                s[i] -= 26;
            }

            s[i] += k;
        }
    }

    cout << s << endl;
}