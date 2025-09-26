// 未完成
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int ans[101][101] = {0};
bool finish = false;

void bfs( int x, int y, const vector<vector<char>> &matrix ){
    vector<vector<bool>> visited(100, vector<bool>(100, false));
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<pair<int, int>> q;
    q.emplace(x, y);

    ans[x][y] = 1;

    while ( !q.empty() ){

        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        visited[now_x][now_y] = true;

        if ( now_x == n - 2 && now_y == n - 2 ){
            finish = true;
            return;
        }

        for ( int i = 0; i < 4; i++ ){
            int next_x = now_x + dir[i][0];
            int next_y = now_y + dir[i][1];
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && matrix[next_x][next_y] == '.' && !visited[next_x][next_y] ){
                q.emplace(next_x, next_y);
                ans[next_x][next_y] = ans[now_x][now_y] + 1;
            }
        }


    }
}


int main(){
    cin >> n;
    
    vector<vector<char>> matrix(n, vector<char> (n));
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            cin >> matrix[i][j];
        }
    }

    bfs(1, 1, matrix);

    if ( !finish ){
        cout << "No solution!" << endl;
    }else{
        cout << ans[n - 2][n - 2] << endl;
    }
}