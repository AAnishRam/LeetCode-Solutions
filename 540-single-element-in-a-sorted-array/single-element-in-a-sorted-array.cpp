class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        if(nums.size()==1) return nums[0];

        if(nums[0]!=nums[1])   return nums[0];
        if(nums[n-1]!=nums[n-2])    return nums[n-1];

        int low = 2;
        int high = n-3;
        int mid;
        while(low<=high)
        {
            mid = (low+high)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];

            if(nums[mid]!=nums[mid+1])
                mid--;

            if(mid%2==0)
                low = mid+2;
            else
                high = mid-1;
        }
        return nums[mid];

    }
};