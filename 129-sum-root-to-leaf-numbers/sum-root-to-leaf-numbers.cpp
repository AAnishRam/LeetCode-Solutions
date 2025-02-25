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
    void recur(TreeNode* root, int &ans, int sum)
    {
        if(root == nullptr)
        {
            return;
        }

        sum = (sum*10) + root->val;

        if(root->left == nullptr && root->right == nullptr)
        {
            ans += sum;
            return;
        }

        recur(root->right, ans, sum);
        recur(root->left, ans, sum);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        recur(root, ans, 0);
        return ans;
    }
};