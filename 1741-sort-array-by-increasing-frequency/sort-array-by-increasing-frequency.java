class Solution {
    public int[] frequencySort(int[] nums) {
           Arrays.sort(nums);

           HashMap<Integer,Integer> hm = new HashMap();

           for(var i: nums)
           {
                hm.put(i,hm.getOrDefault(i,0)+1);
           } 


            List<Integer> numList = new ArrayList();

            for(var i:nums)
                numList.add(i);

           Collections.sort(numList, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                int freqCompare = Integer.compare(hm.get(a), hm.get(b));
                if (freqCompare != 0) {
                    return freqCompare;
                } else {
                    return Integer.compare(b, a);
                }
            }
            });

            for(int i=0;i<nums.length;i++)
            {
                nums[i] = numList.get(i);
            }

            return nums;
    }
}