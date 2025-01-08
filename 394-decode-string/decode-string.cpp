class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st;
        string ans = "";

        for(int i=0;i<s.length();i++)
        {
            string temp = "";
            if(s[i]=='[')
            {
                temp+=s[i];
                st.push(temp);
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                while(s[i]>='0' && s[i]<='9')
                {
                    temp+=s[i];
                    i++;
                }
                i--;
                st.push(temp);
            }
            else if(s[i]==']')
            {
                string segment = "";
                while (!st.empty() && st.top() != "[") {
                    segment = st.top() + segment; 
                    st.pop();
                }
                st.pop();

                
                string numStr = st.top();
                st.pop();
                int repeat = stoi(numStr);

               
                string repeatedSegment = "";
                for (int j = 0; j < repeat; j++) {
                    repeatedSegment += segment;
                }
                st.push(repeatedSegment);
            }
            else
            {
                while(s[i]>='a' && s[i]<='z')
                {
                    temp+=s[i];
                    i++;
                }
                i--;
                st.push(temp);
            }
        }


        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
        

    }
};