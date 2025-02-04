/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool checkHasSum(TreeNode *root, int targetSum)
    {
        if(root == nullptr)
        {
            return false;
        }

        targetSum -= root -> val;

        if(targetSum == 0 && root->left == nullptr && root->right == nullptr)
            return true;

        bool left = checkHasSum(root->left, targetSum);
        bool right = checkHasSum(root->right, targetSum);

        return left || right;
        
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return checkHasSum(root, targetSum);
    }
};