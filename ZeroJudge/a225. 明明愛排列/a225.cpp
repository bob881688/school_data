#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp( int a, int b);

int main(){
    int n;

    while ( cin >> n ){
        vector<int> number;

        for ( int i = 0; i < n; i++ ){
            int tmp;
            cin >> tmp;
            number.push_back(tmp);
        }

        sort(number.begin(), number.end(), cmp);

        for ( int i = 0; i < n; i++ ){
            cout << number[i] << " ";
        }

        cout << endl;
    }
}

bool cmp( int a, int b ){
    if ( a % 10 < b % 10 ){
        return true;
    }else if ( a % 10 > b % 10 ){
        return false;
    }

    if ( a / 10 < b / 10 ){
        return false;
    }else if ( a / 10 > b / 10 ){
        return true;
    }

    return true;
}
