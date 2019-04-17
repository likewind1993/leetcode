class Solution {
private:
    void get_permute(vector<vector<int>> & ans, vector<int>& nums, vector<bool>& is_visited, vector<int> temp, int count)
    {
        if(count == nums.size()) {
            ans.push_back(temp);
            return ;
        }
        for(int i = 0; i<nums.size(); ++i) {
            if(!is_visited[i]) {
                is_visited[i] = true;
                temp.push_back(nums[i]);
                get_permute(ans, nums, is_visited, temp, count + 1);
                temp.pop_back();
                is_visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int> temp;
        vector<bool> is_visited(nums.size(), false);
        get_permute(ans, nums, is_visited, temp, 0);
        return ans;
    }
};
