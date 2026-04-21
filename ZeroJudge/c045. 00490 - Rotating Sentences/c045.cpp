#include <iostream>
#include <vector>
using namespace std;

int main(){
    string one;
    vector<string> lines;

    int maxlength = 0;
    while ( getline(cin, one) ){
        if ( one.length() > maxlength ){
            maxlength = one.length();
        }

        lines.push_back(one);
    }

    for ( int i = 0; i < maxlength; i++ ){
        for ( int j = lines.size() - 1; j >= 0; j--){
            if ( i <= lines[j].length() - 1){
                cout << lines[j][i];
            }else{
                cout << " ";
            }
        }

        cout << endl;
    }
}