#include <iostream>
using namespace std;

int main(){
    int n, m;
    
    while ( cin >> n >> m ){
        int sum = n;
        int count = 1;

        for ( int i = n + 1; sum <= m ; i++ ){
            sum += i;
            count++;
        }

        cout << count << endl;
    }
}