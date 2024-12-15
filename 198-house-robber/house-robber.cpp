class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n);


        if(n-1==0)
            return nums[0];
        if(n-1==1)
            return max(nums[0],nums[1]);

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++)
        {
            int val1 = dp[i-1];
            
            int val2 = nums[i] + dp[i-2];

            dp[i] = max(val1,val2);

        }

        return dp[n-1];

    }
};