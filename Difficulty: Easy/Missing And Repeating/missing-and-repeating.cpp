//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        //x-y
        // from x^2-y^2 find x+y solve to get x and y
        
        int n = arr.size();
        
        long long S = 0;
        long long Sn = (n * (n + 1LL)) / 2;
        
        long long S2 = 0;
        long long S2n = (n * (n + 1LL) * (2 * n + 1LL)) / 6;
        
        for(int i = 0;i < n; i++)
        {
            S+=arr[i];
            S2+=((long long)arr[i]*(long long)arr[i]);
        }
        
        //x-y
        long long n1 = S-Sn;
        
        //x+y 
        long long n2 = (S2-S2n)/n1;
        
        long long x = (n1 + n2) / 2;
        long long y = x - n1;
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)cnt++;
        }
        
        if(cnt==2)  return {(int)x, (int)y};
        else    return {(int)y,(int)x};
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends