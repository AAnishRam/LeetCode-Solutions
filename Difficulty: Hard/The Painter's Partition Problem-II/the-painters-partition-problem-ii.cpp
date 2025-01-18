//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int canAllocate(vector<int>& arr,int maxSum) {
        int split = 1;
        
        long long sum = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(sum + arr[i] <= maxSum)
                sum += arr[i];
            else
            {
                sum = arr[i];
                split++;
            }
        }
        
        return split;
    }
    int minTime(vector<int>& arr, int k) {
        
        // if(k > arr.size()) return -1;
        
        int ans = -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(canAllocate(arr, mid) <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends