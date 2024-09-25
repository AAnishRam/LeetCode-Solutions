class Solution {
    public int subarraySum(int[] nums, int k) {

        int subArray[] = new int[nums.length];

        int count = 0;

        for(int i=0;i<nums.length;i++)
        {
            if(i==0)
                subArray[i] = nums[i];
            else
                subArray[i] = subArray[i-1]+nums[i];

            System.out.println(subArray[i]);
        }

        for(int i=0;i<nums.length;i++)
        {
            for(int j=i;j<nums.length;j++)
            {
                if(i==0)
                {
                    if(subArray[j]==k)
                        count++;
                }
                else 
                {
                    if(subArray[j]-subArray[i-1]==k)
                        count++;
                }
            }
        }

        return count;

    }
}