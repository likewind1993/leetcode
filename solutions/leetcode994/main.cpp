#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Rotting(vector<vector<int>>& grid, int m, int n, vector<int>& rotted_orange, int& num_freash_orange){
        vector<int> temp;
        for (auto iter : rotted_orange) {
            int i = iter / n, j = iter % n;
            if (i - 1 >= 0) {
                if(grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    temp.emplace_back((i-1)*n + j);
                    num_freash_orange--;
                }
            }
            if (i + 1 < m)
            {
                if (grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    temp.emplace_back((i + 1)*n + j);
                    num_freash_orange--;
                }
            }
            if (j - 1 >= 0)
            {
                if (grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                    temp.emplace_back(i*n + j-1);
                    num_freash_orange--;
                }
            }
            if (j+1 < n)
            {
                if (grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                    temp.emplace_back(i*n + j+1);
                    num_freash_orange--;
                }
            }
        }

        for(auto iter : temp)
            rotted_orange.emplace_back(iter);

        return rotted_orange.size();
    }

    int orangesRotting(vector<vector<int>>& grid)
    {
        vector<int> rotted_orange;
        int nums_fresh_orange = 0, iter =0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j] == 2)
                    rotted_orange.emplace_back(i*n + j);
                else if(grid[i][j] == 1)
                    ++nums_fresh_orange;
            }
        }
        int nums = rotted_orange.size();
        while (true) {
            if(nums_fresh_orange == 0)
                break;
            ++iter;
            int nums_rotted_orange = Rotting(grid, m, n, rotted_orange, nums_fresh_orange);
            if(nums >= nums_rotted_orange)
                break;
            nums = nums_rotted_orange;
        }
        return nums_fresh_orange == 0 ? iter : -1;
    }
};
//examples:
// grid = { {2,1,1},{1,1,0},{0,1,1} };
// grid = { {2, 1, 1},{0, 1, 1},{1, 0, 1} };
int main() {
    Solution solution;
    vector<vector<int>> grid = { {1, 2} };

    cout<<solution.orangesRotting(grid)<<endl;

    return 0;

}