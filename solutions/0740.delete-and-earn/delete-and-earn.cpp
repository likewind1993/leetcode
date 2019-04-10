class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        map<int, int> digit_count;
        for (auto iter : nums) { digit_count[iter]++; }
        int used = 0, avoid = 0, prev = -1;
        for (auto cur : digit_count)
        {
            int m = max(used, avoid);
            if (cur.first - 1 != prev)
            {
                used = cur.first * cur.second + m;
                avoid = m;
            }
            else
            {
                used = cur.first * cur.second + avoid;
                avoid = m;
            }
            prev = cur.first;
        }
        return max(used, avoid);
    }
};