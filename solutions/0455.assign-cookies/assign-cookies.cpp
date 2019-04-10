class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<int>::iterator iter_g= g.begin(), iter_s = s.begin();
        while (iter_g != g.end() && iter_s != s.end()) {
            if (*iter_s >= *iter_g) {
                count++;
                iter_s++;
                iter_g++;
            }
            else {
                iter_s++;
            }
        }
        return count;

    }
};