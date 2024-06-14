//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int originalvalue = n; // store the original value
        int sum = 0; // sum up
        while(n>0){
            int lastDigit = n%10;
            sum = sum + (lastDigit * lastDigit*lastDigit);
            n = n/10;
        }
        if(sum == originalvalue){
            return "Yes";
        }
        else{
            return "No";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends