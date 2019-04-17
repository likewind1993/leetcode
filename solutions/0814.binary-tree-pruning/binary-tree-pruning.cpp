#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        if(root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL && root->val == 0) {
            return NULL;
        }
        if (pruneTree(root->left) == NULL) 
            root->left = NULL;
        if (pruneTree(root->right) == NULL)
            root->right = NULL;
        if (root->left == NULL && root->right == NULL && root->val == 0)
        {
            return NULL;
        }
        return root;    
    }
    TreeNode * createNode(int val)
    {
        TreeNode * node = new TreeNode(val);
        return node;
    }

    TreeNode * createTree() {
        int val = 0;
        cin>>val;
        if(val == -1) return NULL;

        TreeNode * root = new TreeNode(val);
        root->left = createTree();
        root->right = createTree();

        return root;
    }
    void print_tree(TreeNode * root) {
        if(root == NULL) return ;
        cout<<root->val<<" ";
        print_tree(root->left);
        print_tree(root->right);
    }
};