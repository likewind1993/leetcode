class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        char cur = letters[0];
        int i = 1;
        while (cur <= target && i < letters.size())
            cur = letters[i++];
        if (cur <= target)
            return letters[0];
        return cur;
    }
};
