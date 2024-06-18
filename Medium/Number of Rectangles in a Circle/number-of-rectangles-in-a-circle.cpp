//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

  class Solution {
  public:
    int rectanglesInCircle(int r) {
        int noOfRectangles = 0;
        int diameter = 2*r;
        int diametersquare = diameter*diameter;
        for(int a=1;a<diameter;a++){
            for(int b=1;b<diameter;b++){
                int diagonalsquare=a*a+b*b;
                if(diagonalsquare<=diametersquare){
                    noOfRectangles++;
                }
            }
        }
        return noOfRectangles;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends