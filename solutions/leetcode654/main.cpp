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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.size() == 0)
            return NULL;

        int max_index = findMaxIndex(nums);
        TreeNode * root = new TreeNode(nums[max_index]);

        vector<int> left_nums(nums.begin(), nums.begin() + max_index);
        vector<int> right_nums(nums.begin() + max_index + 1, nums.end());
        root->left = constructMaximumBinaryTree(left_nums);
        root->right = constructMaximumBinaryTree(right_nums);
        return root;
    }
    int findMaxIndex(vector<int>& nums) {
        int max = -1, index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        return index;
    
    }
};

int main() {
    vector<int> a = {1};

    vector<int> b (a.begin(), a.begin());

    for( auto iter : b)
        cout<<iter<<endl;

    return 0;
}