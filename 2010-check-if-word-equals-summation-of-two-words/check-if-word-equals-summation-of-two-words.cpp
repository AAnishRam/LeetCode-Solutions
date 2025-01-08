class Solution {
public:

    int countWord(string str)
    {
        int ans = 0;

        for(int i=0;i<str.size();i++)
        {
            ans = (ans*10)+(str[i]-'a');
        }
        return ans;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int n1 = countWord(firstWord);
        int n2 = countWord(secondWord);
        int n3 = countWord(targetWord);

        return n1+n2 == n3;


    }
};