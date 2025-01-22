class Solution {
public:

    int findMaxIndex(vector<vector<int>> mat, int col)
    {
        int index = -1;
        int maxi = INT_MIN;
        for(int i = 0; i<mat.size();i++)
        {
            if(maxi < mat[i][col])
            {
                maxi = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            int maxIndex = findMaxIndex(mat, mid);
            int left = -1;
            int right = -1;

            if(mid - 1 >= 0)
                left = mat[maxIndex][mid - 1];
            
            if(mid + 1 < m)
                right = mat[maxIndex][mid + 1];
            

            if(mat[maxIndex][mid] > left && mat[maxIndex][mid] > right)
                return {maxIndex, mid};

            if(left > mat[maxIndex][mid])
                high = mid-1;
            else 
                low = mid + 1;
        }
        return {-1, -1};
    }
};