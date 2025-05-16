#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string line;
    int n;
    
    while ( getline(cin, str) ){
        if ( !(cin >> n) ){
            break;
        }
        cin.ignore();

        for ( int i = 0; i < str.length(); i++ ){
            if ( str[i] >= 'A' && str[i] <= 'Z' ){
                str[i] = ( str[i] - 'A' + n ) % 26 + 'A';
            }else if ( str[i] >= 'a' && str[i] <= 'z' ){
                str[i] = ( str[i] - 'a' + n ) % 26 + 'a';
            }else if ( str[i] >= '0' && str[i] <= '9' ){
                str[i] = ( str[i] - '0' + n ) % 10 + '0';
            }
        }

        cout << str << endl;
    }
}
