class Solution {
public:

    char isOdd(char c)
    {
        return ( (c - '0') % 2 == 1);
    }

    string largestOddNumber(string num) {
        int j = num.size()-1;

        while(j >= 0)
        {
            if(isOdd(num[j]))
                return num.substr(0, j+1);
            j--;
        }
        return num.substr(0, j+1);
    }
};