#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, int> arr;
    for ( int i = 0; i < n; i++ ){
        int temp;
        cin >> temp;

        arr[temp] = 1;
    }

    map<int, int>::iterator i;

    cout << arr.size() << endl;
    for ( i = arr.begin(); i != arr.end(); i++ ){
        cout << (*i).first;

        if ( i != arr.end() ){
            cout << " ";
        }
    }
}