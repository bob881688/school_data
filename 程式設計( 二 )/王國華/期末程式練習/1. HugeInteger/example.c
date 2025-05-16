#include <stdio.h>
#include <string.h>

void read(char big[60], int num[60]);
void display(int ans[120]);

void add(int a[60], int b[60], int ans[120]);
void sub(int a[60], int b[60], int ans[120]);
void mul(int a[60], int b[60], int ans[120]);

int main(){
    char a_big[60], b_big[60];  // 以char型態存剛輸入的東西
    int a_int[60], b_int[60], ans[120] = {0};
    char c;

    scanf( "%59s %c %59s", a_big, &c, b_big );
    read(a_big, a_int);
    read(b_big, b_int);

    if ( c == '+' ){
        add(a_int, b_int, ans);
        display(ans);
    }else if ( c == '-' ){
        sub(a_int, b_int, ans);
        display(ans);
    }else if ( c == '*' ){
        mul(a_int, b_int, ans);
        display(ans);
    } 
}

// 將剛讀進來的東西反轉，比較好計算
void read(char big[60], int num[60]){ // 例 big[0] = 1, big[1] = 2, big[2] = 3; num[0] = 3, num [1] = 2, num[2] = 1
    memset( num, 0, sizeof(int) * 60 ); // 將num清空，避免有亂數，memset(目標陣列, 要填入的東西, 從0填到多少);
    for ( int i = strlen(big) - 1; i >= 0; i-- ){ // 從最後開始讀
        num[strlen(big) - i - 1] = big[i] - '0'; // 從最前面開始存， -'0' 是用ascii碼，例如 '5' - '0' = 5 (53 - 48 = 5)
    }
}

// 顯示答案
void display(int ans[120]){
    int digit = 120 - 1;
    for ( digit; digit >= 0 && ans[digit] == 0; digit-- ); // 先省略掉前面的0，例如輸入3，ans = "000000...3"
        
    while ( digit >= 0 ){
        printf("%d", ans[digit]);
        digit--;
    }
}

// 用直式的方式思考
// 加法
void add(int a[60], int b[60], int ans[120]){
    int carry = 0; // 進位
    for ( int i = 0; i < 60; i++ ){
        ans[i] = a[i] + b[i] + carry;
        carry = ans[i] / 10;
        ans[i] %= 10;
    }
}

// 減法(題目已確保 a >= b)
void sub(int a[60], int b[60], int ans[120]){
    int borrow = 0; // 借位
    for ( int i = 0; i < 60; i++ ){
        ans[i] = a[i] - b[i] - borrow;
        if ( ans[i] < 0 ){
            borrow = 1;
            ans[i] += 10;
        }else{
            borrow = 0;
        }
    }
}

// 乘法
void mul(int a[60], int b[60], int ans[120]){
    for ( int i_a = 0; i_a < 60; i_a++ ){
        if ( a[i_a] == 0 ){
            continue;
        }
        for ( int i_b = 0; i_b < 60; i_b++ ){
            ans[i_a + i_b] += a[i_a] * b[i_b];
            if ( ans[i_a + i_b] >= 10 ){
                ans[i_a + i_b + 1] += ans[i_a + i_b] / 10;
                ans[i_a + i_b] %= 10;
            }
        }
    }
}