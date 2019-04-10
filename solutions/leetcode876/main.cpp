/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    
public:
    ListNode* middleNode(ListNode* head)
    {
        int count = 1;
        int mid = 1;
        ListNode * middle = head;
        while (head->next != NULL) { 
            head = head->next;
            count++;
            if (count / 2 + 1 > mid) {
                mid ++;
                middle = middle->next;
            }
        }
        return middle;
    }
    ListNode* createList()
    {
        int input;
        cin >> input;
        ListNode * head = new ListNode(input);
        ListNode * next = head;
        cin >> input;
        while (input != -1)
        {
            ListNode * node = new ListNode(input);
            head->next = node;
            head = head->next;
            cin >> input;
        }
        return next;
    }
    void printList(ListNode * head) {
        while (head != NULL) {
            cout <<head->val<<" ";
            head = head->next;
        }
        cout<<endl;

    }
};
int main() {
    Solution solution;
    ListNode * head = solution.createList();
    solution.printList(head);
    solution.printList(solution.middleNode(head));
    return 0;

}