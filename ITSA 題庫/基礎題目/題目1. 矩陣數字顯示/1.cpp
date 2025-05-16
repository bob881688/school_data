#include <iostream>
#include <vector>
using namespace std;

int main(){
    string number0[] = {"*****",
                        "*   *",
                        "*   *",
                        "*   *",
                        "*****",};

    string number1[] = {"    *",
                        "    *",
                        "    *",
                        "    *",
                        "    *",};

    string number2[] = {"*****",
                        "    *",
                        "*****",
                        "*    ",
                        "*****",};

    string number3[] = {"*****",
                        "    *",
                        "*****",
                        "    *",
                        "*****",};

    string number4[] = {"*   *",
                        "*   *",
                        "*****",
                        "    *",
                        "    *",};

    string number5[] = {"*****",
                        "*    ",
                        "*****",
                        "    *",
                        "*****",};

    string number6[] = {"*****",
                        "*    ",
                        "*****",
                        "*   *",
                        "*****",};

    string number7[] = {"*****",
                        "    *",
                        "    *",
                        "    *",
                        "    *",};

    string number8[] = {"*****",
                        "*   *",
                        "*****",
                        "*   *",
                        "*****",};

    string number9[] = {"*****",
                        "*   *",
                        "*****",
                        "    *",
                        "*****",};

    vector<string*> numbers(10);
    numbers[0] = number0;
    numbers[1] = number1;
    numbers[2] = number2;
    numbers[3] = number3;
    numbers[4] = number4;
    numbers[5] = number5;
    numbers[6] = number6;
    numbers[7] = number7;
    numbers[8] = number8;
    numbers[9] = number9;

    string input;
    cin >> input;

    for ( int i = 0; i < 5; i++ ){
        for ( int j = 0; j < 4; j++ ){
            cout << numbers[input[j] - '0'][i];
            if ( j != 4 - 1 ){
                cout << " ";
            }
        }
        cout << endl;
    }
}