class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;

        int ans = nums[0];
        int  p = 1;

        for(int i=0;i<n;i++)
        {
            p *= nums[i];
            ans = Math.max(p,ans);

            if(nums[i]==0)
                p = 1;
        }
         
        p = 1;
        
        for(int i=n-1;i>=0;i--)
        {
            p *= nums[i];
            ans = Math.max(p,ans);

            if(nums[i]==0)
                p = 1;
        }

        return ans;

        
    }
}