class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int max = nums[0];
        int sum = 0;
        bool isZero = false;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(max<nums[i])
                max = nums[i];

            if(nums[i]==0)
                isZero = true;
        }

        if(!isZero)
            return 0;

        int ans = (max*(max+1))/2;

        if(ans == sum)
            return max+1;

        return ans-sum;
    }
};