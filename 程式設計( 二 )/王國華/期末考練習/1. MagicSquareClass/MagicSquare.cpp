#include <iostream>
#include <iomanip>

using namespace std;

class Magicsquare{
    public:
        Magicsquare(int n) : size(n), row(0), col( (n + 1) / 2 ) {
            for ( int i = 0; i < size; i++ ){
                array[i] = new int[size];
            }
        }
        ~Magicsquare(){
            for ( int i = 0; i < size; i++ ){
                delete[] array[i];
            }
            delete[] array;
        };

        void fillsquare(){
            for ( int key = 1; key <= size * size; key++ ){
                if ( key % size == 1 ){
                    row++;
                }else{
                    row--;
                    col++;
                }

                if ( row == 0 ){
                    row = size;
                }
                if ( col > size ){
                    col = 1;
                }
                array[row - 1][col - 1] = key;
            }
        }

        void printsquare(){
            cout << (1 + size * size) * size / 2 << endl;
            for ( int i = size - 1; i >= 0; i-- ){
                for ( int j = 0; j < size; j++ ){
                    if ( j != size - 1 ){
                        cout << array[i][j] << " " ;
                    }else{
                        cout << array[i][j];
                    }    
                }
                if ( i != size - 1 ){
                    cout << endl;
                }
            }
        }
    private:
        const int size;
        int row, col;
        int **array = new int*[size];
};

int main(){
    int n;
    int flag = 0;
    while ( cin >> n ){
        Magicsquare square(n);
        
        if ( flag != 0 ){
            cout << endl;
        }

        if ( n % 2 == 0 ){
            cout << "It is not an odd number." << endl;
            flag = 1;
        }else{
            square.fillsquare();
            square.printsquare();
            flag = 1;
        }
    }
}