//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        
        int n1 = a;
        int n2 = b;
        
        while(a>0 && b>0)
        {
            if(a>b) a = a%b;
            else b = b%a;
        }
        
        int gcd;
        
        if(a==0)
            gcd = b;
        else
            gcd = a;
            
        int lcm = n1*n2/gcd;
        
        vector<int>ans;
        ans.push_back(lcm);
        ans.push_back(gcd);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends