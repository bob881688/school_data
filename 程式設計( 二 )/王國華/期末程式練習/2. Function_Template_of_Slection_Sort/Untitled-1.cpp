#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// 計算檔案中的換行數
int countNewlines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return -1;

    int newlineCount = 0;
    string line;
    while (getline(file, line)) {
        newlineCount++;
    }

    // 檢查最後是否以換行符結尾
    file.clear();
    file.seekg(0, ios::end); // 將檔案指標移到末尾
    if (file.tellg() > 0) { // 確保檔案不是空的
        file.seekg(-1, ios::end);
        char lastChar;
        file.get(lastChar);
        if (lastChar != '\n') {
            newlineCount--; // 如果沒有以換行符結尾，減去最後一行的假換行
        }
    }

    return newlineCount;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: judge inputfile ansfile userfile\n";
        return 1;
    }

    ifstream infile(argv[1]);     // 標準輸入檔案（此處未使用，但可擴展用於檢查測資）
    ifstream ansfile(argv[2]);   // 標準答案檔案
    ifstream userfile(argv[3]);  // 使用者輸出檔案

    if (!infile.is_open() || !ansfile.is_open() || !userfile.is_open()) {
        cerr << "Error opening one or more files.\n";
        return 1;
    }

    string userLine, ansLine;
    int lineCount = 0;

    while (true) {
        bool userEOF = !getline(userfile, userLine);
        bool ansEOF = !getline(ansfile, ansLine);
        lineCount++;

        // 如果兩邊都到達檔案結尾，檢查換行數是否一致
        if (userEOF && ansEOF) {
            int userNewlines = countNewlines(argv[3]);
            int ansNewlines = countNewlines(argv[2]);

            if (userNewlines != ansNewlines) {
                cout << "$JUDGE_RESULT=WA\n";
                cout << "$LINECOUNT=" << lineCount << "\n";
                cout << "$MESSAGE=換行數不一致。標準答案有 " << ansNewlines
                          << " 行，使用者輸出有 " << userNewlines << " 行。\n";
                return 0;
            }

            cout << "$JUDGE_RESULT=AC\n";
            return 0;
        }

        // 如果只有一邊到達檔案結尾，內容不匹配
        if (userEOF || ansEOF) {
            cout << "$JUDGE_RESULT=WA\n";
            cout << "$LINECOUNT=" << lineCount << "\n";
            cout << "$USEROUT=" << (userEOF ? "<EOF>" : userLine) << "\n";
            cout << "$SYSTEMOUT=" << (ansEOF ? "<EOF>" : ansLine) << "\n";
            cout << "$MESSAGE=輸出行數不匹配。\n";
            return 0;
        }

        // 嚴格比對每一行內容
        if (userLine != ansLine) {
            cout << "$JUDGE_RESULT=WA\n";
            cout << "$LINECOUNT=" << lineCount << "\n";
            cout << "$USEROUT=" << userLine << "\n";
            cout << "$SYSTEMOUT=" << ansLine << "\n";
            if ( userLine[userLine.length() - 1] == ' ' ){
                cout << "$MESSAGE=您的答案後有多空白。\n";
            }else{
                cout << "$MESSAGE=您的答案與標準答案不一致。\n";
            }
            return 0;
        }
    }
}
