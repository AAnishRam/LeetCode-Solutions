class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size()-1;

        int k = 0;

        while(i<=j)
        {
            while(nums[i]==val && i<=j)
            {
                swap(nums[i],nums[j--]);
                k++;
            }
            i++;
        }
        cout<<nums.size()-k;
        return nums.size()-k;

    }
};