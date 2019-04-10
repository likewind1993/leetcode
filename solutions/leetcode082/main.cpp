#include <iostream>
#include "../../list_op.hpp"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode * dummy = new ListNode(-1), *prev = NULL, *cur = NULL;
        bool is_dup = false;
        dummy->next = head;
        prev = dummy;
        cur = dummy->next;
        while(cur != NULL) {
            ListNode * next = cur->next;
            while (next != NULL && cur->val == next->val) {
                is_dup = true;
                cur->next = next->next;
                next = cur->next;
            }
            if(is_dup)
                prev->next = cur->next;
            else
                prev = cur;
            is_dup = false;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main()
{
    vector<int> a = {};
    ListNode * list = create_list(a);
    Solution solution;
    list = solution.deleteDuplicates(list);
    print_list(list);
    return 0;
}