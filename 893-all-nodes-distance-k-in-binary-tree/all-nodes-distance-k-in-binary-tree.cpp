/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void frameAdj(map<int, vector<int>> &hm, TreeNode*root)
    {
        if(root == nullptr)
            return;
        
        if(root->left != nullptr)
        {
            hm[root->val].push_back(root->left->val);
            hm[root->left->val].push_back(root->val);
            frameAdj(hm, root->left);
        }
        
        if(root->right != nullptr)
        {
            hm[root->val].push_back(root->right->val);
            hm[root->right->val].push_back(root->val);
            frameAdj(hm, root->right);
        }
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int, vector<int>>hm;
        frameAdj(hm, root);


        vector<int> ans;
        queue<pair<int, int>>q;
        map<int, int> visited;

        q.push({target->val, 0});
        visited[target->val] = 1;

        while(!q.empty())
        {
            int node = q.front().first;
            int step = q.front().second;
            q.pop();

            if(step == k)
                ans.push_back(node);

            for(auto adjNode : hm[node])
            {
                if(visited.find(adjNode) == visited.end())
                {
                    if(step + 1 <= k)
                    {
                        q.push({adjNode, step+1});
                        visited[adjNode] = 1;
                    }
                }
            }
        }

        return ans;
    }
};