class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //kadanes algorithm
        // ansStart and ansEnd are the indexes of the subarray formed

        long long maxi = INT_MIN;
        long long sum = 0;
        for(int i=0;i<nums.size();i++)
        {

            sum+=nums[i];

            if(sum>maxi)
            {
                maxi = sum;
            }

            if(sum<0)
            {
                sum = 0;
            }
        }

        return maxi;
    }
};