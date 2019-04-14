class Solution {
public:
    string count(string last_str)
    {
        int p = 0, count = 0;
        string ans = "";
        while(p<last_str.size()) {
            char temp = last_str[p];
            count = 1;
            while( p+1 < last_str.size() && last_str[p] == last_str[p+1]) {
                count++;
                p++;
            }
            p++;
            ans += '0'+count;
            ans += temp;
        }
        return ans;
    }

    string countAndSay(int n)
    {
        vector<string> strs(n+1);
        strs[1] = "1";
        for(int i = 2; i<=n; ++i) {
            strs[i] = count(strs[i-1]);
        }
        return strs[n];
    }
};