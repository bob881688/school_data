#include <iostream>
using namespace std;

int main(){
    int total = 0;
    int h1, m1, h2, m2;
    int minute;
    cin >> h1 >> m1 >> h2 >> m2;

    minute = (h2 - h1) * 60 + (m2 - m1);

    if ( 0 < minute && minute <= 120 ){
        total = (minute / 30) * 30;
    }else if ( 120 < minute && minute <= 240 ){
        minute -= 120;
        total = 120 + (minute / 30) * 40;
    }else{
        minute -= 240;
        total = 280 + (minute / 30) * 60;
    }

    cout << total << endl;
}