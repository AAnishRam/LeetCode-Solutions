class Solution {
public:

    long long flowerGame(int n, int m) {
        
        long long nEven = n/2;
        long long nOdd = n-nEven;
        long long mEven = m/2;
        long long mOdd = m-mEven;

        return (nEven*mOdd) + (nOdd*mEven);
    }
};