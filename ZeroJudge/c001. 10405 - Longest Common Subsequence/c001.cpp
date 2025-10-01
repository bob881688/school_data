#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> lcs(1001, vector<int>(1001, 0));

void lcs_method( string s, string t ){
    for ( int i = 1; i <= s.length(); i++ ){
        for ( int j = 1; j <= t.length(); j++ ){
            if ( s[i - 1] == t[j - 1]){
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }else{
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
}

int main(){
    string s, t;

    
    while ( cin >> s >> t ){
        lcs.assign(1001, vector<int>(1001, 0));
        lcs_method(s, t);

        cout << lcs[s.length()][t.length()] << endl;
    }
}