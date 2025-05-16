#include <iostream>
using namespace std;

int main(){
    int year;

    while ( cin >> year ){
        if ( year % 4 == 0 ){
            if ( year % 100 == 0 && year % 400 != 0 ){
                cout << "Common Year\n";
            }else if ( year % 100 == 0 && year % 400 == 0 ){
                cout << "Bissextile Year\n";
            }else{
                cout << "Bissextile Year\n";
            }
    
        }else{
            cout << "Common Year\n";
        }
    }
}