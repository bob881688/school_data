#include <iostream>
#include <algorithm>
using namespace std;

struct person
{
    string name;
    int height, smart, hold, strength, fast, god;
    int total;
};

bool cmp( person a, person b ){
    if ( a.total != b.total ){
        return a.total > b.total;
    }

    return true;
}


int main(){
    int n;
    cin >> n;

    person *people = new person[n];
    for ( int i = 0; i < n; i++ ){
        cin >> people[i].name >> people[i].height >> people[i].smart >> people[i].hold >> people[i].strength >> people[i].fast >> people[i].god;
        people[i].total = 1000 + (people[i].height - 170) * 100 + (people[i].smart + people[i].hold + people[i].strength + people[i].fast + people[i].god) * 20;
    }

    sort(people, people + n, cmp);

    for ( int i = 0; i < n; i++ ){
        cout << people[i].name << endl;
    }
}