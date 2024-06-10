class Solution {
    public int heightChecker(int[] heights) {
        int [] expected = heights.clone();

        Arrays.sort(expected);

        int count = 0;

        for(int i=0;i<heights.length;i++)
        {
            System.out.println(heights[i]);
            if(heights[i]!=expected[i])
                count++;
        }
        return count;
    }
}