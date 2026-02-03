class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[p])
                p = i;
            else
                break;
        }
        if(p == 0) return false;
        int q = p;
        for(int i = p+1; i<nums.size(); i++) {
            if(nums[i] < nums[q])
                q = i;
            else
                break;
        }
        if(q == p || q == nums.size() - 1) return false;

        for(int i = q+1; i<nums.size(); i++) if(nums[i] <= nums[i-1]) return false;

        cout<<p<<" "<<q;

        return true;
    }
};