//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    bool canPlace(vector<int>& stalls, int k, int dist)
    {
        int curr = 0;
        k--;
        
        for(int i=1; i<stalls.size(); i++)
        {
            if(stalls[i]-stalls[curr]>=dist)
            {
                k--;
                curr = i;
            }
        }
        
        return k <= 0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        
        sort(stalls.begin(),stalls.end());

        int n = stalls.size();
        int low = 1;
        int high = *max_element(stalls.begin(),stalls.end()) - *min_element(stalls.begin(), stalls.end());
        
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(canPlace(stalls, k, mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends