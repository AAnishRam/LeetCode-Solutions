//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    long long multiply(int x, int n)
    {
        long long ans = 1;
        
        
        // here in for loob in this function itself we can add a parameter if
        // its crossed the mid value break the for loop or return some thing
        for(int i=0;i<n;i++)
            ans*=x;
            
        return ans;
    }
    
    int nthRoot(int n, int m) {
        
        int low = 1;
        int high = m;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            long long temp = multiply(mid, n);
            
            if(temp == m)
                return mid;
                
            if(temp > m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends