class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue; 
            for(int j=i+1;j<n;j++)
            {
                int k = j+1;
                int l = n-1;

                while(k<l)
                {
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k]+nums[l];

                    if(sum<target)
                    {
                        k++;
                    }
                    else if(sum>target)
                    {
                        l--;
                    }
                    else 
                    {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        cout<<nums[i];
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l]==nums[l+1])l--;
                    }
                }
                j++;
                while(j<n && nums[j]==nums[j-1])j++;
                j--;
            }
        }
        return ans;
    }
};