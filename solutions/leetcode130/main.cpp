#include <vector>
#include <iostream>
using namespace std;

class Solution {

private:
    vector<bool> flag;
    void dfs(vector<vector<char>> board, vector<bool>&flag, int m, int n, int x, int y) {
        int up = y-1, left = x-1, right = x+1, down = y+1;
        
        if (board[y][x] != 'O') 
            return ;
        if (flag[y*m + x] == true)
            return ;
        flag[y*m + x] = true;
        if(up >= 0)
            dfs(board, flag, m, n, x, up);
        if(left >= 0)
            dfs(board, flag, m, n, left, y);
        if(right < m)
            dfs(board, flag, m, n, right, y);
        if(down <n)
            dfs(board, flag, m, n, x, down);
        
    }

public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = 0; 
        if (n > 0)
            m = board[0].size();
        if (n <= 2 || m <= 2)
            return ;
        vector<vector<int>> coords; 
        flag.resize(m*n);

        for (int j = 0; j < m; ++j) 
            if(board[0][j] == 'O')
                coords.push_back({0, j});
        for (int j = 0; j < m; ++j)
            if (board[n-1][j] == 'O')
                coords.push_back({ n-1, j });
        for (int i = 0; i < n; ++i)
            if (board[i][0] == 'O')
                coords.push_back({ i, 0 });
        for (int i = 0; i<n; ++i)
            if(board[i][m-1] == 'O')
                coords.push_back({i, m-1});

        for (auto coord : coords) {
            dfs(board, flag, m, n, coord[1], coord[0]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(board[i][j] == 'O' && flag[i*n + j] == false)
                    board[i][j] = 'X';
            }
        }
    }
};
//examples:
//vector<vector<char>> board = { { 'O', 'O', 'O'},{ 'O', 'O', 'O'},{ 'O', 'O', 'O'} };
int main() {
    vector<vector<char>> board = { { 'O', 'O', 'O' },{ 'O', 'O', 'O' },{ 'O', 'O', 'O' } };
    
    Solution solution;
    solution.solve(board);

    for (auto line : board) {
        for(auto single : line)
            cout<<single<<" ";
        cout<<endl;
    }

    return 0;
};

