#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int> nums)
{
    if (nums.empty())
        return NULL;

    ListNode * head, *ptr;
    ptr = new ListNode(-1);
    head = ptr;
    for (int i = 0; i < nums.size(); ++i) {
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }
    return head->next;
}
void printList(ListNode * list)
{
    while (list != NULL)
    {
        cout << list->val << endl;
        list = list->next;
    }
}

class Solution {
public:
    

    ListNode* reverseList(ListNode* head)
    {
        ListNode * cur_node = NULL, * next_node = head;
        while (next_node != NULL) {
            ListNode * temp = next_node->next;
            next_node->next = cur_node;
            cur_node = next_node;
            next_node = temp;
        }
        return cur_node;
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    
    Solution solution;

    ListNode * p = createList(a);

    printList(solution.reverseList(p));
}