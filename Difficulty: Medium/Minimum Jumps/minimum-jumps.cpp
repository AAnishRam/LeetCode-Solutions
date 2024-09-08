//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array



class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;  // Base case: If we are already at the end
        
        int jump = 0;
        int maxi = 0;
        int mrange = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i] + i);  // Update the farthest we can reach

            // If we've reached the current maximum range
            if (mrange == i) {
                mrange = maxi;  // Move the range forward
                jump++;         // Increment jump count

                // If we have reached or exceeded the end, return the number of jumps
                if (mrange >= n - 1) {
                    return jump;
                }

                // If we can't move further from this point, return -1
                if (mrange <= i) {
                    return -1;
                }
            }
        }

        return -1;  // In case it's not possible to reach the end
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends