#include <iostream>
#include <vector>
using namespace std;

int count;
vector<int> board;
vector<vector<int>> soultions;

vector<bool> col_used, diag1_used, diag2_used;

bool is_promising( int row, int col, int n ){
    if ( col_used[col] || diag1_used[row + col] || diag2_used[row - col + n - 1] ){
        return false;
    }

    return true;
}

void dfs( int row, int n ){
    if ( row == n ){
        count++;
        soultions.push_back(board);
        return;
    }

    for ( int col = 0; col < n; col++ ){
        if ( is_promising(row, col, n) ){
            board[row] = col;

            col_used[col] = true;
            diag1_used[row + col] = true;
            diag2_used[row - col + n - 1] = true;

            dfs(row + 1, n);

            col_used[col] = false;
            diag1_used[row + col] = false;
            diag2_used[row - col + n - 1] = false;
        }
    }
}

int main(){
    int n;
    while ( cin >> n && n != 0 ){
        count = 0;
        board.assign(n, -1);
        soultions.clear();

        col_used.assign(n, false);
        diag1_used.assign(2 * n - 1, false);
        diag2_used.assign(2 * n - 1, false);

        dfs(0, n);

        if ( count == 0 ){
            cout << endl << 0 << endl;
        }else{
            for ( int i = 0; i < count; i++ ){
                for ( int j = 0; j < n; j++ ){
                    for ( int k = 0; k < n; k++ ){
                        if ( k != soultions[i][j] ){
                            cout << "x";
                        }else{
                            cout << "Q";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << count << endl;
        }
    }
}