struct coord
{
    int x;
    int y;
    coord(int x_, int y_) : x(x_), y(y_) {};
};

class Solution {
public:
    bool check_row(vector<vector<char>>& board, coord & c)
    {
        vector<int>row(10, 0);
        for (int i = 0; i < 9; ++i)
        {
            char cur_char = board[c.x][i];
            if(cur_char != '.') {
                if(row[cur_char - '0'] == 0)
                    row[cur_char - '0'] += 1;
                else
                    return false;
            }
        }
        return true;
    }
    bool check_col(vector<vector<char>>& board, coord & c)
    {
        vector<int>col(10, 0);
        for (int i = 0; i < 9; ++i)
        {
            char cur_char = board[i][c.y];
            if (cur_char != '.')
            {
                if (col[cur_char - '0'] == 0)
                    col[cur_char - '0'] += 1;
                else
                    return false;
            }
        }
        return true;
    }

    bool check_square(vector<vector<char>>& board, coord & c)
    {
        vector<int> square(10, 0);
        int x = c.x - c.x % 3, y = c.y - c.y % 3;
        for (int i = x; i < x+3; ++i)
        {
            for (int j = y; j < y+3; ++j)
            {
                int cur_char = board[i][j];
                if (cur_char != '.')
                {
                    if (square[cur_char - '0'] == 0)
                        square[cur_char - '0'] += 1;
                    else
                        return false;
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char>>& board, coord & c)
    {
        return check_row(board, c) && check_col(board, c) && check_square(board, c);
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<coord> to_check;
        for(int i = 0; i<9; ++i) {
            for(int j = 0; j<9; ++j) {
                if (board[i][j] != '.')
                    to_check.push_back(coord(i, j));
            }
        }
        for(auto c : to_check) {
            if(!check(board, c))
                return false;
        }
        return true;
    }
};
