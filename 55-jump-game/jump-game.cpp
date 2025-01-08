class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;

        int n = nums.size();

        while(i<n)
        {
            if(i>=n-1)
                return true;

            if(nums[i]==0)
                return false;

            int maxi = -1;
            int index = i;
            for(int j = 1; j<=nums[i] && i+j<n ; j++)
            {
                 if (maxi < i + j + nums[i + j]) { 
                    maxi = i + j + nums[i + j];
                    index = i + j;
                }
            }

            if(i==index)
            return false;

            i = index;
        }
       

        return true;
    }
};