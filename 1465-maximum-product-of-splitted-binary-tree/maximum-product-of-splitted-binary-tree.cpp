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

    long long findTreeSum(TreeNode * node, long long sumOfTree, long long &maxi, bool flag) {
        if(node == nullptr)
            return 0;

        long long leftSum = findTreeSum(node->left, sumOfTree , maxi, flag);
        long long rightSum = findTreeSum(node->right, sumOfTree , maxi, flag);

        long long sum = (leftSum + rightSum + node->val);

        if(flag)
        maxi = max(maxi, sum * (sumOfTree-sum));

        return sum ;
    }

    int maxProduct(TreeNode* root) {
        long long maxi = LLONG_MIN;
        long long sumOfTree = findTreeSum(root, 0, maxi, false);
        findTreeSum(root, sumOfTree, maxi, true);
        
        return maxi % (long long)(1e9 + 7);
    }
};