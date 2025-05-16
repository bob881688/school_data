#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Student{
    public:
        Student( int m, int e, int c ){
            mathematic = m;
            english = e;
            chinese = c;
            average = ( m + e + c ) / 3.0;
        }

        int getmathematic() const{
            return mathematic;
        }
        int getenglish() const{
            return english;
        }
        int getchinese() const{
            return chinese;
        }
        double getaverage() const{
            return average;
        }
    private:
        int mathematic, english, chinese;
        double average;
};

bool cmp( const Student a, const Student b );

int main(){
    int a;
    cin >> a;
    vector<Student> record;
    int m, e, c;
    string trash;
    for ( int i = 0; i < a; i++ ){
        cin >> trash >> m >> trash >> e >> trash >> c;
        record.push_back(Student(m, e, c));
    }

    sort(record.begin(), record.end(), cmp);

    for ( int i = 0; i < a; i++ ){
        cout << i + 1 << " [M: " << record[i].getmathematic() << ", E: " << record[i].getenglish() << ", C: " << record[i].getchinese() << "] Average = " << fixed << setprecision(2) << record[i].getaverage() << endl;
    }
}

bool cmp( const Student a, const Student b ){
    if ( a.getaverage() > b.getaverage() ){
        return true;
    }else if ( a.getaverage() < b.getaverage() ){
        return false;
    }

    if ( a.getmathematic() > b.getmathematic() ){
        return true;
    }else if ( a.getmathematic() < b.getmathematic() ){
        return false;
    }
    if ( a.getenglish() > b.getenglish() ){
        return true;
    }else if ( a.getenglish() < b.getenglish() ){
        return false;
    }
    return false;
}