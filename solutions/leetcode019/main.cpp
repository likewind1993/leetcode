#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * create_list(vector<int> nums)
{
    if (nums.size() == 0)
        return NULL;

    int n = nums.size();
    ListNode * p, *head_node;
    head_node = new ListNode(nums[0]);
    p = head_node;
    for (int i = 1; i < n; ++i)
    {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head_node;
}
//给定链表头结点，打印该链表节点值
void print_list(ListNode * p)
{
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(n == 0 || head == NULL)
            return head;
        ListNode * t = new ListNode(0);
        t->next = head;
        ListNode * p = t, * q = t;
        int count = 0;
        while(p != NULL) {
            if(count > n) {
                q = q->next;
            }
            p = p->next;
            count++;
        }
        q->next = q->next->next;
        return t->next;
    }
};

int main()
{
    vector<int> a = { 1,2 };
    ListNode * list = create_list(a);

    Solution solution;
    print_list(solution.removeNthFromEnd(list, 2));

    return 0;
}
