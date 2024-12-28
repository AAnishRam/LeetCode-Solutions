class Solution {
public:
    void sortColors(vector<int>& nums) {
        // my code
        // int n = nums.size();
        // int i = 0;
        // int j = n-1;
        // int k = 0;

        // while(k<n)
        // {
        //     while(i<=k && nums[k]==0)
        //     {
        //         swap(nums[i],nums[k]);
        //         i++;
        //     }
        //     while(k<=j && nums[k]==2)
        //     {
        //         swap(nums[j],nums[k]);
        //         j--;
        //     }
        //     while(i<=k && nums[k]==0)
        //     {
        //         swap(nums[i],nums[k]);
        //         i++;
        //     }
        //     k++;
           
        // }

        //Dutch national flag algorithm
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};