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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*, pair<int, int>>> q;

        map<int, map<int, multiset<int>>> hm;

        vector<vector<int>> ans;

        if(root == nullptr)
            return ans;

        q.push({root, {0,0}});
        // mp[0][0].insert(root -> val);

        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int level = temp.second.first;
            int vertical = temp.second.second;

            hm[vertical][level].insert(node -> val);

            if(node -> left)
                q.push({node -> left, {level + 1, vertical - 1 }});

            if(node -> right)
            q.push({node -> right, {level + 1, vertical + 1 }});
        }

        for(auto p : hm)
        {
            vector<int> temp;

            for(auto q : p.second)
            {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
        


    }
};