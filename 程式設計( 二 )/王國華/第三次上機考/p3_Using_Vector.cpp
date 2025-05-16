#include <iostream>
#include <vector>
using namespace std;

int main(){
    int first, number;
    // 5 1 4 3 9 2 7 8 0

    while ( cin >> first ){ // 5
        vector<int> vec;
        vec.push_back(first);
        
        while ( cin >> number && number != 0 ){ // 1 4 3 9 2 7 8 0
            vec.push_back(number); // 1 4 3 9 2 7 8 (0)
        }

        int flag = 0;
        for ( auto i : vec ){
            if ( flag != 0 ){
                cout << " ";
            }else{
                flag = 1;
            }
            cout << i;
        }
        
        int size = vec.size();
        for ( int i = 0; i < size / 3; i++ ){
            vec.pop_back();
        }

        flag = 0;
        int min = 1e9;
        int max = 0;
        for ( auto i : vec ){
            if ( i < min ){
                min = i;
            }
            if ( i > max ){
                max = i;
            }

            if ( flag != 0 ){
                cout << " ";
            }else{
                flag = 1;
            }
            cout << i;
        }
    }
}