class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
        int ans = 0;
        int sign = 1;

        while(i<s.length() && s[i] == ' ')
            i++;
        

        if(i < s.length() && (s[i]=='-' || s[i] =='+'))
        {
            if(s[i] == '-')
                sign *= -1;
            else
                sign *= +1;

            i++;
        }

        while(i<s.length() && s[i] == '0')
            i++;
        
        while(i<s.length() && s[i] >= '0' && s[i]<='9')
        {
            int digit = s[i] - '0';

            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans*sign;


        // how did i checked over flow

        // everytime       ans * 10 + digit <= INT_MAX;
        // on rearranging  ans * 10         <= (INT_MAX - digit) / 10;
        //                 ans              <= (INT_MAX - digit) / 10;

        // therefore if    ans              >  (INT_MAX - digit) / 10;
        // we need to return INT_MAX;

    }
};