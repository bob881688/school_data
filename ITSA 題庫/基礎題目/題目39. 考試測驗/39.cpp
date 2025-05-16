#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ){
        int listen, reading, speaking;
        cin >> listen >> reading >> speaking;

        int sum = listen + reading + speaking;
        int fail = 0;
        if ( listen < 60 ){
            fail++;
        }
        if ( reading < 60 ){
            fail++;
        }
        if ( speaking < 60 ){
            fail++;
        }

        if ( fail == 0 ){
            cout << "P\n";
        }
        if ( fail == 1 ){
            if ( sum >= 220 ){
                cout << "P\n";
            }else{
                cout << "M\n";
            }
        }
        if ( fail == 2 ){
            if ( listen >= 80 || reading >= 80 || speaking >= 80 ){
                cout << "M\n";
            }else{
                cout << "F\n";
            }
        }
        if ( fail == 3 ){
            cout << "F\n";
        }
    }
}