class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return n;
        int i = 0;
        int j = 0;

        for(int j = 1;j<n;j++)
        {
            if(nums[i]!=nums[j])
            {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;

        //my solution 
        // while(j<n)
        // {
        //     while(j<n && nums[i]==nums[j])
        //     {
        //         j++;
        //     }
        //     if(i+1<n && j<n)
        //     nums[i+1] = nums[j];
        //     i++;
        // }
        // return i;
    }
};