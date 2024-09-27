class Solution {
    public int maxArea(int[] height) {
        int n = height.length;

        int i = 0,j=n-1;

        int ans = 0;
        int max = 0;

        while(i<j)
        {
            max = (j-i) * Math.min(height[j],height[i]);

            ans = Math.max(ans,max);
            if(height[i]<height[j])
                i++;
            else
                j--;
    
        }
        return ans;
    }
}