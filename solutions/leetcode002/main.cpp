#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* createList(vector<int> nums) {
        if(nums.empty())
            return NULL;

        ListNode * head, * ptr;
        for (int i = 0; i < nums.size(); ++i) {
            ListNode * temp = new ListNode(nums[i]);
            if (i == 0) {
                head = temp;
                ptr =temp;
                continue;
            }
            ptr->next = temp;
            ptr = temp;
        }
        return head;
    }
    void printList(ListNode * list) {
        while (list != NULL) {
            cout<<list->val<<endl;
            list = list->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int sum  = 0;
        vector<int> res;
        while (l1 != NULL && l2 != NULL) {
            int a = l1->val, b = l2->val;
            sum = sum + a + b;
            res.push_back(sum % 10);
            sum = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL)
        {
            sum += l1->val;
            res.push_back(sum % 10);
            sum = sum / 10;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            sum += l2->val;
            res.push_back(sum % 10);
            sum = sum / 10;
            l2 = l2->next;
        }
        if (sum != 0)
            res.push_back(sum);

        return createList(res);
    }
};

int main() {
    vector<int> a = {9, 9};
    vector<int> b = {9, 9, 9};
    Solution solution;

    ListNode * l1 = solution.createList(a);
    ListNode * l2 = solution.createList(b);

    solution.printList(solution.addTwoNumbers(l1, l2));

    return 0;
}