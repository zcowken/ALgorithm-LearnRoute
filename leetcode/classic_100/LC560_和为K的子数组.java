import java.util.Arrays;
import java.util.HashMap;

public class LC560_和为K的子数组 {

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = { 1, 2, 3 };
        System.out.println(s.subarraySum(nums, 3));
    }

    static class Solution {
        public int subarraySum(int[] nums, int k) {
            int ans = 0;
            int[] sums = new int[nums.length];
            Arrays.fill(sums, 0);
            sums[0] = nums[0];
            HashMap<Integer, Integer> vMap = new HashMap<Integer, Integer>();
            for (int i = 1; i < nums.length; i++) {
                sums[i] = sums[i - 1] + nums[i];
            }
            // 初始化哈希表
            vMap.put(0, 1);
            for (int i = 0; i < nums.length; i++) {
                // 如果有满足要求的前边界j的值复合要求以下
                int tar = sums[i] - k;
                if (vMap.containsKey(tar)) {
                    ans += vMap.get(tar);
                }
                vMap.put(sums[i], vMap.getOrDefault(sums[i], 0) + 1);
            }

            return ans;
        }
    }
}