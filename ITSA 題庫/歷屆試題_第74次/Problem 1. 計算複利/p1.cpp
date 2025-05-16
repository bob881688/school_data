// 計算複利
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double r, n, p;

    while ( cin >> r >> n >> p ){
        double ans = 0;
        double temp;

        for ( int i = 0; i < n; i++ ){
            ans += p;
            temp = ans * r;
            ans += temp;
        }

        cout << (long long)ans << endl;
    }
}