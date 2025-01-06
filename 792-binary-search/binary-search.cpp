class Solution {
public:

    int binarySearch(vector<int>& nums, int target)
    {
        // if(low > high)
        // return -1;


        // int mid = (low + high) / 2;

        // if(nums[mid]==target) return mid;

        // if(nums[mid]<target) 
        //     return binarySearch(nums, target, mid+1, high);
        // else
        //     return binarySearch(nums, target, low, mid-1);


        int low = 0;
        int high = nums.size()-1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(nums[mid]==target)return mid;
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }

        return -1;


    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target);
    }
};