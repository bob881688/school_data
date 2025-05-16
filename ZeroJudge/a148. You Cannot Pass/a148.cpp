#include <iostream>
using namespace std;

int main(){
    int n;

    while ( cin >> n ){
        int sum = 0;

        for ( int i = 0; i < n; i++ ){
            int score;
            cin >> score;

            sum += score;
        }

        if ( (double)sum / n > 59.0 ){
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
        }
    }
}