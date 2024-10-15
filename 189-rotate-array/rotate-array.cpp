class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k= k%n;

        if(n==1)
            return;


        for(int i=0;i<n/2;i++)
        {
            swap(nums[i],nums[n-i-1]);
        }

        for(int i=0;i<(k)/2;i++)
        {
            swap(nums[i],nums[k-i-1]);
        }

        for(int i=k;i<(n+k)/2;i++)
        {
            swap(nums[i],nums[n+k-i-1]);
        }

    }
};