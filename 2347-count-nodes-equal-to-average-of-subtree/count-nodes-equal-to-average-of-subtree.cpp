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

    pair<int, int> recur(TreeNode *root, int &ans)
    {
        if(root == nullptr)
        {
            return {0, 0};
        }

        auto lh = recur(root->left, ans);
        auto rh = recur(root->right, ans);

        int subTreeSum = root->val + lh.first + rh.first;
        int subTreeCount = 1 + lh.second + rh.second;

        if(root->val == subTreeSum / subTreeCount)
            ans++;

        return {subTreeSum, subTreeCount};

    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        recur(root, ans);
        return ans;
    }
};