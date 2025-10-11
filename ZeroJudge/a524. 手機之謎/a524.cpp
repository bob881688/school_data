#include <iostream>
#include <vector>
using namespace std;

vector<int> number;
vector<bool> visited(9, false);

void dfs( int digit, int n ){
    if ( digit == n ){
        for ( int i = 0; i < n; i++ ){
            cout << number[i];
        }

        cout << endl;
    }

    for ( int i = n; i >= 1; i-- ){
        if ( !visited[i] ){
            number.push_back(i);
            visited[i] = true;
            dfs(digit + 1, n);
            visited[i] = false;
            number.pop_back();
        }
    }
}

int main(){
    int n;
    while ( cin >> n ){
        visited.assign(9, false);
        dfs(0, n);
    }
}