class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        int temp = nums[0];

        while(i<n && nums[i-1]<=nums[i])
        {
            i++;
        }

        if(i<n && nums[i]>temp ) return false;

        i++;

        while(i<n && nums[i-1]<= nums[i])
        {
            if(nums[i]>temp)
                return false;
            
            i++;
        }

        if(i<nums.size())
            return false;

        return true;

    }
};