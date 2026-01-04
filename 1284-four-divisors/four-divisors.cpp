class Solution {
public:

    int divisors(int num) {
        int val = num;
        int sum = 0;
        int count = 1;
        num /= 2;
        sum += val;
        for(int i=1; i<=num; i++) {
            if(val % i == 0)
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