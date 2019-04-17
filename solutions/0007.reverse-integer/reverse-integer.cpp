class Solution {
public:
    int reverse(int x)
    {
        int chars [32], i = 0;
        long long x_positive = 0, ans = 0;
        bool is_positive = false;
        if(x >=0 )
            is_positive = true;
        x_positive = x;
        x_positive = abs(x_positive);
        while(x_positive) {
            chars[i++] = x_positive % 10;
            x_positive = x_positive / 10;
        }
        --i;
        for(int j = 0; i>=0; --i, ++j) {
            ans += pow(10, i) * chars[j];
        }
        if(ans > 0x7fffffff)
            return 0;
        if(!is_positive)
            ans = ans * -1;
        return ans;
    }
};