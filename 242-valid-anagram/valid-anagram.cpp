class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> hm1;
        map<char, int> hm2;

        if(s.length() !=  t.length())
            return false;
        
        for(int i = 0; i<s.length();i++)
        {
            hm1[s[i]]++;
            hm2[t[i]]++;
        }

        
        for(int i = 0; i<s.length();i++)
        {
            if(hm1[s[i]] != hm2[s[i]])
                return false;
        }
        return true;


    }
};