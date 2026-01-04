class Solution {
public:

    int divisors(int num) {
        int val = num, sum = 0, count = 1;
        sum += val;
        val /= 2;
        for(int i=1; i<=val; i++) {
            if(num % i == 0)
            {
                count++;
                sum += i;
            }
            
            if(count > 4)
                return 0;
        }

        return (count == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for(auto it : nums)
        {
            sum += divisors(it);
        }
        return sum;
    }

};