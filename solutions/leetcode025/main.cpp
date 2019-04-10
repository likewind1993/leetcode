#include <iostream>
#include <vector>
using namespace std;

//链表节点的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//给定vector数组，创建链表
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int count = 1;
        ListNode * dummy = new ListNode(-1), *pre = NULL, * cur = NULL, *p = NULL;
        dummy->next = head;
        pre = dummy;
        cur = dummy->next;
        p = cur;
        while(true) {
            for(int i = 0; i<k ;++i) {
                if(p == NULL)
                    return dummy->next;
                p = p->next;
            }
           
            for (int i = 0; i < k - 1; ++i)
            {
                ListNode * temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            cur = cur->next;
            p = cur;
        }
    }
};

int main()
{
    vector<int> a = { 1,2,3,4,5 };
    ListNode * list = create_list(a);
    Solution solution;
    list = solution.reverseKGroup(list, 2 );

    print_list(list);

    return 0;
}