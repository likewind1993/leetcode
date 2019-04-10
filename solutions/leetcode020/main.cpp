#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        if(s.size() == 0)
            return false;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i<s.size(); ++i) {
            char top = '\0';
            if(!st.empty())
                top = st.top();
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                continue;
            }

            if(s[i] == ']' && top == '[') {
                st.pop();
            }else if(s[i] == ')' && top == '(') {
                st.pop();
            }else if(s[i] == '}' && top == '{') {
                st.pop();
            }else {
                return false;
            }
        }
        return st.empty() ? true : false;
    }
};

int main()
{
    Solution solution;
    cout<<solution.isValid(")")<<endl;
    return 0;

}