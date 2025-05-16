#include <iostream>
#include <string>
#include <string.h>
#include "HugeInteger.h"
using namespace std;

istream &operator>>( istream &input, HugeInt &h ){
    string str;
    input >> str;
    h.convert(str);
    return input;
}
ostream &operator<<( ostream &output, HugeInt h ){
    h.Print();
    return output;
}

HugeInt::HugeInt(){};
HugeInt::HugeInt( const string &str ){
    convert(str);
}

HugeInt HugeInt::operator+( const HugeInt &other ) const{
    int carry = 0;
    HugeInt ans;

    for ( int i = 0; i < 40; i++ ){
        ans.number[i] = number[i] + other.number[i] + carry;
        carry = ans.number[i] / 10;
        ans.number[i] %= 10; 
    }

    return ans;
}
HugeInt HugeInt::operator-( const HugeInt &other ) const{
    int borrow = 0;
    HugeInt ans;

    if ( *this >= other ){
        for ( int i = 0; i < 40; i++ ){
            ans.number[i] = number[i] - other.number[i] - borrow;
            if ( ans.number[i] < 0 ){
                borrow = 1;
                ans.number[i] += 10;
            }else{
                borrow = 0;
            }
        }
        
    }else{
        ans.isNeg = true;
        for ( int i = 0; i < 40; i++ ){
            ans.number[i] = other.number[i] - number[i] - borrow;
            if ( ans.number[i] < 0 ){
                borrow = 1;
                ans.number[i] += 10;
            }else{
                borrow = 0;
            }
        }
    }

    return ans;
}
HugeInt HugeInt::operator*( const HugeInt &other ) const{
    HugeInt ans;

    for ( int a_i = 0; a_i < 40; a_i++ ){
        if ( number[a_i] == 0 ){
            continue;
        }

        for ( int b_i = 0; b_i < 40; b_i++ ){
            if ( other.number[b_i] == 0 ){
                continue;
            }

            ans.number[a_i + b_i] += number[a_i] * other.number[b_i];

            int pos = a_i + b_i;
            while ( ans.number[pos] >= 10 ){
                ans.number[pos + 1] += ans.number[pos] / 10;
                ans.number[pos] %= 10;
                pos++;
            }
        }
    }

    return ans;
}
HugeInt HugeInt::operator/( const HugeInt &other ) const{
    HugeInt a = *this; // 被除數
    HugeInt b = other;  // 除數
    HugeInt ans("0");   // 商
    HugeInt now("0");    // 當前處理的部分

    for (int i = 39; i >= 0; --i) {
        now.shiftLeft(1); // 左移一位模擬進位
        now.number[0] = a.number[i]; // 新增當前位數

        // 計算該位的商
        int count = 0;
        while (now >= b) {
            now = now - b;
            count++;
        }

        ans.number[i] = count; // 記錄商
    }

    return ans;
}
HugeInt HugeInt::operator%( const HugeInt &other ) const{
    HugeInt a = *this; // 被除數
    HugeInt b = other;  // 除數
    HugeInt ans("0");    // 當前處理的部分

    // 從最高位開始逐步計算餘數
    for (int i = 39; i >= 0; --i) {
        ans.shiftLeft(1); // 左移一位模擬進位
        ans.number[0] = a.number[i]; // 新增當前位數

        while (ans >= b) {
            ans = ans - b;
        }
    }

    return ans; // 返回餘數
}

bool HugeInt::operator<( const HugeInt &other ) const{
    for ( int i = 40 - 1; i >= 0; i-- ){
        if ( number[i] < other.number[i] ){
            return true;
        }
        if ( number[i] > other.number[i] ){
            return false;
        }
    }

    return false;
}
bool HugeInt::operator>( const HugeInt &other ) const{
    for ( int i = 40 - 1; i >= 0; i-- ){
        if ( number[i] > other.number[i] ){
            return true;
        }
        if ( number[i] < other.number[i] ){
            return false;
        }
    }

    return false;
}
bool HugeInt::operator==( const HugeInt &other ) const{
    for ( int i = 40 - 1; i >= 0; i-- ){
        if ( number[i] != other.number[i] ){
            return false;
        }
    }

    return true;
}
bool HugeInt::operator!=( const HugeInt &other ) const{
    return !(*this == other);
}
bool HugeInt::operator>=( const HugeInt &other ) const{
    if ( ( *this > other || *this == other ) && this->isNeg == false ){
        return true;
    }

    return false;
}

void HugeInt::Print(){
    int digit = 40 - 1;

    while ( digit >= 0 && number[digit] == 0 ){
        digit--;
    }

    if ( digit < 0 ){
        cout << "0";
    }else{
        if ( isNeg ){
            cout << "-";
        }
        for ( int i = digit; i >= 0; i-- ){
            cout << number[i];
        }
    }
}

void HugeInt::convert( string str ){
    for ( int i = 0; i < 40; i++ ){
        number[i] = 0;
    }

    for ( int i = 0; i < str.length(); i++ ){
        int reverse_index = str.length() - i - 1;
        number[i] = str[reverse_index] - '0';
    }
}

void HugeInt::shiftLeft(int times) {
    for (int t = 0; t < times; ++t) {
        for (int i = 39; i > 0; --i) {
            number[i] = number[i - 1];
        }
        number[0] = 0; // 最低位補 0
    }
}