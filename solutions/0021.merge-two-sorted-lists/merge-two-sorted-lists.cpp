/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while (l1 && l2) {
            ListNode* temp;
            if (l1->val < l2->val) {
                temp = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                temp = new ListNode(l2->val);
                l2 = l2->next;
            }
            p->next = temp;
            p = p->next;
        }
        if (l1)
            p->next = l1;
        else
            p->next = l2;
        return head->next;
    }
};