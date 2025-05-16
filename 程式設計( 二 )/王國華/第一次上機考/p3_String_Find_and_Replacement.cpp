#include <iostream>
#include <string>
using namespace std;

int main(){
    string origin, target, replacement;
    int flag_endl = 0;

    while ( getline(cin, origin) ){
        cin >> target >> replacement;
        cin.ignore();

        if ( flag_endl != 0 ){
            cout << endl;
        }else{
            flag_endl = 1;
        }

        if ( origin.find(target) != string::npos ){
            int index = 0;
            int flag = 0;

            while ( origin.find(target, index) != string::npos ){
                if ( flag == 0 ){
                    cout << origin.find(target, index);
                    flag = 1;
                }else{
                    cout << " " << origin.find(target, index);
                }

                index = origin.find(target, index) + target.length();
            }

            while ( origin.find(target) != string::npos ){
                origin.replace(origin.find(target), target.length(), replacement);
            }

            cout << endl << origin;
        }else{

            cout << "-1" << endl << origin;
        }
        
        cout << endl;
    }
}