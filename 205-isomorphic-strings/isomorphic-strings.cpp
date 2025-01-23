class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char, char> hm1;
        map<char, char> hm2;

        for(int i = 0; i < s.length(); i++)
        {
            if(hm1.find(s[i]) != hm1.end() &&  hm1[s[i]] != t[i] )
                return false;

            if(hm2.find(t[i]) != hm2.end() && hm2[t[i]] != s[i] )
                return false;
            
            hm1[s[i]] = t[i];
            hm2[t[i]] = s[i];
        }

        return true;

        // map<char,char> hm;
        // for(int i=0;i<s.length();i++)
        // {       
        //     if(hm.find(s[i]) == hm.end())
        //     {
        //         hm[s[i]] = t[i];
        //     }
        //     else
        //     {
        //         if(hm[s[i]] != t[i])
        //             return false;
        //     }
        // }

        // return true;

    }
};