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

    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxi = INT_MIN, maxLevel = INT_MIN;
        q.push(root);

        int level = 0;

        while(!q.empty()) {
            level++;
            int sum = 0;
            int count = q.size();
            for(int i=0; i < count; i++) {
                TreeNode *top = q.front();
                q.pop();
                sum += top->val;

                if(top->left != nullptr)
                    q.push(top->left); 
                if(top->right != nullptr)
                    q.push(top->right); 
            }
            if(sum > maxi) {
                maxi = sum;
                maxLevel = level;
            }
        }

        return maxLevel;
    
    }
};