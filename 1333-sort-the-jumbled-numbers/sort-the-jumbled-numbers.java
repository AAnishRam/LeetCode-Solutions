import java.util.Arrays;
import java.util.Comparator;

class Solution {

    public int convert(int[] mapping, int num) {
        if (num == 0) {
            return mapping[0];
        }

        int temp = 0;
        int factor = 1;

        while (num != 0) {
            int digit = num % 10;
            temp = mapping[digit] * factor + temp;
            num = num / 10;
            factor *= 10;
        }
        return temp;
    }

    public int[] sortJumbled(int[] mapping, int[] nums) {
        Integer[] indices = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, new Comparator<Integer>() {
            public int compare(Integer i1, Integer i2) {
                int converted1 = convert(mapping, nums[i1]);
                int converted2 = convert(mapping, nums[i2]);
                return Integer.compare(converted1, converted2);
            }
        });

        int[] sortedNums = new int[nums.length];
        for (int i = 0; i < indices.length; i++) {
            sortedNums[i] = nums[indices[i]];
        }

        return sortedNums;
    }
}
