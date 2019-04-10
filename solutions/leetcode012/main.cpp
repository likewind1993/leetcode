#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    void initMap(map<int, string> &strs)
    {
        strs.insert(pair<int, string>(1, "I"));
        strs.insert(pair<int, string>(4, "IV"));
        strs.insert(pair<int, string>(5, "V"));
        strs.insert(pair<int, string>(9, "IX"));
        strs.insert(pair<int, string>(10, "X"));
        strs.insert(pair<int, string>(40, "XL"));
        strs.insert(pair<int, string>(50, "L"));
        strs.insert(pair<int, string>(90, "XC"));
        strs.insert(pair<int, string>(100, "C"));
        strs.insert(pair<int, string>(400, "CD"));
        strs.insert(pair<int, string>(500, "D"));
        strs.insert(pair<int, string>(900, "CM"));
        strs.insert(pair<int, string>(1000, "M"));
    }

    string intoRomanRe(map<int, string> strs, int num)
    {
        string str = "";
        if(num == 0)
            return str;
        map<int,string>::iterator iter = strs.end();
        int times = 0, remain = 0;
        while(--iter != strs.begin()) {
            if (num >= iter->first) {
                times = num / iter->first;
                remain = num % iter->first;
                break;
            }  
        }
        if(iter == strs.begin()) {
            times = num / iter->first;
            remain = num % iter->first;
        }
            
        for(int i = 0; i<times; ++i)
            str += iter->second;

        str += intoRomanRe(strs, remain);
        return str;
    }

    string intToRoman(int num)
    {
        string str = "";
        map<int, string> strs;
        initMap(strs);
        
        str = intoRomanRe(strs, num);
        return str;

    }
};
int main()
{
    Solution solution;
    cout<<solution.intToRoman(1994)<<endl;
    return 0;
}