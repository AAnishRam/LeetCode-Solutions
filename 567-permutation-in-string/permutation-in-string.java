class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int l = 0;
        Map<Character, Integer> s1hm = new HashMap<Character, Integer>();
        for(int i = 0; i < s1.length(); i++){
            Character c = s1.charAt(i);
            if(!s1hm.containsKey(c)){
                s1hm.put(c, 1);
            } else{
                s1hm.put(c, s1hm.get(c) + 1);
            }
        }
        for (int r = s1.length(); r <= s2.length(); r++){

            String str = s2.substring(l, r);
            
            Map<Character, Integer> s2hm = new HashMap<Character, Integer>();
            for(int i = 0; i < str.length(); i++){
                Character c = str.charAt(i);
                if(!s2hm.containsKey(c)){
                    s2hm.put(c, 1);
                } else{
                    s2hm.put(c, s2hm.get(c) + 1);
                }
            }
            System.out.println(s2hm);
            System.out.println(s1hm);
            if(s2hm.equals(s1hm)){
                return true;
            }

            l++;
        }

        return false;
    }
}