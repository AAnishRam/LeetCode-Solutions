class Solution {
    public int maxSubArray(int[] arr) {
        int n = arr.length;
        
        int sum = 0;
        int ans = Integer.MIN_VALUE;

        for(int i=0;i<n;i++)
        {
            if(sum>=0)
                sum+=arr[i];
            else
                sum = arr[i];

            ans = Math.max(sum,ans);
        }

        return ans;

    }
}