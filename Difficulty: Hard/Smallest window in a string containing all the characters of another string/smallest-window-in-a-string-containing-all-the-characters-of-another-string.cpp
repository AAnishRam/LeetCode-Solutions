//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to find the smallest window in the string s consisting of all characters of string p
    string smallestWindow(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        // If s is smaller than p, no such window can exist
        if (n < m) return "-1";  

        // Frequency map for characters in string p
        vector<int> target(256, 0);
        for (char ch : p)
            target[ch]++;

        // Variables to track the smallest window
        int start = 0, minLen = INT_MAX, minStart = 0;
        int count = 0; // To track the number of characters matched
        vector<int> window(256, 0);

        // Expanding the window using 'end' pointer
        for (int end = 0; end < n; end++) {
            char currentChar = s[end];
            window[currentChar]++;
            
            // Increment count if the character matches the requirement in target
            if (target[currentChar] != 0 && window[currentChar] <= target[currentChar]) {
                count++;
            }

            // Try to shrink the window from the left
            while (count == m) {
                int windowLen = end - start + 1;
                
                if (windowLen < minLen) {
                    minLen = windowLen;
                    minStart = start;
                }

                // Remove the character at the start
                char startChar = s[start];
                window[startChar]--;
                
                // Decrease count only if it is a relevant character
                if (target[startChar] != 0 && window[startChar] < target[startChar]) {
                    count--;
                }
                
                start++;  // Move start pointer to the right
            }
        }

        // If no valid window is found, return "-1"
        if (minLen == INT_MAX) return "-1";
        
        return s.substr(minStart, minLen);
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends