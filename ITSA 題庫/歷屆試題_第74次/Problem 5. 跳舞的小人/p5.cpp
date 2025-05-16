#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int m;
    cin >> m;
    cin.ignore();

    int flag = 0;
    string input;
    for ( int i = 0; i < m; i++ ){
        if ( flag != 0 ){
            cout << endl;
        }else{
            flag = 1;
        }

        getline(cin, input);

        vector<string> str;
        while ( input.find(" ") != string::npos ){
            str.push_back( input.substr(0, input.find(" ")) );
            input = input.substr( input.find(" ") + 1, input.length() );
        }
        str.push_back(input);

        int offset = 0;
        for ( int j = str.size() - 1; j >= 0; j-- ){
            if ( str[j][0] - '0' <= 9 ){
                offset = str[j][0] - '0';

                vector<string>::iterator it = str.begin();
                str.erase(it + j);

            }else{
                str[j][0] = ( str[j][0] + offset - 'A' ) % 26 + 'A';
            }
        }

        for ( int j = 0; j < str.size(); j++ ){
            cout << str[j];
        }

        //cout << endl;
    }
}