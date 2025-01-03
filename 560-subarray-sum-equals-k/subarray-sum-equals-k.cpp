class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        map<int,int> hm;
        int count = 0;
        int n = arr.size();

        int sum = 0;
        hm[sum]++;


        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            int rem = sum-k;
            count+=hm[rem];
            hm[sum]++;
        }
        return count;
    }
};