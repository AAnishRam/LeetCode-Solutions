class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer,Integer> h=new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            if(!h.containsKey(nums[i]))
            {
                h.put(nums[i],1);
            }
            else
            {
                h.put(nums[i],h.get(nums[i])+1);
            }
        }
        int ans=0;
        for(Map.Entry<Integer,Integer> ma:h.entrySet())
        {
            int v=ma.getValue();
            if(v==1)
            {
            ans=ma.getKey();
            }
            
        }
        return ans;
        
    }
}