#include <iostream>
using namespace std;

int main(){
    int n;
    int input, k[3] = {0};

    while ( cin >> n ){
        for ( int i = 0; i < n; i++ ){
            cin >> input;

            k[input % 3]++;
        }
    }
    
    cout << k[0] << " " << k[1] << " " << k[2] << endl;
}