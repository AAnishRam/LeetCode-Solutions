class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = INT_MAX;
        for(int i=0; i<n-k+1; i++) {
            sum = min(sum, nums[i+k-1] - nums[i]);
        }
        return sum;
    }
};