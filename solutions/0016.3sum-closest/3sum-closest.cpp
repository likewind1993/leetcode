class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size(), ans = 0;
        if(n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n-2; ++i) {
            int j = i+1, k = n-1, sum = target - nums[i];
            if(i == 0)
                ans = nums[i] + nums[j] + nums[k];
            while(j < k) {
                if (abs(target - nums[i] - nums[j] - nums[k]) < abs(target - ans))
                    ans = nums[i] + nums[j] + nums[k];
                if(nums[j] + nums[k] == sum)
                    return target;
                else if(nums[j] + nums[k] <sum) {
                    ++j;
                }else {
                    --k;
                }
       
            }
        }
        return ans;
    }
};