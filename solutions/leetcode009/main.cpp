#include <iostream>
using namespace std;

//class Solution {
//public:
//    bool isPalindrome(int x)
//    {
//        if (x < 0 || (x % 10 == 0 && x != 0))
//        {
//            return false;
//        }
//        int reverseNumber = 0;
//        while (x > reverseNumber)
//        {
//            reverseNumber = reverseNumber * 10 + x % 10;
//            x /= 10;
//        }
//        return x == reverseNumber || x == reverseNumber / 10;
//    }
//};

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
            return false;
        int chars[12], i = 0, j = 0;
        while(x) {
            chars[i++] = x % 10;
            x = x / 10;
        }
        --i;
        while(j<=i) {
            if(chars[j++] != chars[i--])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout<<solution.isPalindrome(121)<<endl;
    return 0;
}