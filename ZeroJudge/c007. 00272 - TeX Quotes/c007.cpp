#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;

    int is_odd = 1;
    while ( getline(cin, str) ){
        for ( int i = 0; i < str.length(); i++ ){
            if ( str[i] == '"'){
                if ( is_odd % 2 == 1 ){
                    cout << "``";
                }else{
                    cout << "''";
                }

                is_odd++;

            }else{
                cout << str[i];
            }
        }

        cout << endl;
    }
}