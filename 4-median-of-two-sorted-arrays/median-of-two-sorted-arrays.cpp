class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        
        int l = 0;
        int r = 0;

        while(l < nums1.size() && r < nums2.size())
        {
            if(nums1[l] <= nums2[r])
            {
                temp.push_back(nums1[l]);
                l++;
            }
            else
            {
                temp.push_back(nums2[r]);
                r++;
            }
        }

        while(l < nums1.size())
        {
            temp.push_back(nums1[l]);
            l++;
        }
        while(r < nums2.size())
        {
            temp.push_back(nums2[r]);
            r++;
        }

        int n = temp.size();

        if(temp.size() % 2 == 0)
        {
            int mid = n/2;
            return (double)(temp[mid-1] + temp[mid]) / 2.0;
        }
        else
        {
            int mid = n/2;
            return (double)(temp[mid]);
            
        }



    }
};