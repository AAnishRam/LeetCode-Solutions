class Solution {
public:
    int romanToInt(string s) {
        map<char, int> hm;
        hm['I'] = 1;
        hm['V'] = 5;
        hm['X'] = 10;
        hm['L'] = 50;
        hm['C'] = 100;
        hm['D'] = 500;
        hm['M'] = 1000;

        int ans = 0;

        ans += hm[s[s.length()-1]];

        for(int i = s.length()-2; i >= 0; i--)
        {
            if(hm[s[i]] < hm[s[i+1]])
                ans -= hm[s[i]];
            else
                ans += hm[s[i]];

        }

        return ans;


    }
};