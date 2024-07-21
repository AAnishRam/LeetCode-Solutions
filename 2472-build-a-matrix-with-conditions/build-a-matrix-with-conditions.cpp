class Solution {
public:
    bool findOrder(vector<vector<int>>& a, int k, unordered_map<int, int> &m){
        vector<int> adj[k+1];
        vector<int> indegree(k+1, 0);
        queue<int> q;
        int num = 0;
        
        for(int i=0;i< a.size();i++){
            adj[a[i][0]].push_back(a[i][1]);
            indegree[a[i][1]]++;
        }
        
        for(int i=1;i< k+1;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        if(!q.size()) return false;
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            indegree[val]--;
            
            m[val] = num;
            num++;
            
            for(auto i : adj[val]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        
        return (m.size() != k) ? false : true;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<vector<int>> temp;
        
        unordered_map<int, int> row, col;
        
        bool a = findOrder(rowConditions,k,row);
        bool b = findOrder(colConditions,k,col);
        
        if(!a | !b) return temp;
        
        for(int i=1;i<= k;i++){
            ans[row[i]][col[i]] = i;
        }
        return ans;
    }
};