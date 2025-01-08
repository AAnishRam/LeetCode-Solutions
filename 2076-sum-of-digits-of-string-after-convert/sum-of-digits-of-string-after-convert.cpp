class Solution {
public:

    long long countWord(string str)
    {
        long long ans = 0;

        for(int i=0;i<str.size();i++)
        {
            int temp = str[i]-'a'+1LL;
            
            while(temp!=0)
            {
                ans += temp%10;
                temp/=10;
            }
        }
        return ans;
    }

    long long transform(long long n)
    {
        long long sum = 0;
        while(n!=0) 
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        
            long long n = countWord(s);

            cout<<n;

            for(int i = 2;i<=k;i++)
               n = transform(n);

            return n;


    }
};