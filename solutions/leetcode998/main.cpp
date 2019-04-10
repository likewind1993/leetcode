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
class Solution{

public:
    TreeNode* construct(vector<int>& nums, int begin, int end)
    {
        if (begin > end)
            return NULL;

        int max_index = findMaxIndex(nums, begin, end);
        TreeNode * root = new TreeNode(nums[max_index]);

        root->left = construct(nums, begin, max_index - 1);
        root->right = construct(nums, max_index + 1, end);

        return root;
    }
    int findMaxIndex(vector<int>& nums, int begin, int end)
    {
        int max = -1, index = 0;
        for (int i = begin; i <= end; ++i)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
        }
        return index;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return construct(nums, 0, nums.size() - 1);
    }
    
    void visitTree(vector<int>& A, TreeNode * root) {
        if(root == NULL)
            return ;
        visitTree(A, root->left);
        A.emplace_back(root->val);
        visitTree(A, root->right);
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val)
    {
        vector<int> A;
        visitTree(A, root);

        A.emplace_back(val);
        return constructMaximumBinaryTree(A);
    }
};
int main() {
    vector<int> a = {1, 2, 3, 4, 1};

    cout<<a[0 + 3]<<endl;

    return 0;
}