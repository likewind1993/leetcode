#include <iostream>
#include <vector>
#include "../../list_op.hpp"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode * dummy = new ListNode(-1), * cur = NULL, * smaller = NULL, * greater = NULL, * small_head = NULL, * great_head = NULL;
        dummy->next = head;
        cur = dummy->next;
        while(cur != NULL) {
            if(cur->val < x) {
                if(smaller!= NULL)
                    smaller->next = cur;
                else {
                    small_head = cur;
                }
                smaller = cur;
                    
            }else {
                if(greater != NULL)
                    greater->next = cur;
                else { 
                    great_head = cur;
                }
                greater = cur;
            }
            cur = cur->next;
        }
        if(greater != NULL)
            greater->next = NULL;
        if(smaller != NULL)
            smaller->next = NULL;
        if(small_head != NULL) {
            dummy->next = small_head;
            smaller->next = great_head;
        }else
            dummy->next = great_head;
        return dummy->next;
    }
};

int main()
{
    vector<int> a = {};
    ListNode * list = create_list(a);
    Solution solution;
    list = solution.partition(list, 3);

    print_list(list);

    return 0;
}