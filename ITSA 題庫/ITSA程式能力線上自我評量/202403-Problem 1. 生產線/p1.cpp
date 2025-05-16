#include <iostream>
using namespace std;

int main(){
    int n;

    while ( cin >> n ){
        int time[25] ={0};
        for ( int i = 0; i < n; i++ ){
            int s, d;
            cin >> s >> d;

            for ( int j = s; j < d; j++ ){
                time[j]++;
            }
        }

        int max = 0;
        for ( int i = 0; i < 25; i++ ){
            if ( time[i] > max ){
                max = time[i];
            }
        }

        cout << max << endl;
    }      
}