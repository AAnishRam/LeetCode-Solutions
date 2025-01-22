//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
       
       int n = stations.size();
       priority_queue<pair<long double, int>> pq;
       vector<int> howMany(n-1, 0);
       
       for(int i = 0; i < n-1; i++)
       {
           pq.push({(long double)stations[i+1]-stations[i], i});
       }
       
       for(int i = 0; i < k; i++)
       {
           auto it = pq.top();
           pq.pop();
           
           int sec_index = it.second;
           howMany[sec_index]++;
           
           long double diff = (long double)stations[sec_index + 1] - stations[sec_index];
           long double new_diff = diff / (long double) (howMany[sec_index] + 1);
           pq.push({new_diff, sec_index});
       }
       
       return round(pq.top().first*100)/100.0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends