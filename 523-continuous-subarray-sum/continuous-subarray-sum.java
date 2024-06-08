import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> remainderMap = new HashMap<>();
        remainderMap.put(0, -1);  // Initialize with a dummy value.

        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];

            if (k != 0) {
                sum = sum % k;
            }

            if (remainderMap.containsKey(sum)) {
                int prevIndex = remainderMap.get(sum);
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                remainderMap.put(sum, i);
            }
        }

        return false;
    }
}