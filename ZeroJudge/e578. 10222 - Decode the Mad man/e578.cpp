#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string table = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    
    while ( getline(cin, str) ){
        for ( int i = 0; i < str.length(); i++ ){
            for ( int j = 0; j < 48; j++ ){
                if ( str[i] == ' ' ){
                    cout << " ";
                    break;
                }else if ( str[i] == table[j] ){
                    cout << table[j - 2];
                    break;
                }
            }
        }

        cout << endl;
    }
}