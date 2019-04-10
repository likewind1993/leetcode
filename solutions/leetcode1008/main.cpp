#include <iostream>
#include <vector>
using namespace std;

//树节点的定义以及创建
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
    TreeNode* createTree(vec)

    TreeNode* bstFromPreorder(vector<int>& preorder)
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
};

int main() {
    

}