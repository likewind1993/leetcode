#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * createTree()
{
    int val = 0;
    cin >> val;
    TreeNode * root = NULL;
    if (val != -1)
    {
        root = new TreeNode(val);
        root->left = createTree();
        root->right = createTree();
    }

    return root;
}
void printTree(TreeNode * root)
{
    if (root == NULL)
        return;
    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}


class Solution {
public:

    void get_longest_path(TreeNode* root, int cur_val, int& res) {
        if (root == NULL) {
            res = 0;
            return ;
        }
        if(root->left != NULL)
            if(root->val == root->left->val)
                res += 1;
    }

    int longestUnivaluePath(TreeNode* root)
    {

    }
};

int main() {

}