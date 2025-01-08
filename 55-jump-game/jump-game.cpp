class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int i = 0;

        int n = nums.size();

        // while(i<n-1)
        // {
        //     if(nums[i]==0)
        //         return false;

        //     int maxi = -1;
        //     int index = i;
        //     for(int j = 1; j<=nums[i] && i+j<n ; j++)
        //     {
        //          if (maxi < i + j + nums[i + j]) { 
        //             maxi = i + j + nums[i + j];
        //             index = i + j;
        //         }
        //     }

        //     i = index;
        // }
       

        // return true;

        int canReach = nums[0];

        for(int i=0;i<nums.size();i++)
        {
            if(canReach>=n-1)
                return true;

            if(canReach < i+nums[i])
                canReach = i+nums[i];

            if(i==canReach)
                return false;
        }

        return false;
    }
};