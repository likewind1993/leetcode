#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int is_sec_normal(string str) {
        int n = str.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if(str[i] == '(')
                count++;
            else
                count--;
            if(count == 0)
                return i;
        }
        return -1;
    }
    int scoreOfParentheses(string S)
    {
        int sum = 0, n = S.size();
        if(S == "()")
            return 1;
        int split_point = is_sec_normal(S);
        if (split_point == n-1) {
            sum += 2 * scoreOfParentheses(S.substr(1, n - 2));
        }
        else {
            sum+= scoreOfParentheses(S.substr(0, split_point + 1)) + scoreOfParentheses(S.substr(split_point+1));
        }
        return sum;
    }
};