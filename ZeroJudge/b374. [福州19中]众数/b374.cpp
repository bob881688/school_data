#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> array;
    for ( int i = 0; i < n; i++ ){
        int number;
        cin >> number;

        array[number]++;
    }

    int max = 0;
    for ( auto iterator : array ){
        if ( max < iterator.second ){
            max = iterator.second;
        }
    }

    for ( auto iterator : array ){
        if ( iterator.second == max ){
            cout << iterator.first << " " << max << endl;
        }
    }
}