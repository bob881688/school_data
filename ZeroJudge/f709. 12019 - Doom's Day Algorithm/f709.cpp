#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    int days_of_a_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days_name[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
    for ( int i = 0; i < t; i++ ){
        int m, d;
        cin >> m >> d;

        int sum_of_days = 0;
        for ( int i = 1; i < m; i++ ){
            sum_of_days += days_of_a_month[i];
        }

        sum_of_days += d - 1;

        cout << days_name[sum_of_days % 7] << endl;
    }
}