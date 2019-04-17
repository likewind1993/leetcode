class Solution {
public:
    void get_unique_permute(vector<int>& nums, vector<vector<int>>&ans, vector<bool>& is_visited,vector<int> temp, int count)
    {
        if(count == nums.size()) {
            ans.push_back(temp);
            return ;
        }

        for(int i = 0; i<nums.size(); ++i) {
            if(i != 0 && nums[i] == nums[i-1] && !is_visited[i-1])
                continue;
            if(!is_visited[i]) {
                is_visited[i] = true;
                temp.push_back(nums[i]);
                get_unique_permute(nums, ans, is_visited, temp, count + 1);
                is_visited[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        vector<bool>is_visited(nums.size(), false);
        get_unique_permute(nums, ans ,is_visited, temp, 0);
        return ans;
    }
};