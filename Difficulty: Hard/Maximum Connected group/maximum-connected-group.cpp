//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Dsu{
     public:
       vector<int>parent,size;
       Dsu(int n){
           parent.resize(n+10,0);
           size.resize(n+10,1);
           for(int i=0;i<n;i++){
               parent[i]=i;
           }
       }
       int findp(int node){
           if(node==parent[node]) return node;
           return parent[node]=findp(parent[node]);
       }
       void add(int u,int v){
           int ulp_u=findp(u);
           int ulp_v=findp(v);
           if(ulp_u==ulp_v) return ;
           if(size[ulp_u]>size[ulp_v]){
               size[ulp_u]+=size[ulp_v];
               parent[ulp_v]=ulp_u;
           }
           else{
               size[ulp_v]+=size[ulp_u];
               parent[ulp_u]=ulp_v;
           }
       }
};
int dir[5] = {0, 1, 0, -1, 0};
bool isvalid(int row,int col,int n,int m){
    if(row<0 or row>=n or col<0 or col>=m) return 0;
    return 1;
}
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        Dsu d(n*m+100);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                       int newx=i+dir[k];
                       int newy=j+dir[k+1];
                       if(isvalid(newx,newy,n,m) and grid[newx][newy]==1){
                           d.add(i*m+j,newx*m+newy);
                       }
                   }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]==1) ans=max(ans,d.size[d.parent[i*m+j]]+1);
                set<int>st;
                if(grid[i][j]==0){
                    for(int k=0;k<4;k++){
                        int newx=i+dir[k];
                        int newy=j+dir[k+1];
                        if(isvalid(newx,newy,n,m)and grid[newx][newy]==1){
                            int r=d.findp(newx*m+newy);
                            st.insert(r);
                        }
                    }
                }
                int at=0;
                for(auto it:st){
                    at+=d.size[it];
                }
                ans=max(ans,at+1);
            }
        }
        if(ans==n*m+1) ans=n*m;
        return ans;
        
    }
};  


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends