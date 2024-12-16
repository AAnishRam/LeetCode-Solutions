class Solution {
public:

    int solution(vector<int> &nums,int start, int n)
    {
        if (n <= start) return nums[0]; // Base case: No houses to rob

        vector<int> dp (n);

        dp[start] = nums[start];

        for(int i=start+1;i<n;i++)
        {
            int ifPicked = nums[i];
            if(i>start+1)
                ifPicked += dp[i-2];
            
            int notPicked = dp[i-1];

            dp[i] = max(ifPicked,notPicked);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {

        

        int ans1 = solution(nums,0,nums.size()-1);
        int ans2 = solution(nums,1,nums.size());
        return max(ans1,ans2);
    }
};