#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    const string chinese[] = { "零", "壹", "貳", "參", "肆", "伍", "陸", "柒", "捌", "玖" };
    const string big[] = { "", "萬", "億" };

    while ( cin >> n ){
        for ( int i = 0; i < n; i++ ){
            int arabic;
            cin >> arabic;

            vector<int> group;
            while ( arabic != 0 ){
                group.push_back(arabic % 10000);
                arabic /= 10000;
            }

            if ( group.size() == 0 ){
                cout << "零" << endl;
                continue;
            }

            int zf = 1;
            for ( int i = group.size() - 1; i >= 0; i-- ){
                if ( ( group[i] / 1000 ) % 10 != 0 ){
                    cout << chinese[( group[i] / 1000 ) % 10] << "仟";
                    zf = 0;
                }else if ( zf == 0 && group[i] % 1000 != 0 ){
                    cout << "零";
                    zf = 1;
                }

                if ( ( group[i] / 100 ) % 10 != 0 ){
                    cout << chinese[( group[i] / 100 ) % 10] << "佰";
                    zf = 0;
                }else if ( zf == 0 && group[i] % 100 != 0 ){
                    cout << "零";
                    zf = 1;
                }

                if ( ( group[i] / 10 ) % 10 != 0 ){
                    if ( ( group[i] / 10 ) % 10 == 1 && ( group[i] / 100 ) == 0 && i + 1 > group.size() - 1 ){
                        cout << "拾";
                    }else{
                        cout << chinese[( group[i] / 10 ) % 10] << "拾";
                    }
                    
                    zf = 0;
                }else if ( zf == 0 && group[i] % 10 != 0 ){
                    cout << "零";
                    zf = 1;
                }

                if ( ( group[i] / 1 ) % 10 != 0 ){
                    cout << chinese[( group[i] / 1 ) % 10];
                    zf = 0;
                }else if ( zf == 0 && group[i] % 1 != 0 ){
                    cout << "零";
                    zf = 1;
                }

                if ( group[i] != 0 ){
                    cout << big[i];
                }
            }
            
            cout << endl;
        }
    }
}