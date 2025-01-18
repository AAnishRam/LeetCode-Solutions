class Solution {
public:

    int canAllocate(vector<int>& arr,int maxSum) {
        int split = 1;
        
        long long sum = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(sum + arr[i] <= maxSum)
                sum += arr[i];
            else
            {
                sum = arr[i];
                split++;
            }
        }
        
        return split;
    }

    int splitArray(vector<int>& arr, int k) {
        if(k > arr.size()) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        // cout<<high;
        
        int ans = -1;
        

        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(canAllocate(arr, mid) <= k)
            {
                ans = mid;
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