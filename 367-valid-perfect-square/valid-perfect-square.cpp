class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num/2;

        if(num==1)return true;

        int mid;

        while(low<=high)
        {
            mid = (low+high)/2;

            if(mid == num/mid && num%mid == 0)
                return true;

            if(mid <num/mid)
                low = mid+1;
            else
                high = mid-1;

        }
        return false;

    }
};