#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;

    while ( cin >> n >> m ){    
        vector<int> food;
        vector<int> sum;

        for ( int i = 0; i < n; i++ ){
            int temp;
            cin >> temp;
            food.push_back(temp);

            if ( !sum.empty() ){
                sum.push_back(temp + sum.back());
            }else{
                sum.push_back(temp);
            }
        }

        for ( int i = 0; i < m; i++ ){
            int a, b;
            cin >> a >> b;
            
            cout << sum[b - 1] - sum[a - 1] + food[a - 1] << endl;
        }
    }
}