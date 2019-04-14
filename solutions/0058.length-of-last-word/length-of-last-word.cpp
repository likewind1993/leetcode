class Solution {
public:
    int lengthOfLastWord(string s)
    {
        string last_word = "";
        int n = s.size(), i = n - 1;
        while(i>=0) {
            if(s[i] == ' ' && last_word != "")
                break;
            if(s[i] != ' ')
                last_word = s[i] + last_word;
            --i;
        }
        return last_word.size();
    }
};