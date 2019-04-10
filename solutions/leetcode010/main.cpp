#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int i = 0, j = 0;
        char prev = '\0';
        while(i < s.size() && j < p.size()) {
            if(p[j] == '.') {
                ++j;
                ++i;
                continue;
            }else if(p[j] == '*') {
                prev = p[j-1];
                if(prev == '.')
                    prev = s[i];

                while(i< s.size() && s[i] == prev)
                    i += 1;
                ++j;
                continue;
            }
            if(p[j] != s[i]) {
                if(j+1 <p.size() && p[j+1] == '*')
                    ++j;
                else
                    return false;
                j+=2;
            }else {
                ++i;
                ++j;
            }

        }
        return i == s.size() && j == p.size() ? true : false;
    }
};

int main()
{
    Solution solution;
    string s = "aaa";
    string p = "a*a";

    cout<<solution.isMatch(s ,p)<<endl;

    return 0;
}