#include <iostream>
using namespace std;

int main(){
    long long int a, b;

    while ( cin >> a >> b ){
        while ( b != 0 ){
            long long int temp = a % b;
            a = b;
            b = temp;
        }

        cout << a << endl;
    }
}