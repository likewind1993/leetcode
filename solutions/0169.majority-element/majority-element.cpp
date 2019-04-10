class Solution {
 public:
    int majorityElement(const std::vector<int> & nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(const std::vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];
        int mid = (left + right ) / 2;
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm)
            return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
};