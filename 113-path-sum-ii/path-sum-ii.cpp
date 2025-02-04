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
    bool hasPathSum(TreeNode *root, int targetSum, vector<vector<int>>&ans, vector<int> &temp)
    {
        if(root == nullptr)
            return false;

        temp.push_back(root->val);
        targetSum -= root->val;

        if(targetSum == 0 && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(temp);
            temp.pop_back();
            return true;
        }

        bool left = hasPathSum(root->left, targetSum, ans, temp);
        bool right = hasPathSum(root->right, targetSum, ans, temp);
         
        temp.pop_back();

        return left || right;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        hasPathSum(root, targetSum, ans, temp);
        return ans;
    }
};