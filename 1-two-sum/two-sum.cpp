class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hm;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(hm.find(target-nums[i]) != hm.end())
            {
                return {i,hm[target-nums[i]]};
            }
            hm[nums[i]] = i;
        }
        return {-1,-1};
    }
};