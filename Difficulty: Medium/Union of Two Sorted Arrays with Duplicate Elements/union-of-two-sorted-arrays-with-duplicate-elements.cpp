//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        
        vector<int> ans;
        
        int m = a.size();
        int n = b.size();
        
        int i = 0;
        int j = 0;
        

        while(i<m && j<n)
        {
            if(a[i]<=b[j])
            {
                if(ans.size()==0)
                    ans.push_back(a[i]);
                else if(ans[ans.size()-1]!=a[i])
                    ans.push_back(a[i]);
                i++;
            }
            else
            {
                if(ans.size()==0)
                    ans.push_back(b[j]);
                else if(ans[ans.size()-1]!=b[j])
                    ans.push_back(b[j]);
                j++;
            }
            
        }
        
        while(i<m)
        {
            if(ans[ans.size()-1]!=a[i])
                    ans.push_back(a[i]);
            i++;
        }
        
        while(j<n)
        {
            if(ans[ans.size()-1]!=b[j])
                    ans.push_back(b[j]);
            j++;
        }
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends