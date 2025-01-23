class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            string word = "";
            while(i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            if(word.length() > 0)
            {
                reverse(word.begin(),word.end());

                if(ans.size()>0)
                    ans = ans + " " + word;
                else
                    ans = ans + word;
            }
        }

        return ans;


    }
};