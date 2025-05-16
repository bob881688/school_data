// TLE
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;

    while ( cin >> n && n != 0 ){
        cout << "Original number was " << n << endl;

        int count = 0;
        int pre = 0;
    
        while ( n != pre ){
            pre = n;
            string input = to_string(n);
    
            sort(input.begin(), input.end());
            int a = stoi(input);
    
            reverse(input.begin(), input.end());
            int b = stoi(input);
    
            n = b - a;
            count++;
    
            cout << b << " - " << a << " = " << n << endl;
        }
    
        cout << "Chain length " << count << endl << endl;
    }
}