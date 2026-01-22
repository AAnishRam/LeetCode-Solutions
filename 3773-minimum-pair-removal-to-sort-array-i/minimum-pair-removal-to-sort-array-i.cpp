class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        bool flag = true;

        while(flag) {
            if(nums.size() < 2)
                return count;
            int first = -1;
            int second = -1;
            int mini = INT_MAX;
            bool orderCheck = true;
            for(int i=0; i<nums.size() - 1; i++) {
                if(nums[i] + nums[i+1] < mini) {
                    mini = nums[i] + nums[i+1];
                    first = i;
                    second = i+1;
                }
                if(nums[i] > nums[i + 1]) orderCheck = false;
            }
            if(orderCheck)
            { 
                return count;
            }
            nums[first] = nums[first] + nums[second];
            nums.erase(nums.begin() + second);
            count++;
        }
        return count;
        
    }
};