#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Rectangle{
    public:
        Rectangle( int length, int width ){
            this->length = length;
            this->width = width;
            area = computearea();
            diagonal = computediagonal();
        }

        int computearea(){
            return length * width;
        }
        double computediagonal(){
            return sqrt(length * length + width * width);
        }
        int getlength() const{
            return length;
        }
        int getwidth() const{
            return width;
        }
        int getarea() const{
            return area;
        }
        double getdiagonal() const{
            return diagonal;
        }

    private:
        int length, width;
        int area;
        double diagonal;
};

bool cmp( Rectangle a, Rectangle b);

int main(){
    int n;
    cin >> n;

    vector<Rectangle> arr;
    int length, width;
    for ( int i = 0; i < n; i++ ){
        cin >> length >> width;
        Rectangle rectangle(length, width);
        arr.push_back(rectangle);
    }

    sort(arr.begin(), arr.end(), cmp);

    for ( int i = 0; i < arr.size(); i++ ){
        cout << i + 1 << ":(" << arr[i].getlength() << "," << arr[i].getwidth() << ") area= " << arr[i].getarea() << " diagonal= " << fixed << setprecision(3) << arr[i].getdiagonal() << endl;
    }
}

bool cmp( Rectangle a, Rectangle b ){
    if ( a.getarea() > b.getarea() ){
        return false;
    }else if ( a.getarea() < b.getarea() ){
        return true;
    }else if ( a.getarea() == b. getarea() ){
        if ( a.getdiagonal() < b.getdiagonal() ){
            return false;
        }else{
            return true;
        }
    }else{
        return true;
    }
}