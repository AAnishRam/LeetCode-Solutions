class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size() / 2;
        map<int, int> hm;
        
        for(auto it : nums) {
            hm[it]++;
        }
        
        for(auto it : hm) {
            if(it.second == n)
                return it.first;
        }

        return 0;
    }
};