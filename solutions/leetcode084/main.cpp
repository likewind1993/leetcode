#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size(); 
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            stack<int> s;
            int length = 0, height = heights[i], left = 0, right = 0;
            for (int j = 0; j <= i; ++j)
            {
                while (!s.empty() && heights[s.top()] < heights[j])
                    s.pop();
                s.push(j);
            }
            s.pop();
            if(!s.empty())
                left = s.top();
            else
                left = -1;
            while(!s.empty())
                s.pop();
            for (int j = n - 1; j >= i; --j) {
                while(!s.empty() && heights[s.top()] < heights[j])
                    s.pop();
                s.push(j);
            }
            s.pop();
            if(!s.empty())
                right = s.top();
            else
                right = n;
            cout<<left<<" "<<right<<endl;
            length = (right - left -1) * height;
            ans = max(length, ans);
        }
        return ans;
    }
    
};

int main() {
    vector<int> heights = { 2,1,5,6,2,3 };
    Solution solution;
    cout<<solution.largestRectangleArea(heights)<<endl;

    return 0;

}