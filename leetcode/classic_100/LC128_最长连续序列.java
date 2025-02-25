
import java.util.*;

/**
 * 将一个函数分为多段
 */
public class LC128_最长连续序列 {
    public static void main(String[] args) {
        Solution solution = new LC128_最长连续序列().new Solution();
        int res = solution.longestConsecutive(new int[]{100, 4, 200, 1, 3, 2});
//        int res = solution.longestConsecutive(new int[]{1, 0, -1});
        System.out.println(res);
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int longestConsecutive(int[] nums) {
            if (nums.length == 0) return 0;

            int ans = 0;
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < nums.length; i++) {
                set.add(nums[i]);
            }
            // 非有序连续检索
            // 注意不要局部最优错误
            for (Integer num : set) {
                if (set.contains(num - 1)) {
                    continue;
                }

                int currAns = 1;
                int currFindNum = num + 1;
                while (set.contains(currFindNum)) {
                    currFindNum += 1;
                    currAns++;
                }
                // update
                ans = Math.max(ans, currAns);

            }

            return ans;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}