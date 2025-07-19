#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> boxes(n, 0);
    for ( int i = 0; i < q; i++ ){
        int x;
        cin >> x;

        if ( x > 0 ){
            boxes[x - 1]++;
            cout << x;
        }else if ( x == 0 ){
            int min_index = 0;
            for ( int j = 0; j < n; j++ ){
                if ( boxes[min_index] > boxes[j] ){
                    min_index = j;
                }
            }

            boxes[min_index]++;
            cout << min_index + 1;
        }

        if ( i != q - 1 ){
            cout << " ";
        }
    }
}