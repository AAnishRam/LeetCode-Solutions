//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        
        // Using map to store the first & last occurence of the element


        unordered_map<int , int>first_occur ; 
        unordered_map<int,int>last_occur;
        
        // Creating the Hash Map 


        for(int i = 0 ; i<arr.size() ; i++){


            // First Occurence of the item
            if(first_occur.find(arr[i]) == first_occur.end()){
                first_occur[arr[i]] = i;
                last_occur[arr[i]] = i;
            }
            else{                // Elements already exist (Second/last occurence )
                last_occur[arr[i]] = i;
            }
        }
        
        int diff = 0 ; 
        // Checking the max difference 
        for(int i = 0 ; i<arr.size(); i++){
            if(last_occur[arr[i]] - first_occur[arr[i]] > diff ){
                diff = (last_occur[arr[i]] - first_occur[arr[i]]);
            }
        }
        return diff ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends