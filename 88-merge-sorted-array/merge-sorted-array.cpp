class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m==0)
        {
            nums1 = nums2;
            return;
        }


        int a = m-1;
        int b = n-1;
        int c = m+n-1;


        while(a>=0 && b>=0)
        {
            if(nums1[a]<nums2[b])
                nums1[c--] = nums2[b--];
            else
                nums1[c--] = nums1[a--];

        }

        while(b>=0)
        {
            nums1[c--] = nums2[b--];
        }

    }
};