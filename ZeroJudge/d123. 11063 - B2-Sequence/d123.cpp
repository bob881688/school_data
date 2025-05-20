#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int casec = 1;
    while ( cin >> n ){
        int break_flag = 0;
        int *num_arr = new int[n];
        for ( int i = 0; i < n; i++ ){
            cin >> num_arr[i];
            if ( i > 0 && num_arr[i] < num_arr[i - 1] ){
                break_flag = 1;
            }
        }
        
        if ( break_flag == 0 ){
            vector<int> vec;
            for ( int i = 0; i < n; i++ ){
                for ( int j = i; j < n; j++ ){
                    vec.push_back(num_arr[i] + num_arr[j]);
                }
            }
            
            for ( int i = 0; i < vec.size() - 1; i++ ){
                for ( int j = i + 1; j < vec.size(); j++){
                    if ( vec[i] == vec[j] ){
                        break_flag = 1;
                        break;
                    }
                }
                
                if ( break_flag == 1 ){
                    break;
                }
            }

            delete[] num_arr;
        }
        
        if ( break_flag == 0 ){
            cout << "Case #" << casec << ": It is a B2-Sequence." << endl;
        }else{
            cout << "Case #" << casec << ": It is not a B2-Sequence." << endl;
        }
        casec++;
    }
}