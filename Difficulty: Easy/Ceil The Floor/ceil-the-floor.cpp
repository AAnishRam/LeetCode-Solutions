//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
  
    int floor_func(int x, vector<int> &arr)
    {
        int ans = -1;
        
        int low = 0;
        int high = arr.size() - 1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(arr[mid]<=x)
            {
                ans = arr[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    int ceil_func(int x, vector<int> &arr)
    {
        int ans = -1;
        
        int low = 0;
        int high = arr.size() - 1;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(arr[mid]>=x)
            {
                ans = arr[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        
        sort(arr.begin(),arr.end());
        
        return { floor_func(x, arr), ceil_func(x, arr) };
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends