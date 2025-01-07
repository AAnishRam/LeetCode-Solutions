class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(nums[mid]== target)
            {
                while(low<=mid && nums[low]!=target) low++;
                while(high>=mid && nums[high]!=target) high--;
                return {low, high};
            }

            if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return {-1, -1};
    }
};