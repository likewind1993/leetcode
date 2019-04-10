#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> m_stack;
        int n = pushed.size();
        int i = 1, j = 0;
        if (n == 0)
            return true;
        if (n == 1) {
            if(popped[0] == pushed[0])
                return true;
            else
                return false;
        }
        m_stack.push(pushed[0]);
        
        while (!m_stack.empty() || i<n) {
            if (j == n)
                break;
            if (m_stack.empty() && i < n) {
                m_stack.push(pushed[i]);
                i++;
            }
            else if (m_stack.top() != popped[j] && i < n) {
                m_stack.push(pushed[i]);
                ++i;
            }
            else if (m_stack.top() != popped[j] && i == n) {
                break;
            }
            else if (m_stack.top() == popped[j]) {
                m_stack.pop();
                ++j;
            }
        }
        return (m_stack.empty() && i== n && j == n) ? true : false;
    }
};
//examples:
//1, 2, 3, 4, 5    4,3,5,1,2
//1, 2, 3, 4, 5    4,5,3,2,1
//[4,0,1,2,3]
//[4, 2, 3, 0, 1]
//
int main() {
    vector<int> pushed = { 1, 2, 3, 4, 5 };
    vector<int> poped = { 4,5,3,2,1 };

    Solution solution;
    cout<<solution.validateStackSequences(pushed, poped)<<endl;

    return 0;
}