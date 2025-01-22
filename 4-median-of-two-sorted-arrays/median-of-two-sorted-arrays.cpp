class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> temp;
        
        // int l = 0;
        // int r = 0;

        // while(l < nums1.size() && r < nums2.size())
        // {
        //     if(nums1[l] <= nums2[r])
        //     {
        //         temp.push_back(nums1[l]);
        //         l++;
        //     }
        //     else
        //     {
        //         temp.push_back(nums2[r]);
        //         r++;
        //     }
        // }

        // while(l < nums1.size())
        // {
        //     temp.push_back(nums1[l]);
        //     l++;
        // }
        // while(r < nums2.size())
        // {
        //     temp.push_back(nums2[r]);
        //     r++;
        // }

        // int n = temp.size();

        // if(temp.size() % 2 == 0)
        // {
        //     int mid = n/2;
        //     return (double)(temp[mid-1] + temp[mid]) / 2.0;
        // }
        // else
        // {
        //     int mid = n/2;
        //     return (double)(temp[mid]);
            
        // }

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;

        int left = (n1 + n2 + 1) / 2;

        while(low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if(mid1 <= n1-1) r1 = nums1[mid1];
            if(mid2 <= n2-1) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1)
            {
                if((n1 + n2) % 2 == 1)
                    return max(l1, l2);
                else
                    return (double)(max(l1,l2) + min(r1,r2)) / 2.0;
            }
            else if( l1 > r2 ) high = mid1 - 1;
            else
                low = mid1 + 1;
        }

        return 0;



    }
};