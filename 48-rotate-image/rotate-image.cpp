class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        //first transpose
        // then reverse each row

        int n = arr.size();

        for(int i=0;i<=n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            int low = 0;
            int high = n-1;

            reverse(arr[i].begin(),arr[i].end());
            // while(low<=high)
            // {
            //     swap(arr[i][low],arr[i][high]);
            //     low++;
            //     high--;
            // }
        }
    }
};