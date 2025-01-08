class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) 
            return 0;

        int maxJump = 0;
        int currJump = 0;

        int jump = 0;

        for(int i=0;i<n;i++)
        {
            maxJump = max(maxJump, i + nums[i]);

            if(currJump == i)
            {
                currJump = maxJump;
                jump++;
            }

            if(currJump>=n-1)
                break;
        }

        return jump;
    }
};
