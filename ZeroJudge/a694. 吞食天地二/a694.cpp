#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;

    while ( cin >> n >> m ){
        vector<vector<int>> food;
        vector<vector<int>> sum;

        for ( int i = 0; i < n; i++ ){
            vector<int> vec_food;
            vector<int> vec_sum;

            for ( int j = 0; j < n; j++ ){
                int temp;
                cin >> temp;

                vec_food.push_back(temp);

                if ( !vec_sum.empty() ){
                    vec_sum.push_back(temp + vec_sum.back());
                }else{
                    vec_sum.push_back(temp);
                }
            }

            food.push_back(vec_food);
            sum.push_back(vec_sum);
        }

        for ( int i = 0; i < m; i++ ){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int total = 0;
            for ( int j = x1 - 1; j < x2; j++ ){
                total += sum[j][y2 - 1] - sum[j][y1 - 1] + food[j][y1 - 1];
            }
            cout << total << endl;
        }
    }
}