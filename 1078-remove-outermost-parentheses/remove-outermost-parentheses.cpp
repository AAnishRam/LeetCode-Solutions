class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();

        string ans = "";
        stack<char>st;

        string temp = "";

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
                temp+=s[i];
            }
            else if(s[i] == ')')
            {
                if(st.top() == '(')
                {
                    temp+=s[i];
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                    temp+=s[i];
                }
            }

            if(st.empty())
            {
                ans += temp.substr(1,temp.length()-2);
                temp = "";
            }
        }

        return ans;
    }
};