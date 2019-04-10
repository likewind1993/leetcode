class Solution {
public:
    void mergeSort(vector<int> & nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    void merge(vector<int> & nums, int left, int mid, int right) {
        vector<int>::iterator iter = nums.begin();
        vector<int>Left(iter + left, iter + mid + 1);
        vector<int>Right(iter + mid + 1, iter + right + 1);

        int i = 0, j = 0;
        while (i < Left.size() && j < Right.size()) {
            if (Left[i] > Right[j]) {
                nums[left++] = Right[j++];
            } else {
                nums[left++] = Left[i++];
            }
        }
        while (i < Left.size()) {
            nums[left++] = Left[i++];
        }
        while (j < Right.size()) {
            nums[left++] = Right[j++];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};