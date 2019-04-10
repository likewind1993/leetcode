#include <vector>
#include <iostream>
using namespace std;

class Solution {
    void scan(vector<vector<int>>board, vector<vector<int>>&res, int m, int n, int x, int y)
    {
        int count = 0;
        res[x][y] = board[x][y];
        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i < 0 || i >= m || j < 0 || j >= n || (i == x && j == y))
                    continue;
                if (board[i][j] == 1)
                    count++;
            }
        }
        if (board[x][y] == 1)
        {
            if (count < 2)
                res[x][y] = 0;
            else if (count > 3)
                res[x][y] = 0;
        }
        else
        {
            if (count == 3)
                res[x][y] = 1;
        }

    }
public:
    

    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scan(board, res, m, n, i, j);
            }
        }
        board = res;
    }
};
int main() {
    vector<vector<int>> board = { { 0,1,0 }, { 0,0,1 },{ 1,1,1 },{ 0,0,0 } };
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"---------"<<endl;
    Solution solution;
    solution.gameOfLife(board);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

