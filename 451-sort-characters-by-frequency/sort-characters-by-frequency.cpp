class Solution {
public:

    static bool cmp(pair<int, int>a, pair<int, int> b)
    {
        return a.second > b.second;        
    }

    string frequencySort(string s) {

        map<char, int> hm;

        for(auto it : s)
            hm[it]++;

        vector<pair<char, int>> arr(hm.begin(), hm.end());

        sort(arr.begin(),arr.end(), cmp);

        string ans = "";    

        for(auto it : arr)
        {
            ans += string(it.second, it.first);
        }

        return ans;
    }
};