#include <iostream>
using namespace std;

bool isLeapYear( int y ){
    if ( y % 4 == 0 ){
        if ( y % 100 == 0 ){
            if ( y % 400 == 0 ){
                return true;
            }else{
                return false;
            }
        }else{
            return true;
        }
    }else{
        return false;
    }
}

int year_to_year( int y ){
    int days = 0;
    for ( int i = 1; i < y; i++ ){
        if ( isLeapYear(i) ){
            days += 366;
        }else{
            days += 365;
        }
    }

    return days;
}

int month_to_month( int y, int m, int d ){
    int days_of_months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;

    if ( isLeapYear(y) ){
        days_of_months[2] = 29;
    }

    for ( int i = 1; i < m; i++ ){
        days += days_of_months[i];
    }

    days += d - 1;

    return days;
}

int main(){
    int y1, m1, d1;
    int y2, m2, d2;

    while ( cin >> y1 >> m1 >> d1 ){
        cin >> y2 >> m2 >> d2;
    
        int total1 = year_to_year(y1) + month_to_month(y1, m1, d1);
        int total2 = year_to_year(y2) + month_to_month(y2, m2, d2);
    
        if ( total1 < total2 ){
            cout << total2 - total1 << endl;
        }else{
            cout << total1 - total2 << endl;
        }
    }
}