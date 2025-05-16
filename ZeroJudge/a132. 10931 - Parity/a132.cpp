#include <iostream>
using namespace std;

int main(){
    int i;
    while ( cin >> i && i != 0 ){
        int count = 0;
        string binary;
        while ( i != 0 ){
            if ( i % 2 == 1 ){
                binary.append("1");
                count++;
            }else{
                binary.append("0");
            }
            i /= 2;
        }

        cout << "The parity of ";
        for ( int j = binary.length() - 1; j >= 0; j-- ){
            cout << binary[j];
        }
        cout << " is "<< count <<  " (mod 2)." << endl;
    }
}