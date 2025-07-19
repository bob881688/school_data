#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    unordered_set<char> t_record;
    for ( int i = 0; i < t.length(); i++ ){
        t_record.insert(t[i]);
    }

    bool found = true;
    for ( int i = 1; i < s.length(); i++ ){
        if ( s[i] >= 'A' && s[i] <= 'Z' ){
            if ( t_record.count(s[i - 1]) == 0 ){
                found = false;
                break;
            }
        }
    }

    if ( found == true ){
        cout << "Yes";
    }else{
        cout << "No";
    }
}