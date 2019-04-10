#include "../../list_op.hpp"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode * dummy = new ListNode(-1), * cur = NULL;
        dummy->next = head;
        cur = head;
        while(cur != NULL && cur->next != NULL) {
            ListNode * next = cur->next;
            while(next != NULL && cur->val == next->val) {
                next = next->next;
            }
            cur->next = next;
            cur = next;
        }
        return dummy->next;
    }
};

int main()
{
    vector<int> a = { };
    ListNode * list = create_list(a);
    Solution solution;
    list = solution.deleteDuplicates(list);
    print_list(list);
    return 0;
}