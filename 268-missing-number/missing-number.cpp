class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //using sum of n natural numbers
        // int n = nums.size();

        // int sum = 0;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=nums[i];
        // }
        // int temp = (n*(n+1))/2;

        // return temp-sum;
        int xor1 = 0;
        int xor2 = 0;

        for(int i=0;i<nums.size();i++)
        {
            xor1^=(i+1);
            xor2^=nums[i];
        }
        return xor1^xor2;

    }
};