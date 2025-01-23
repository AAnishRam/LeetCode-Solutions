class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s == t;

        map<char, int> hm;
        

        if(s.length() !=  t.length())
            return false;
        
        for(int i = 0; i<s.length();i++)
        {
            hm[s[i]]++;
            hm[t[i]]--;
        }

        for(auto it : hm)
        {
            if(it.second != 0)
                return false;
        }
        return true;


    }
};