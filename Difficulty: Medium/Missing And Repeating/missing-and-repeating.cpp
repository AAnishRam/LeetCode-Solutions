//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>&A) {
        vector<int>Arr = A;
    int n = Arr.size();
    int missing, repeated;

    for (int i = 0; i < n; i++)
    {
        int index = abs(Arr[i]) - 1;

        if (Arr[index] < 0)
        {
            repeated = abs(Arr[i]);
        }
        else
        {
            Arr[index] = -1 * Arr[index];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (Arr[i - 1] > 0)
        {
            missing = i;
        }
    }

    vector<int> ans;
    ans.push_back(repeated);
    ans.push_back(missing);

    return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends