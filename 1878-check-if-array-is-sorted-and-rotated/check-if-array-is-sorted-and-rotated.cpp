class Solution {
public:
    bool check(vector<int>& nums) {
        // int i = 1;
        // int n = nums.size();
        // int temp = nums[0];

        // while(i<n && nums[i-1]<=nums[i])
        // {
        //     i++;
        // }

        // if(i<n && nums[i]>temp ) return false;

        // i++;

        // while(i<n && nums[i-1]<= nums[i])
        // {
        //     if(nums[i]>temp)
        //         return false;
            
        //     i++;
        // }

        // if(i<nums.size())
        //     return false;

        // return true;

        int count = 0;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
                count++;
        }
        if(nums[nums.size()-1]>nums[0])count++;

        return count<=1;

    }
};