/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode * createTree() {
        int val = 0;
        cin >> val;
        TreeNode * root = NULL;
        if (val != -1) {
            root = new TreeNode(val);
            root->left = createTree();
            root->right = createTree();
        }
        
        return root;
    }
    void printTree(TreeNode * root) {
        if(root == NULL)
            return ;
        cout<<root->val<<endl;
        printTree(root->left);
        printTree(root->right);
    }
    int dfsOfTree(TreeNode * root, int L, int R) {
        int ans = 0;
        if(root == NULL)
            return ans;
        if (root->val >= L && root->val <= R) 
            ans += root->val;
        
        ans += dfsOfTree(root->left, L, R);
        ans += dfsOfTree(root->right, L, R);

        return ans;
    }

    int rangeSumBST(TreeNode* root, int L, int R)
    {
        return dfsOfTree(root, L, R);
    }
};
//create Tree examples:
//10 5 3 -1 -1 7 -1 -1 15 -1 18 -1 -1
//10 5 3 1 -1 -1 -1 7 6 -1 -1 -1 15 13 -1 -1 18 -1 -1
int main() {
    Solution solution;
    TreeNode * root = solution.createTree();
    cout<<solution.rangeSumBST(root, 6, 10)<<endl;

    return 0;
}