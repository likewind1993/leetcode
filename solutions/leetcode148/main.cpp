#include <iostream>
#include <vector>
#include <map>

using namespace std;
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
private:
    map<int, ListNode*> indexs;

public:
    int calcListIndex(ListNode* head) {
        int n = 0;
        while (head != NULL) {
            indexs[n] = head;
            head = head->next;
            ++n;
        }
        return n;
    }
    void mergeList(ListNode *head, int begin, int mid, int end) {
        ListNode *new_list = new ListNode(-1), *p = indexs[begin], *q = indexs[mid+1];
        ListNode *new_head = new_list;

        int count = end - begin + 1;
        while (count) {
            int min_val = 0;
            if (p->val < q->val) {
                min_val = p->val;
                p = p->next;
            }
            else {
                min_val = q->val;
                q = q->next;
            }
            new_list->next = new ListNode(min_val);
            new_list = new_list->next;
            --count;
        }
        

    }
    ListNode* sortListMC(ListNode *head, int begin, int end) {
        if (begin < end) {
            int mid = (begin + end) / 2;
            sortListMC(head, begin, mid);
            sortListMC(head, mid+1, end);
            mergeList(head, begin, mid, end);
        }
    }
    ListNode* sortList(ListNode *head)
    {
        int n = calcListIndex(head);
        sortListMC(head, 0, n-1);
        return head;
    }
};

int main() {
    vector<int> a = {4, 2, 1, 3};
    ListNode * list = create_list(a);
    Solution solution;




}