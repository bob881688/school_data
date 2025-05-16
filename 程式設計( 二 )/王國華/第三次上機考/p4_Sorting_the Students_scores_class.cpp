#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Student{

    friend istream &operator>>( istream &input, Student &s ){
        // M: 85 E: 77 C: 84
        string trash;
        input >> trash >> s.Mathematic >> trash >> s.English >> trash >> s.Chinese;
        s.Average = ( s.Mathematic + s.English + s.Chinese ) / 3.0;
        return input;
    }
    friend ostream &operator<<( ostream &output, Student s ){
        // [M: 100, E: 100, C: 100]
        output << " [M: " << s.Mathematic << ", E: " << s.English << ", C: " << s.Chinese << "] Average = " << fixed << setprecision(2) << s.Average;
        return output;
    }

    public:
        Student(){};
        Student( int m, int e, int c ){
            Mathematic = m;
            English = e;
            Chinese = c;
            Average = ( m + e + c ) / 3.0;
        }

        bool operator<( const Student &other ) const{
            if ( Average < other.Average ){
                return false;
            }else if ( Average > other.Average ){
                return true;
            }

            if ( Mathematic < other.Mathematic ){
                return false;
            }else if ( Mathematic > other.Mathematic ){
                return true;
            }

            if ( English < other.English ){
                return false;
            }else if ( English > other.English ){
                return true;
            }

            return true;
        }

    private:
        int Mathematic, English, Chinese;
        double Average;
};

int main(){
    int n;
    cin >> n;

    vector<Student> storage;
    for ( int i = 0; i < n; i++ ){
        Student student;
        cin >> student;
        storage.push_back(student);
    }

    sort(storage.begin(), storage.end());

    int flag = 0;
    for ( int i = 0; i < n; i++ ){
        if ( flag != 0 ){
            cout << endl;
        }else{
            flag = 1;
        }
        
        cout << i + 1 << storage[i];       
    }
}