//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   bool canSplit(vector<int>& arr) {
    int l=0;
    int r=arr.size()-1;
    int l_sum = 0 , r_sum=0;
    while(l<=r){
        if(l_sum>=r_sum){
            r_sum+=arr[r];
            r--;
        }
        else if(r_sum>l_sum){
            l_sum+=arr[l];
            l++;
        }
    }
    return (l_sum==r_sum)?true:false;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends