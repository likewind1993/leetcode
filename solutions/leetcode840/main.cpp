#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isMagicSquares(vector<vector<int>>& grid, int x, int y) {
        set<int> nums;
        for (int i = y; i < y + 3; i++) {
            for (int j = x; j < x + 3; j++) {
                int num = grid[i][j];
                if(num >=1 && num <=9 && nums.count(num) == 0)
                    nums.insert(num);
                else
                    return false;
            }
        }

        int sum1 = grid[y][x] +  grid[y + 2][x + 2];
        int sum2 = grid[y][x + 2] + grid[y + 2][x];
        return sum1 == sum2 ? true : false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int n = grid[0].size(), m = grid.size();
        if( n < 3 || m < 3) 
            return 0;
        int times = (n - 3 + 1) * (m - 3 + 1);
        int x = 0, y = 0, ans = 0;
        for (int i = 0; i < times; i++) {
            
            if(isMagicSquares(grid, x, y))
                ans++;
            if(x + 2 == n - 1){
                x=0;
                y++;
            }
            else {
                x++;
            }
        }
        return ans;
    }
};
//[[5, 2, 9, 5, 4], [8, 1, 6, 1, 4], [7, 2, 4, 7, 8], [1, 8, 3, 5, 9], [5, 7, 2, 6, 1]]
//[[5,4,7,8,5,4,6,8,2,9],[5,3,6,8,1,5,1,1,8,5],[8,9,6,8,4,7,3,4,9,1],[9,3,8,9,2,8,3,8,7,1],[1,1,1,7,3,3,9,1,8,7],[1,5,5,7,1,6,7,9,3,4],[2,3,3,8,8,1,1,6,5,7],[7,8,5,4,7,9,4,6,5,3],[8,5,2,7,1,3,7,2,8,9],[4,9,4,3,9,4,5,4,7,1]]
int main() {
    vector<vector<int>>grid = { { 5, 2, 9, 5, 4 }, { 8, 1, 6, 1, 4 }, { 7, 2, 4, 7, 8 }, { 1, 8, 3, 5, 9 },{ 5, 7, 2, 6, 1 } };
    Solution solution;
    cout<<solution.numMagicSquaresInside(grid)<<endl;

    return 0;


}