#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp( string a, string b ){
    if ( a[0] == '-' && b[0] != '-' ){ //* a < 0 && b >= 0
        return true;
    }else if ( a[0] != '-' && b[0] == '-' ){ //* a >= 0 && b < 0
        return false;
    }

    if ( a[0] == '-' && b[0] == '-' ){ //* a < 0 && b < 0
        if ( a.length() != b.length() ){
            return a.length() > b.length();
        }else{
            return a > b;
        }
    }else{
        if ( a.length() != b.length() ){
            return a.length() < b.length();
        }else{
            return a < b;
        }
    }
}

int main(){
    int n;
    while ( cin >> n ){
        vector<string> arr(n);
        for ( int i = 0; i < n; i++ ){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), cmp);

        for ( int i = 0; i < n; i++ ){
            cout << arr[i] << endl;
        }
    }
}