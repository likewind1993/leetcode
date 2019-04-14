void initMap(map<string, int>& strs)
{
    strs.insert(pair<string, int>("I", 1));
    strs.insert(pair<string, int>("IV", 4));
    strs.insert(pair<string, int>("V", 5));
    strs.insert(pair<string, int>("IX", 9));
    strs.insert(pair<string, int>("X", 10));
    strs.insert(pair<string, int>("XL", 40));
    strs.insert(pair<string, int>("L", 50));
    strs.insert(pair<string, int>("XC", 90));
    strs.insert(pair<string, int>("C", 100));
    strs.insert(pair<string, int>("CD", 400));
    strs.insert(pair<string, int>("D", 500));
    strs.insert(pair<string, int>("CM",900));
    strs.insert(pair<string, int>("M", 1000));
}

int find_roman(map<string, int>& strs, string str)
{
    for(auto iter : strs) {
        if( iter.first == str)
            return iter.second;
    }
    return 0;
}


class Solution {
public:
    int romanToInt(string s)
    {
        map<string, int> strs;
        initMap(strs);
        int i = s.size() - 1, ans = 0;
        while (i >= 0) {
            if(i - 1 >= 0 && find_roman(strs, s.substr(i - 1, 2)) != 0) {
                ans += find_roman(strs, s.substr(i-1, 2));
                i -= 2;
            }else {
                ans += find_roman(strs, s.substr(i, 1));
                i -= 1;
            }
        }
        return ans;
    }
};