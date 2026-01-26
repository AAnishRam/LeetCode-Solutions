class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini = INT_MAX;
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size()-1; i++) {
            mini = min(mini, arr[i+1]-arr[i]);
        }
        
        for(int i=0; i<arr.size(); i++) {
            for(int j=i+1; j<arr.size(); j++) {
                if(arr[j] - arr[i] > mini)
                    break;
                
                if(arr[j] - arr[i] == mini)
                    ans.push_back({arr[i], arr[j]});
            }
        }

        return ans;

        
    }
};