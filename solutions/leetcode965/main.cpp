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

    bool isSameValue(TreeNode* root, int value) {
        if (root == NULL)
            return true;
        if(root->val != value)
            return false;
        return isSameValue(root->left, value) && isSameValue(root->right, value);

    }
    bool isUnivalTree(TreeNode* root)
    {
        int value = root->val;
        return isSameValue(root->left, value) && isSameValue(root->right, value);
    }
};

int main() {
    Solution solution;
    TreeNode * root = solution.createTree();
    cout<<solution.isUnivalTree(root)<<endl;
    //solution.printTree(root);

    return 0;
}