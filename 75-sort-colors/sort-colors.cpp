class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int k = 0;

        while(k<n)
        {
            while(i<=k && nums[k]==0)
            {
                swap(nums[i],nums[k]);
                i++;
            }
            while(k<=j && nums[k]==2)
            {
                swap(nums[j],nums[k]);
                j--;
            }
            while(i<=k && nums[k]==0)
            {
                swap(nums[i],nums[k]);
                i++;
            }
            k++;
           
        }
    }
};