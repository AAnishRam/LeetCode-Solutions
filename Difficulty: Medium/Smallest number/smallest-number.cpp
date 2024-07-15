//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        string ans="";
        int rem=s;
        int dig;
        for (int i=1;i<=d;i++)
        {
            if (i==1)
            {
                int sum=(d-1)*9;
                if (sum+9<s) return "-1";
                int dig=max(1,s-sum);
                s-=dig;
                ans+=to_string(dig);
                continue;
            }
            
            int dig=s-(d-i)*9;
            if (dig<=0) ans+="0";
            else{
                ans+=to_string(dig);
                s-=dig;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends