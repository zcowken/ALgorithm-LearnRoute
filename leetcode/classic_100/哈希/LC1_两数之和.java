
import java.util.HashMap;
import java.util.Map;

public class LC1_两数之和 {
    public static void main(String[] args) {
        Solution solution = new LC1_两数之和().new Solution();
        int[] p2s = solution.twoSum(new int[]{3, 2, 4}, 6);
        for (int i = 0; i < p2s.length; i++) {
            System.out.println(p2s[i]);
        }
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> map = new HashMap<>();
            int[] ans = new int[]{0, 0};
            for (int i = 0; i < nums.length; i++) {
                map.put(nums[i], i);
            }
            for (int i = 0; i < nums.length; i++) {
                int complement = target - nums[i];
                if (map.containsKey(complement) && map.get(complement) != i) {
                    ans[0] = i;
                    ans[1] = map.get(complement);
                    return ans;
                }
            }
            return ans;
        }
    }
    //leetcode submit region end(Prohibit modification and deletion)
}