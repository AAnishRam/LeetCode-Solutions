class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;
        int left = weights[0];
        int right = 0;
        for (int i = 0; i < n; i++){
            right += weights[i];
            left = Math.max(left, weights[i]);
        }
        int res = left;
        while (left <= right){
            int mid = (left + right) / 2;

            int no_of_days = 1;
            int temp = 0;
            for (int i = 0; i < n; i++){
                if (temp + weights[i] > mid){
                    no_of_days++;
                    temp = 0;
                }
                temp += weights[i];
            }
            if (no_of_days <= days){
                res = mid;
                right = mid - 1;
            }
            else if (no_of_days > days){
                left = mid + 1;
            }
        }
        return res;
    }
}