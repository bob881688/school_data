#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main(){
    unordered_set<string> appeared; // 判斷有沒有重複的工具
    vector<string> input_order;
    string word;//輸入的句子
    getline(cin, word);
    stringstream ss(word);
    while(ss >> word){ // 將讀的一整行依照空格分開
        for(size_t i = 0; i < word.length(); ++i){ // 這個原本在下面出現 目的是為了將大寫轉成小寫
            word[i] = tolower(word[i]); // 但是WHAT跟what應該要是同一個字 所以搬到這裡做處理
        }
        // 這個是unordered_set的功能 可以計算某個特定的東西有沒有出現過
        // 有出現過會回傳1 否則就回傳0
        // 如果剛剛沒有先轉成小寫 這裡的判斷會把WHAT跟what分成不同的字 導致重複計算
        if(appeared.count(word) == 0){ 
            appeared.insert(word); // 將這個單字加到unordered_set裡 之後才能查有沒有重複
            input_order.push_back(word); // 並且之後也要照這個順序輸出
        }else{
           continue; // 如果有重複 則不做任何事(忽略這個字)
        }
    }

    int flag = 0; // 這個依然是拿來控制空格
    for(string &output : input_order){
        if ( flag != 0 ){
            cout << " " << output; // 第2 3 4 5...個字
        }else{
            cout << output; // 第1個字
            flag = 1;
        }
    }

    cout << endl; // 題目說最後的最後要換行
}