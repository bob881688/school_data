#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ){
        int r;
        cin >> r;

        int *people = new int[r];
        for ( int j = 0; j < r; j++ ){
            cin >> people[j];
        }

        sort(people, people + r);

        int sum = 0;
        int mid = 0;
        if ( r % 2 == 0 ){
            mid = ( people[r / 2] + people[r / 2 - 1] ) / 2;
        }else{
            mid = people[r / 2];
        }

        for ( int j = 0; j < r; j++ ){
            sum += abs(people[j] - mid);
        }

        cout << sum << endl;
    }
}