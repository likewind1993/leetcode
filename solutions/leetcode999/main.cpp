#include<iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int caputure(vector<vector<char>>& board, vector<int> rook_pos)
    {
        int n = board.size(), ans = 0;

        int x = rook_pos[0], y = rook_pos[1];

        for (int i = 0; x + i < n; ++i)
        {
            char ch = board[x + i][y];
            if (ch == 'B')
                break;
            else if (ch == 'p')
            {
                ans++;
                break;
            }
        }
        for (int i = 0; x + i >= 0; --i)
        {
            char ch = board[x + i][y];
            if (ch == 'B')
                break;
            else if (ch == 'p')
            {
                ans++;
                break;
            }
        }
        for (int i = 0; y + i >= 0; --i)
        {
            char ch = board[x][y + i];
            if (ch == 'B')
                break;
            else if (ch == 'p')
            {
                ans++;
                break;
            }
        }
        for (int i = 0; y + i < n; ++i)
        {
            char ch = board[x][y + i];
            if (ch == 'B')
                break;
            else if (ch == 'p')
            {
                ans++;
                break;
            }
        }

        return ans;
    }

    int numRookCaptures(vector<vector<char>>& board)
    {
        int n = board.size(), m = board[0].size();
        vector<int> rook_pos;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == 'R')
                {
                    rook_pos.emplace_back(i);
                    rook_pos.emplace_back(j);
                    break;
                }
            }
        }
        return caputure(board, rook_pos);
    }
};


int main() {

    return 0;
}