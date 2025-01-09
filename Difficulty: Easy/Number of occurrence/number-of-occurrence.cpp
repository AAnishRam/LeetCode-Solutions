//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int first(vector<int> nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;

        int first = -1;

        while(low<=high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                first = mid;
                high = mid-1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return first;
    }
    int last(vector<int> nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;

        int last = -1;

        while(low<=high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                last = mid;
                low = mid+1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return last;
    }
    
    int countFreq(vector<int>& arr, int target) {
        
        int f = first(arr, target);
        
        if(f == -1) return 0;
        
        int l = last(arr, target);
        
        return l-f+1;
            
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends