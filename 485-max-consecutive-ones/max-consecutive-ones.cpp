class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // int i = 0 , j = 0 , n = nums.size();

        // int ans = 0;

        // while(i<n && j<n)
        // {
        //     if(nums[i]==0)
        //     {
        //         i++;
        //         j=i;
        //         continue;
        //     }
        //     while(j<n && nums[j]==1)
        //         j++;
            
        //     int temp = j-i;
        //     ans = max(ans,temp);

        //     i=j;

        // }
        // return ans;

        int count = 0, ans = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            else if(nums[i]==0)
                count = 0;

            ans = max(ans,count);
        }

        return ans;
    }
};