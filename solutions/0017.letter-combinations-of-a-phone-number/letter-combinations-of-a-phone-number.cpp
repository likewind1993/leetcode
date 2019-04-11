class Solution {
private:
    vector<string> letters;
public:
    void dfs(vector<string> &ans, string str, string digits)
    {
        if (digits.size() == 0) {
            ans.push_back(str);
            return ;
        }
        int n = digits.size();
        int letters_no = digits[0] - '0';
        for(int i = 0; i<letters[letters_no].size(); ++i)    
            dfs(ans, str + letters[letters_no][i],digits.substr(1, n-1));
    }
    

    vector<string> letterCombinations(string digits)
    {
        letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        dfs(ans, "" ,digits);
        return ans;
    }
};