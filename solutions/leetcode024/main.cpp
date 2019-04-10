#include <iostream>
#include <vector>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//����vector���飬��������
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
//��������ͷ��㣬��ӡ������ڵ�ֵ
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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode * dummy = new ListNode(-1), *pre = NULL, *cur = NULL;
        dummy->next = head;
        pre = dummy;
        cur = dummy->next;
        while(cur != NULL && cur->next != NULL) {
            ListNode * temp = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            pre->next = temp;

            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main()
{
    vector<int>a = {};
    ListNode * list = create_list(a);
    Solution solution;
    list = solution.swapPairs(list);
    print_list(list);

    return 0;
}