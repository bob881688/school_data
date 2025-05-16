#include <iostream>
using namespace std;

int main(){
    string target, origin;

    while ( cin >> target >> origin ){
        int count = 0;
        int pos = 0;

        while ( origin.find(target, pos) != string::npos ){
            count++;
            pos = origin.find(target, pos) + 1;
        }

        cout << count << endl;
    }
}