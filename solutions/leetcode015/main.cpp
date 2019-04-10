#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 3)
            return ans;
        vector<bool> is_visited(n, false);
        
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, k = n-1;
        while(j < n && k >= 0) {
            if (nums[i] + nums[j] + nums[k] == 0) {
                if(!(is_visited[i] && is_visited[j] && is_visited[k] )) {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    is_visited[i] = true;
                    is_visited[j] = true;
                    is_visited[k] = true;
                }
                --k;
                ++i;
                ++j;
            }   
            else if (nums[i] + nums[j] + nums[k] > 0) {
                --k;
            }else {
                ++i;
                ++j;
            }

        }
        return ans;
    }
};
int main()
{
    vector<int> a = { 0, 0, 0, 0 };
    Solution solution;
    vector<vector<int>> res = solution.threeSum(a);

    for(auto iter : res) {
        for(auto num : iter) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}