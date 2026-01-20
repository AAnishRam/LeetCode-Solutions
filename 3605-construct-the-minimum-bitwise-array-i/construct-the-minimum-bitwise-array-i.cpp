class Solution {
public:

    int check(int n) {
        for(int i=1; i<=n; i++) {
            if((i | (i + 1)) == n)
                return i;
        }
        return -1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto it : nums) {
            ans.push_back(check(it));
        }

        return ans;
    }
};