class Solution {
public:
    int countPrimeSetBits(int L, int R)
    {
        int ans = 0;
        unordered_set<int> primes = { 2,3,5,7,11,13,17,19,23,29 };
        for (int i = L; i <= R; i++)
        {
            int t = i;
            int temp = 0;
            while (t) temp += t & 1, t >>= 1;
            ans += primes.count(temp);
        }
        return ans;
    }
};