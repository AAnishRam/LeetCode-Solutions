class Solution {
public:

    bool canMakeBouquets(vector<int> bloomDay, int day, int m, int k)
    {
        int count = 0;

        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
                count++;
            else 
                count = 0;

            if(count == k)
            {
                m--;
                count = 0;
            }
        }

        return m <= 0;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = INT_MAX;
        while(low <= high)
        {
            int mid = low + ((high-low)/2);

            if(canMakeBouquets(bloomDay, mid, m, k))
            {
                ans = min(ans,mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }

        }

        //return ans;
        return low;
    }
};