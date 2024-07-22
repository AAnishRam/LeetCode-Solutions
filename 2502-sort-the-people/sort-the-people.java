import java.util.*;

class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        Map<Integer,String> hm = new HashMap();


        for(int i=0;i<names.length;i++)
        {
            hm.put(heights[i],names[i]);
        }

        Arrays.sort(heights);

        int arr[] = new int[heights.length];

        int index = 0;
        for(int i=heights.length-1;i>=0;i--)
        {
            arr[index] = heights[i];
            index++;
        }

        String ans[] = new String[names.length];

        for(int i=0;i<names.length;i++)
        {
            ans[i] = hm.get(arr[i]);
        }

        return ans;

        

    }
}