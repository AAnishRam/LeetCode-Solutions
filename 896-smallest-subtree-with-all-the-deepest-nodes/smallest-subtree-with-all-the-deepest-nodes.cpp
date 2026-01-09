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
void depthOfTree(TreeNode *node, int depth, map<TreeNode*, int> &hm, int &maxi) {
        if(node == nullptr)
            return;
        hm[node] = depth;
        maxi = max(maxi, depth);
        depthOfTree(node->left, depth+1, hm, maxi);
        depthOfTree(node->right, depth+1, hm, maxi);
    }

    TreeNode* lca(TreeNode *node, TreeNode *s, TreeNode *t) {
        if(node == nullptr || node == s || node == t)
            return node;

        TreeNode *left = lca(node->left, s, t);
        TreeNode *right = lca(node->right, s, t);

        if(left == nullptr)
            return right;
        else if(right == nullptr)
            return left;
        else
            return node;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*, int>hm;
        int maxi = INT_MIN;
        depthOfTree(root, 0, hm, maxi);

        queue<TreeNode*>q;
        for(auto it : hm) {
            if(it.second == maxi) {
                q.push(it.first);
            }
        }

        while(q.size() > 1) {
            TreeNode* s = q.front();
            q.pop();
            
            TreeNode* t = q.front();
            q.pop();

            q.push(lca(root, s, t));

        }
        return q.front();;
    }
};