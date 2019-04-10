#include <vector>
#include <iostream>
using namespace std;
/**
* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct NewTreeNode {
    int val;
    bool visited;
    NewTreeNode * from;
    NewTreeNode *left;
    NewTreeNode *right;
    NewTreeNode(int x) : val(x), visited(false), left(NULL), right(NULL), from(NULL) {}
};


class Solution {
private:
    NewTreeNode * new_target;
public:
    TreeNode * createNode(int val)
    {
        TreeNode * node = new TreeNode(val);
        return node;
    }

    TreeNode * createTree()
    {
        int val = 0;
        cin >> val;
        if (val == -1) return NULL;

        TreeNode * root = new TreeNode(val);
        root->left = createTree();
        root->right = createTree();

        return root;
    }
    void print_tree(TreeNode * root)
    {
        if (root == NULL) return;
        cout << root->val << " ";
        print_tree(root->left);
        print_tree(root->right);
    }

    void visitedTree(TreeNode * root, TreeNode * target, NewTreeNode * curNode) {
        if (root->left != NULL) {

            NewTreeNode * left_child = new NewTreeNode(root->left->val);
            left_child->from = curNode;
            left_child->left = NULL;
            left_child->right = NULL;

            if (root->left->val == target->val)
                new_target = curNode->left;

            curNode->left = left_child;
            visitedTree(root->left, target, left_child);
        }
        if (root->right != NULL) {
            NewTreeNode * right_child = new NewTreeNode(root->right->val);
            right_child->from = curNode;
            right_child->left = NULL;
            right_child->right = NULL;

            if (root->right->val == target->val)
                new_target = curNode->right;

            curNode->right = right_child;
            visitedTree(root->right, target, right_child);
        }
    }

    vector<int> findNode(NewTreeNode * curNode, int count, int K, vector<int> & ans) {
        if(count == K && curNode->visited == false)
            ans.push_back(curNode->val);
        curNode->visited = true;
        findNode(curNode->from, count++, K, ans);
        findNode(curNode->left, count++, K, ans);
        findNode(curNode->right, count++, K, ans);

        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        NewTreeNode * new_root = new NewTreeNode(root->val);
        visitedTree(root, target, new_root);
        vector<int> ans;
        if (new_target != NULL) {
            ans = findNode(new_target, 0, K, ans);
        }

        return ans;        
    }
};

int main() {
    //3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1
    Solution solution;
    TreeNode * root = solution.createTree();
    solution.print_tree(root);

    return 0;
}