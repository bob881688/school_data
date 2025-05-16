#include <iostream>
using namespace std;

int main(){
    string line;

    while ( cin >> line ){
        int count[26] = {0};

        for ( int i = 0; i < line.length(); i++ ){
            if ( line[i] >= 'A' && line[i] <= 'Z' ){
                count[line[i] - 'A']++;
            }else if ( line[i] >= 'a' && line[i] <= 'z' ){
                count[line[i] - 'a']++;
            }
        }

        int flag = 0;
        for ( int i = 0; i < 26; i++ ){
            if ( count[i] % 2 != 0 ){
                flag++;
            }
        }

        if ( flag > 1 ){
            cout << "no..." << endl;
        }else{
            cout << "yes !" << endl;
        }
    }
}