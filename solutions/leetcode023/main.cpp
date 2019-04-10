#include <algorithm>
#include <iostream>
#include <vector>
#include <xfunctional>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * create_list(vector<int> nums) {
    if(nums.size() == 0)
        return NULL;

    int n = nums.size();
    ListNode * p, * head_node;
    head_node = new ListNode(nums[0]);
    p = head_node;
    for (int i = 1; i < n; ++i) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head_node; 
}

void print_list(ListNode * p) {
    while (p != NULL) {
        cout<< p->val<<" ";
        p = p->next;
    }
}
#define LEFT(i) 2 * i + 1;
#define RIGHT(i) 2 * i + 2;

void exchange(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void min_heapify(vector<int> &arr, int i, int heap_size) {
    int left = LEFT(i);
    int right = RIGHT(i);
    int min_val = 0;
    if(left < heap_size && arr[left] < arr[i])
        min_val = left;
    else
        min_val = i;
    if (right < heap_size && arr[right] < arr[min_val])
        min_val = right;
    if (min_val != i) {
        exchange(arr, i, min_val);
        min_heapify(arr, min_val, heap_size);
    }
}

void build_min_heap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2; i >= 0; --i) {
        min_heapify(arr, i, n);
    }
}
void insert_min_heap(vector<int> &arr, int val) {
    
}
void sort_min_heap(vector<int> &arr) {
    build_min_heap(arr);
    int n = arr.size(), heap_size = arr.size();
    for (int i = n - 1; i >= 1; --i) {
        exchange(arr, 0, i);
        heap_size--;
        min_heapify(arr, 0, heap_size);
    }
}


class Solution {
public:

    void merge(vector<ListNode*> &lists, int l, int m, int r) {

        ListNode *p = lists[l], *q = lists[m+1];
        ListNode *new_list = NULL, *head = NULL;

        if (q == NULL) return ;

        if (p == NULL) {
            lists[l] = q;
            return ;
        }

        new_list = new ListNode(-1);
        head = new_list;

        while (p != NULL && q != NULL)
        {
            if (q->val < p->val)
            {
                new_list->next = new ListNode(q->val);
                q = q->next;
            }
            else
            {
                new_list->next = new ListNode(p->val);
                p = p->next;
            }
            new_list = new_list->next;
        }

        if(p == NULL)
            new_list->next = q;
        if(q == NULL)
            new_list->next = p;
        lists[l] = head->next;
    }

    void divide_conquer(vector<ListNode*> &lists, int l, int r) {
        if (l < r) {
            int m = (l+r)/2;
            divide_conquer(lists, l, m);
            divide_conquer(lists, m+1, r);
            merge(lists, l, m, r);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
            return NULL;
        divide_conquer(lists, 0, lists.size() - 1);
        return lists[0];
    }
};


int main() {
    /*vector<int> a = { 1, 4, 5};
    vector<int> b = { 1, 3, 4};
    vector<int> c = { 2, 6};*/


    vector<int> a = { 1, 2 ,3, 4 ,5, 6 };
    vector<int> b = { 1, 1, 2,2 ,3, 4 , 4,5, 6 };
    vector<int> c = { 1, 2 ,3, 4 ,5, 6 };

    vector<ListNode*> lists = {create_list(a), create_list(b), create_list(c)};
    Solution solution;

    ListNode *temp = solution.mergeKLists(lists);
    print_list(temp);
    return 0;
}