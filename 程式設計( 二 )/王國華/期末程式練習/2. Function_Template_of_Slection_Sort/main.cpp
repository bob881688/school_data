#include <iostream>
using namespace std;

template<typename T>
void Selection_Sort(T *array, int num){
    for ( int i = 0; i < num; i++ ){
        int min_index = i;
        
        for ( int j = i + 1; j < num; j++ ){
            if ( array[j] < array[min_index] ){
                min_index = j;
            }
        }

        T temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }

    for ( int i = 0; i < num; i++ ){
        if ( i != num - 1 ){
            cout << array[i] << " ";
        }else{
            cout << array[i];
        }
    }
}

int main(){
    int n;
    string name;

    cin >> n;
    cin >> name;
    
    if ( name == "int" ){
        int *array = new int[n];

        for ( int i = 0; i < n; i++ ){
            cin >> array[i];
        }

        Selection_Sort(array, n);
        delete[] array;

    }else if ( name == "double" ){
        double *array = new double[n];

        for ( int i = 0; i < n; i++ ){
            cin >> array[i];
        }

        Selection_Sort(array, n);
        delete[] array;
        
    }else if ( name == "char" ){
        char *array = new char[n];

        for ( int i = 0; i < n; i++ ){
            cin >> array[i];
        }

        Selection_Sort(array, n);
        delete[] array;
        
    }else if ( name == "string" ){
        string *array = new string[n];

        for ( int i = 0; i < n; i++ ){
            cin >> array[i];
        }

        Selection_Sort(array, n);
        delete[] array;
        
    }

    cout << endl;
}