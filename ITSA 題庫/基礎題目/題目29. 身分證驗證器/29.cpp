#include <iostream>
using namespace std;

int main() {
	string identify;
	int top, tmp, total;
	cin >> identify;

	if( identify[ 0 ] == 'A' ){
		top = 10;
	}else if( identify[ 0 ] == 'B' ){
		top = 11;
	}else if( identify[ 0 ] == 'C' ){
		top = 12;
	}else if( identify[ 0 ] == 'D' ){
		top = 13;
	}else if( identify[ 0 ] == 'E' ){
		top = 14;
	}else if( identify[ 0 ] == 'F' ){
		top = 15;
	}else if( identify[ 0 ] == 'G' ){
		top = 16;
	}else if( identify[ 0 ] == 'H' ){
		top = 17;
	}else if( identify[ 0 ] == 'I' ){
		top = 34;
	}else if( identify[ 0 ] == 'J' ){
		top = 18;
	}else if( identify[ 0 ] == 'K' ){
		top = 19;
	}else if( identify[ 0 ] == 'L' ){
		top = 20;
	}else if( identify[ 0 ] == 'M' ){
		top = 21;
	}else if( identify[ 0 ] == 'N' ){
		top = 22;
	}else if( identify[ 0 ] == 'O' ){
		top = 35;
	}else if( identify[ 0 ] == 'P' ){
		top = 23;
	}else if( identify[ 0 ] == 'Q' ){
		top = 24;
	}else if( identify[ 0 ] == 'R' ){
		top = 25;
	}else if( identify[ 0 ] == 'S' ){
		top = 26;
	}else if( identify[ 0 ] == 'T' ){
		top = 27;
	}else if( identify[ 0 ] == 'U' ){
		top = 28;
	}else if( identify[ 0 ] == 'V' ){
		top = 29;
	}else if( identify[ 0 ] == 'W' ){
		top = 32;
	}else if( identify[ 0 ] == 'X' ){
		top = 30;
	}else if( identify[ 0 ] == 'Y' ){
		top = 31;
	}else if( identify[ 0 ] == 'Z' ){
		top = 33;
	}
	
	tmp = top / 10 + ( top % 10 ) * 9;
	total = tmp + ( identify[ 1 ] - '0' ) * 8 + ( identify[ 2 ] - '0' ) * 7 + ( identify[ 3 ] - '0' ) * 6 + ( identify[ 4 ] - '0' ) * 5 + ( identify[ 5 ] - '0' ) * 4 + ( identify[ 6 ] - '0' ) * 3 + ( identify[ 7 ] - '0' ) * 2 + ( identify[ 8 ] - '0' ) * 1 + ( identify[ 9 ] - '0' );
	
	if( total % 10 == 0 ){
		cout << "CORRECT!!!\n";
	}else{
		cout << "WRONG!!!\n";
	}
}