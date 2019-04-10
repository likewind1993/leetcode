#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    char checkSuccess(vector<string>& board)
    {
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
            return board[0][0];
        if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
            return board[1][0];
        if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
            return board[2][0];
        if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
            return board[0][0];
        if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
            return board[0][1];
        if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
            return board[0][2];
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
            return board[0][0];
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
            return board[0][2];
        return 'N';
    }

    bool validTicTacToe(vector<string>& board)
    {
        int m = board.size(), n = board[0].size();
        int x_nums = 0, o_nums = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'X')
                    x_nums++;
                else if(board[i][j] == 'O')
                    o_nums++;
            }
        }
        if (!(x_nums == o_nums || x_nums == o_nums + 1)){
            return false;
        }
        char sign = checkSuccess(board);
        if(sign == 'N'){
            return true;
        }else if(sign == 'X'){
            if(x_nums == o_nums + 1)
                return true;
            else 
                return false;
        }else if(sign == 'O'){
            if(x_nums == o_nums)
                return true;
            else 
                return false;
        }
        return true;
    }
};