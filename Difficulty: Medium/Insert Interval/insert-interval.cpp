//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void mergeOverlap(vector<vector<int>>& arr, vector<vector<int>>& ans) {
        // Code here
        // vector<vector<int>> ans;
        // sort(arr.begin(), arr.end());
        
        int x = arr[0][0], y = arr[0][1];
        for(int i=0; i<arr.size(); ++i) {
            if(y < arr[i][0]) {
                ans.push_back({x,y});
                x = arr[i][0], y = arr[i][1];
            } else {
                y = max(y, arr[i][1]);
            }
        }
        ans.push_back({x,y});
        return;
    }
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        // Insert newInterval into sorted order
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval,
                              [](const vector<int>& a, const vector<int>& b) {
                                  return a[0] < b[0];
                              });
        intervals.insert(it, newInterval);

        // Merge overlapping intervals
        vector<vector<int>> ans;
        mergeOverlap(intervals, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends