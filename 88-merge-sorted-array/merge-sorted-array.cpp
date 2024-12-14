class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m + n); // Temporary array to store merged result
        int i = 0, j = 0, k = 0;

        // Merge nums1 and nums2 into temp
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp[k++] = nums1[i++];
            } else {
                temp[k++] = nums2[j++];
            }
        }

        // Copy remaining elements from nums1, if any
        while (i < m) {
            temp[k++] = nums1[i++];
        }

        // Copy remaining elements from nums2, if any
        while (j < n) {
            temp[k++] = nums2[j++];
        }

        // Copy the merged result back to nums1
        for (int t = 0; t < m + n; t++) {
            nums1[t] = temp[t];
        }
    }
};
