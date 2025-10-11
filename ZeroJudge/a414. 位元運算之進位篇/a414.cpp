#include <iostream>
using namespace std;

int main(){
    int n;
    while ( cin >> n && n!= 0 ){
        int count = 0;

        while ( n & 0x1 ){
            count++;
            n >>= 1;
        }

        cout << count << endl;
    }
}