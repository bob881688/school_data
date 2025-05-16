#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

class Rectangle{
    public:
        Rectangle( int l, int w ) :length(l), width(w){
            area = cal_area();
            diagonal = cal_diagonal();
        };

        int cal_area(){
            return length * width;
        }

        double cal_diagonal(){
            return sqrt(length * length + width * width);
        }

        int get_length(){
            return length;
        }

        int get_width(){
            return width;
        }

        int get_area(){
            return area;
        }

        double get_diagonal(){
            return diagonal;
        }

    private:
        int length, width, area;
        double diagonal;
};

int cmp( const void *a, const void *b );

int main(){
    int n;
    int length, width;
    cin >> n;
    Rectangle** rectangle = new Rectangle*[n];
    for ( int i = 0; i < n; i++ ){
        cin >> length >> width;
        rectangle[i] = new Rectangle(length, width);
    }

    qsort(rectangle, n, sizeof(*rectangle), cmp);

    for ( int i = 0; i < n; i++ ){
        cout << i + 1 << ":(" << rectangle[i]->get_length() << "," << rectangle[i]->get_width() << ")" << " ";
        cout << "area= " << rectangle[i]->get_area() << " ";
        cout << fixed << setprecision(3) << "diagonal= " << rectangle[i]->get_diagonal() << endl;
    }

    for ( int i = 0; i < n; i++ ){
        delete[] rectangle[i];
    }
    delete[] rectangle;
}

int cmp( const void *a, const void *b ){
    Rectangle* rectA = *(Rectangle**)a;  // 取得指向 Rectangle 的指標
    Rectangle* rectB = *(Rectangle**)b;
    if ( rectA -> get_area() < rectB -> get_area() ){
        return -1;
    }
    if ( rectA -> get_area() == rectB -> get_area() ){
        if  ( rectA -> get_diagonal() > rectB -> get_diagonal() ){
            return -1;
        }else{
            return 1;
        }
    }
    return 1;
    /*if ( (((Rectangle*)a) -> get_area()) < (((Rectangle*)b) -> get_area()) ){
        return -1;
    }
    if ( (((Rectangle*)a) -> get_area()) == (((Rectangle*)b) -> get_area()) ){
        return 0;
    }
    if ( (((Rectangle*)a) -> get_area()) > (((Rectangle*)b) -> get_area()) ){
        return 1;
    }
    return 0;*/
    //return (int)( (((Rectangle*)a) -> get_area()) - (((Rectangle*)b) -> get_area()));*/
}
