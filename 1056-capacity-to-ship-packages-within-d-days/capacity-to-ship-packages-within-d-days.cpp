class Solution {
public:

    bool canShip(vector<int> weights, int days, int cap)
    {
        int sum = 0;
        int reqDays = 0;
        for(auto it : weights)
        {
            if(it > cap)
                return false;
            if(sum + it == cap)
            {
                reqDays++;
                sum = 0;
            }
            else if(sum + it > cap) 
            {
                reqDays++;
                sum = it;
            }
            else
            {
                sum += it;
            }
        }

        if(sum !=0)
            reqDays++;
        cout<<cap<<" "<<reqDays<<endl;

        return reqDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = INT_MAX;

        while(low <= high)
        {
            int mid = low + ((high - low) / 2);

            if(canShip(weights, days, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};