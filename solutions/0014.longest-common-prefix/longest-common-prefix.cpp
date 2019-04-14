class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = "";
        if(strs.size() == 0)
            return ans;
        for(int i = 0; i<strs[0].size(); ++i) {
            char cur_char = '\0';
            int j = 0;
            for(j = 0; j<strs.size(); ++j) {
                if(i < strs[j].size() && j == 0)
                    cur_char = strs[j][i];
                if(i >= strs[j].size() || cur_char != strs[j][i])
                    break;
            }
            if(cur_char != '\0' && j == strs.size())
                ans += cur_char;
            else
                break;
        }
        return ans;
    }
};