#include <iostream>
#include <stack>
#include <vector>
#include "../../list_op.hpp"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL)
            return NULL;
        int count = 1;
        stack<ListNode * > s;
        ListNode * dummy = new ListNode(-1), * tail = NULL, * prev = NULL;
        dummy->next = head;
        tail = head;
        while (tail->next != NULL) {
            s.push(tail);
            tail = tail->next;
            count ++;
        }
        k = k % count;
        for(int i = 0; i<k; ++i) {
            prev = s.top();
            prev->next = tail->next;
            tail->next = dummy->next;
            dummy->next = tail;
            tail = prev;
            s.pop();
        }
        return dummy->next;
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5};
    ListNode * list = create_list(a);
    Solution solution;
    list = solution.rotateRight(list, 7);
    print_list(list);

    return 0;
}