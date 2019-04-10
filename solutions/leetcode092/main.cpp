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

    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = dummy->next;
        for (int i = 1; i < m; ++i) {
            pre = pre->next;
            cur = cur->next;
        }
        for (int i = 0; i < n - m; ++i) {
            ListNode * temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }

    
    ListNode* reverseBetween1(ListNode* head, int m, int n)
    {
        if (m == n)
            return head;

        ListNode *cur_node = head, *pre_node = NULL, *m_node = NULL;
        int i = 0;
        if (m == 1)
        {
            m_node = head;
            pre_node = NULL;
        }
        else
        {
            for (i = 1; i < m - 1; ++i)
            {
                cur_node = cur_node->next;
            }
            pre_node = cur_node;
            m_node = cur_node->next;
        }

        cur_node = m_node->next;
        ListNode *last_node = m_node, *temp = NULL;

        i = m + 1;
        while (i <= n)
        {
            temp = cur_node->next;
            cur_node->next = last_node;
            last_node = cur_node;
            cur_node = temp;
            ++i;
        }
        if (pre_node == NULL)
            head = last_node;
        else
            pre_node->next = last_node;
        m_node->next = cur_node;

        return head;
    }
};
int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    ListNode * p = create_list(a);

    Solution solution;
    print_list(solution.reverseBetween(p,1, 4 ));
}