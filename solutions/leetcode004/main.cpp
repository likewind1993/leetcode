#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findKthNum(vector<int> &nums1, int begin1, int end1,
        vector<int> &nums2, int begin2, int end2, int k)
    {
        
        if (k == 0) {
            return begin1 == end1 ? nums1[begin1] : nums2[begin2];
        }
        int p1 = 0, p2 = 0;
        if (begin1 <= end1) {
            p1 = (begin1 + end1) / 2;
        }else 
            p1 = 
        if (begin2 < end2) {
            p2 = (begin2 + end2) / 2;
        }
        if (nums1[p1] < nums2[p2])
        {
            return findKthNum(nums1, p1, end1, nums2, begin2, p2, k - (end2 - p2));
        }else{
            return findKthNum(nums1, begin1, p1, nums2, p2, end2, k- (end1 - p1));
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size() + nums2.size(); 
        if (n % 2 == 1) {
            return findKthNum(nums1, 0, nums1.size()-1, nums2, 0, nums2.size() - 1, n / 2 + 1, 0);
        }
        else {
            return (findKthNum(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, n / 2, 0) + 
                findKthNum(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, n / 2 + 1, 0)) / 2;
        }
    }
};

int main() {
    Solution solution;
    vector<int> a = {};
    //cout<<solution.findMedianArray(a, 0, a.size() - 1);

    return 0;
}