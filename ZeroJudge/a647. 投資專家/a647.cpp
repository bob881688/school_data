#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ){
        double buy, sell;
        cin >> buy >> sell;

        double money = ( sell - buy ) / buy;

        if ( money >= 0 ){
            money += 0.0000001;
        }else{
            money -= 0.0000001;
        }

        money *= 100;

        if ( money >= 10 || money <= -7 ){
            cout << fixed << setprecision(2) << money << "% dispose" << endl;
        }else{
            cout << fixed << setprecision(2) << money << "% keep" << endl;
        }
    }
}