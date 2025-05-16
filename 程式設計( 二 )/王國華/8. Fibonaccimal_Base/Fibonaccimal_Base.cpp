#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int fib[40] = {0, 1};
    for ( int i = 2; i < 40; i++ ){
        fib[i] = fib[i - 1] + fib[i - 2];
    }


    int flag_endl = 0;
    for ( int i = 0; i < n; i++ ){
        int number;
        cin >> number;

        if ( flag_endl != 0 ){
            cout << endl;
        }else{
            flag_endl = 1;
        }

        cout << number << " = ";

        int flag = 0;
        for ( int j = 39; j >= 2; j-- ){
            if ( number >= fib[j] ){
                flag = 1;
                cout << "1";
                number -= fib[j];
            }else if ( flag == 1 ){
                cout << "0";
            }
        }

        cout << " (fib)";
    }
}