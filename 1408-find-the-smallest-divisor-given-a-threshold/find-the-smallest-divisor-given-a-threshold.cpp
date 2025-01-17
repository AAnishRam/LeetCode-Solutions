class Solution {
public:

    bool isPossible(vector<int> nums, int t, int d)
    {
        int sum = 0;

        for(auto it : nums)
        {
            sum += ceil((double)it / (double)d);

            if(sum > t)
                return false;
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(isPossible(nums, threshold, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};