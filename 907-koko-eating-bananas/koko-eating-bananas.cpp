class Solution {
public:

    bool canEat(int k, vector<int> piles, int h)
    {
        long long count = 0;

        for(int i=0;i<piles.size();i++)
        {
            count += piles[i] / k;
            long long rem = piles[i] % k;

            if(rem != 0)
                count++;
            
            if(count > h)
                return false;
        }

        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        
        int low = 1;
        int high = INT_MIN;

        for(auto it : piles)
            high = max(high, it);

        int ans = INT_MAX;

        while(low <= high)
        {
            int mid = ( low + high ) / 2;

            if(canEat(mid, piles, h))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;

    }
};