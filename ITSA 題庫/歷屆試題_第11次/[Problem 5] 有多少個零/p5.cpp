#include <iostream>
using namespace std;

int main(){
    int n;

    while ( cin >> n ){
        for ( int i = 0; i < n; i++ ){
            int x, y;
            cin >> x >> y;
    
            int count = 0;
            for ( int j = x + 1; j < y; j++ ){
                int temp = j; // 把 j 存到temp 裡面，才不會動到
                while ( temp != 0 ){ // 當temp不是0的時候，繼續找最後一位數是不是0
                    if ( temp % 10 == 0 ){ // 找最後1位的數字 例如 123 % 10 = 3 (取到最後一位數)
                        count++;
                    }
    
                    temp /= 10; // 去掉最後一位數字 例如 123 / 10 = 12 (最後一位數會消失) 
                }
            }
            
            if ( count == 0 ){ // 如果沒有找到0
                cout << "No Solution\n";
            }else{ // 否則
                cout << count << endl;
            }

            if ( i != n - 1 ){ // 如果 i (迴圈) 不是測資筆數 - 1，就要換行
                               //例如有3筆測資(n = 3)，會在第1筆(i = 0)和第2筆(i = 1) 後換行
                cout << endl;
            }
        }
    }
}