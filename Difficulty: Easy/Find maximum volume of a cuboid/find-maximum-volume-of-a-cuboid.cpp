//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // for fiding the maximum Voulme L=B 
        // Use the S=2(lb+bh+hl)
        //      p=4(L+B+H);
        // on solving H((perimeter/4)-2*l) and p=(perimeter-sqrt(pow(perimeter,2)-(24*area)))/12
        
        double l=(perimeter-sqrt(pow(perimeter,2)-(24*area)))/12;
        double h=((perimeter/4)-2*l);
        return l*l*h;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends