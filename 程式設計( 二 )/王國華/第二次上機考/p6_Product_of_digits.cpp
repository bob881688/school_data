#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string digits ( int number );

int main(){
    int n;
    cin >> n;

    int flag = 0;
    for ( int i = 0; i < n; i++ ){
        int number;
        cin >> number;
        
        if ( flag != 0 ){
            cout << endl;
        }else{
            flag = 1;
        }

        if ( number == 1 ){
            cout << 1;
        }else{
            cout << digits(number);
        }
    }
}

string digits ( int number ){
    string ans = "";
    for ( int i = 9; i >= 2; i-- ){
        while ( number % i == 0 ){
            ans.append(to_string(i));
            number /= i;
        }
    }

    if ( number != 1 ){
        return "-1";
    }

    reverse(ans.begin(), ans.end());
    return ans;
}