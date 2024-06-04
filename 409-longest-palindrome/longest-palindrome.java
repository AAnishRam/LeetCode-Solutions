class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> hm= new HashMap();

        for(char i:s.toCharArray())
        {
            hm.put(i,hm.getOrDefault(i,0)+1);
        }

        int count = 0;
        boolean hasOne = false;

        for(Map.Entry<Character, Integer> val : hm.entrySet())
        {
            if(val.getValue()%2==1)
            {
                hasOne = true;
            }
            
                count += val.getValue()-(val.getValue()%2);
            
        }

        if(hasOne)
        count++;

        System.out.println(hm.entrySet());
        return count;
    }
}