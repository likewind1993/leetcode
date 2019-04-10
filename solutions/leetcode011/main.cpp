#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int i = 0, j = n - 1, ans = 0;

        while(i < j) {
            ans = max(ans, min(height[i], height[j]) * (j-i));
            if(height[i] < height[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};
int main()
{
    vector<int> a = { 1,8,6,2,5,4,8,3,7 };
    Solution solution;

    cout<<solution.maxArea(a)<<endl;
    return 0;
}
