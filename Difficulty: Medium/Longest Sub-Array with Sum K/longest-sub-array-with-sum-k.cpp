//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        map<int, int> hm;
        int sum = 0;
        int maxi = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==k)
                maxi = max(maxi, i+1);
                
            if(hm.find(sum)==hm.end())
                hm[sum] = i;
                
            int rem = sum-k;
            
            if(hm.find(rem)!=hm.end())
            {
                maxi = max(maxi,i-hm[rem]);
            }
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends