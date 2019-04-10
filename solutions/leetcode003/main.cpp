#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s)
    {
        const int n = s.size();
        set<char> set_;
        //vector<vector<int>> dp(n+1, vector<int>(n+1));

        auto ans = 0;
        int i = 0, j = 0;
        while(i < n && j < n)
        {
            if(set_.find(s[j]) == set_.end())
            {
                set_.insert(s[j++]);
                ans = max(ans, j - i);
            }else
            {
                set_.erase(set_.find(s[i++]));
            }

        }
        return ans;
    }
    int lengthOfLongestSubstring(string s)
    {
        const int n = s.size();
        unordered_map<char, int> map_;

        int ans = 0;
        for(int j = 0, i = 0; j<n; ++j)
        {
            if(map_[s[j]] != 0)
                i = max(map_[s[j]], i);
            ans = max(ans, j - i + 1);
            map_[s[j]]= j+1;
        }
        return ans;
    }

};

int main() {
    
    Solution solution;
    cout<<solution.lengthOfLongestSubstring("aab")<<endl;

    return 0;
}