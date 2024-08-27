//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
       int m=0;
      
       int n=arr.size();
       for(int i=0;i<n;i++){
            int l=0;
       int r=0;
           for(int j=i;j>=0;j--){
               if(arr[j]<arr[i]){
                   l=arr[j];
                   break;
               }
           }
           for(int j=i;j<n;j++){
               if(arr[j]<arr[i]){
                   r=arr[j];
                   break;
               }
           }
           m=max(m,abs(r-l));
           
       }
    return m;   
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
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends