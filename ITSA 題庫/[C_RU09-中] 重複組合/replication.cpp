#include <iostream>
#include <string>
using namespace std;

long long int recurision(int n, int k);

int main(){
    string str;
    
    while ( cin >> str ){
        int n = 1, k = 0; // 如果方程式 X=5，沒有+號，n就是1(1個變數)

        int pos = 0; // 搜尋的位置(從0開始)
        while ( str.find("+", pos) != string::npos ){ // 找+
            n++;
            pos = str.find("+", pos) + 1; // 從找到的下一個開始找
        }
        for ( int i = str.find('=') + 1; i < str.length(); i++ ){ // 找=右邊的數字
            k *= 10;
            k += str[i] - '0'; // 因為str[i] 是字串的形式，所以計算到'0'的距離，例如'9'(字元)-'0'(字元) = 9(整數)
        }
        


        cout << n << endl << recurision(n + k - 1, k) << endl;
    }
}

long long int recurision(int n, int k) { // C(n 取 k)
    if (k > n - k){ // C(10 7) = C(10 3)
       k = n - k;
    }

    long long int result = 1;
    for (int i = 1; i <= k; ++i) { // 範例 C(10 3) = (10 * 9 * 8) / (3 * 2 * 1) [10! / 3!7!]
        result *= n - i + 1;
        result /= i;
        // i = 1
        // *10(分子) / 1(分母)
        // i = 2
        // *9(分子) / 2(分母)
        // i = 3
        // *8(分子) / 3(分母)
    }
    
    return result;
}