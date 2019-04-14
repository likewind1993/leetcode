class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        if(nums.size() == 0)
            return ans;
        sort(nums.begin(), nums.end());
        int n =nums.size();
        for(int i = 0; i<n-3; ++i) {
            if(i == 0 || i>0 && nums[i] != nums[i-1]) {
                for (int j = i + 1; j < n - 2; ++j)
                {
                    if (j == i+1 || j > i+1 && nums[j] != nums[j - 1])
                    {
                        int l = j + 1, r = n - 1, sum = target - nums[i] - nums[j];
                        while (l < r)
                        {
                            if (nums[l] + nums[r] == sum)
                            {
                                ans.push_back(vector<int> {nums[i], nums[j], nums[l], nums[r]});
                                while (l < r && nums[r] == nums[r - 1]) --r;
                                while (l < r && nums[l] == nums[l + 1]) ++l;
                                --r;
                                ++l;
                            }
                            else if (nums[l] + nums[r] < sum)
                            {
                                while (l < r && nums[l] == nums[l + 1]) ++l;
                                l++;
                            }
                            else
                            {    
                                while (l < r && nums[r] == nums[r - 1]) --r;
                                r--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};