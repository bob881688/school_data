#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int pririority( string str );
double calculate( double a, double b, string ope );


int main(){
    string input[5];
    int flag = 0;

    while ( cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4]){
        if ( flag != 0 ){
            cout << endl;
        }else{
            flag = 1;
        }
        
        double num[3];
        string ope[2];

        num[0] = stod(input[0]);
        num[1] = stod(input[2]);
        num[2] = stod(input[4]);

        ope[0] = input[1];
        ope[1] = input[3];

        if ( pririority(ope[0]) > pririority(ope[1]) ){
            double temp = calculate(num[0], num[1], ope[0]);
            cout << calculate(temp, num[2], ope[1]);
        }else if ( pririority(ope[0]) < pririority(ope[1]) ){
            double temp = calculate(num[1], num[2], ope[1]);
            cout << calculate(num[0], temp, ope[0]);
        }else{
            double temp = calculate(num[0], num[1], ope[0]);
            cout << calculate(temp, num[2], ope[1]);
        }
    }
}

int pririority( string str ){
    if ( str == "+" || str == "-" ){
        return 1;
    }else if ( str == "*" || str == "/" || str == "%" ){
        return 2;
    }

    return 0;
}

double calculate( double a, double b, string ope ){
    if ( ope == "+" ){
        return a + b;
    }else if ( ope == "-" ){
        return a - b;
    }else if ( ope == "*" ){
        return a * b;
    }else if ( ope == "/" ){
        return a / b;
    }

    return -1;
}