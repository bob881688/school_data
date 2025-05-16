#include <iostream>
using namespace std;

int main(){
    int m;
    cin >> m;

    int n, data;
    for ( int i = 0; i < m; i++ ){
        cin >> n;

        int array[10] = {0};
        for ( int j = 0; j < n; j++ ){
            cin >> data;
            array[data]++;
        }

        int max = 0;
        for ( int j = 0; j < 10; j++ ){
            if ( array[j] > max ){
                max = array[j];
            }
        }

        cout << max << endl;
    }
}