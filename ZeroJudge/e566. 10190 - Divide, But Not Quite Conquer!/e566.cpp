#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n;

    while ( cin >> m >> n ){
        vector<int> store;
        store.push_back(m);

        int isBoring = 0;
        while ( m != 1 ){
            if ( m == 0 || n == 0 || n == 1 ){
                cout << "Boring!";
                isBoring = 1;
                break;
            }

            if ( m % n == 0 ){
                store.push_back(m / n);
                m /= n;
            }else{
                cout << "Boring!";
                isBoring = 1;
                break;
            }
        }

        if ( isBoring == 0 ){
            for ( int i = 0; i < store.size(); i++ ){
                if ( i != store.size() - 1 ){
                    cout << store[i] << " ";
                }else{
                    cout << store[i];
                }
            }
        }

        cout << endl;
    }
}