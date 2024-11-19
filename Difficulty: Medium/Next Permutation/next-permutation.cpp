//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size(), i = n-2, j = n-1;
        while(i >= 0 and arr[i] >= arr[i+1]) i--;
        
        while(i >= 0 and arr[i] >= arr[j]) j--;
        if(i >= 0) swap(arr[i], arr[j]);
        reverse(arr.begin() + i+1, arr.end());
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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends