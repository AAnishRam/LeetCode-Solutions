class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n <= 1) return 1; // Base case, no need to update dp[n] here.
        if (dp[n] != -1) return dp[n]; // Use memoized value if available.

        return dp[n] = f(n - 1, dp) + f(n - 2, dp); // Compute and store.
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1); // Initialize dp array.
        return f(n, dp); // Call helper function.
    }
};
