class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0, e1;
        int c2 = 0, e2;

        for(int i=0;i<nums.size();i++)
        {
            if(c1==0 && e2!=nums[i])
            {
                c1 = 1;
                e1 = nums[i];
            }
            else if(c2==0 && e1!=nums[i])
            {
                c2 = 1;
                e2 = nums[i];
            }
            else if(e1 == nums[i])
            {
                c1++;
            }
            else if(e2 == nums[i])
            {
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        c1 = 0;
        c2 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==e1)c1++;
            if(nums[i]==e2)c2++;
        }

        vector<int>ans;

        if(c1>=n/3+1)
        ans.push_back(e1);
        if(c2>=n/3+1)
        ans.push_back(e2);

        return ans;
        
    }
};