//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
     int circularSubarraySum(vector<int> &arr) {
        // your code here
         // We have to use Kadane's Algorithm for the finding the max sum subarray
         int n=arr.size();
         int maxsum=INT_MIN,sum=0;
         int totalsum=0;
         for(int i=0;i<n;i++)
         {
             sum+=arr[i];
             totalsum+=arr[i];
             maxsum=max(maxsum,sum);
             if(sum<0)
             {
                 sum=0;
             }
         }
         // We have to find the Minimum Sum subarry by Kadane's Algorithm
         int minsum=INT_MAX,sum1=0;
         for(int i=0;i<n;i++)
         {
             sum1+=arr[i];
             minsum=min(minsum,sum1);
             if(sum1>0)
             {
                 sum1=0;
             }
         }
         if(maxsum<0)
         {
             return maxsum;
         }
         return max(maxsum,totalsum-minsum);
    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends