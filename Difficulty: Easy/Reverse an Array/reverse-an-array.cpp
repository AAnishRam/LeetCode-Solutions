//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void rev(int l,int r,vector<int> &arr){
        if(l>=r)
            return;
        swap(arr[l],arr[r]);
        rev(l+1,r-1,arr);
        return;
    }
  
    void reverseArray(vector<int> &arr) {
        // code here
        rev(0,arr.size()-1,arr);
        return;
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends