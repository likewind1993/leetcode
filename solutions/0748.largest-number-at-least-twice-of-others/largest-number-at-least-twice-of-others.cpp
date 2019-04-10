class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        int index = 0, max_value = nums[0], second_value = nums[0]; 
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max_value)
            {
                index = i;
                max_value = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (second_value == max_value)
                second_value = nums[i];
            if (nums[i] < max_value && second_value < nums[i])
                second_value = nums[i];
        }
        if (max_value >= second_value * 2)
            return index;
        return -1;

    }
};