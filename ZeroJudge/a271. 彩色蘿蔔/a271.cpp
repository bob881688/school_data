#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int case_count;
    cin >> case_count;

    for ( int i = 0; i < case_count; i++ ){
        int x, y, z, w, n, m;
        string str; 

        cin >> x >> y >> z >> w >> n >> m;
        cin.ignore();

        getline(cin, str);
        stringstream ss(str);

        int num;
        int poision = 0;
        bool die = false;
        while ( ss >> num ){
            for ( int j = 0; j < poision; j++ ){
                m -= n;
                if ( m <= 0 ){
                    die = true;
                    break;
                }
            }

            switch (num){
                case 1:
                    m += x;
                    break;
            
                case 2:
                    m += y;
                    break;

                case 3:
                    m -= z;
                    break;

                case 4:
                    m -= w;
                    poision++;
                    break;
                default:
                    break;
            }


            if ( m <= 0 || die ){
                die = true;
                break;
            }
        }

        if ( !die ){
            cout << m << "g" << endl;
        }else{
            cout << "bye~Rabbit" << endl;
        }

        ss.clear();
    }
}