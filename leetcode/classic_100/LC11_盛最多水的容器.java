
public class LC11_盛最多水的容器 {
    public static void main(String[] args) {
//        Solution solution = new ContainerWithMostWater().new Solution();
//        int maxed = solution.maxArea(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7});
//        System.out.println(maxed);
        new LC11_盛最多水的容器().sol2();
    }

    void sol2() {
        Solution2 solution = new LC11_盛最多水的容器().new Solution2();
        int maxed = solution.maxArea(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7});
        System.out.println(maxed);
    }

    // 贪心策略1

    /**
     * 长度永远是变短的，解决了长度和高度的策略选择误区
     */
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int maxArea(int[] height) {
            int ans = 0;
            int left = 0, right = height.length - 1;
            while (left < right) {
                int v_left = height[left];
                int v_right = height[right];
                int curr = (right - left) * Math.min(v_left, v_right);
                ans = Math.max(ans, curr);
                // 移动左边
                if (v_left < v_right) {
                    left += 1;
                }
                // 移动右边
                else if (v_left > v_right) {
                    right -= 1;
                } else {
                    right -= 1;
                }
            }
            return ans;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

    // 贪心策略2-- 错误，无法解决长度和高度的策略区分
    class Solution2 {
        public int maxArea(int[] height) {
            int ans = 0;
            int left = 0, right = 1;
            while (true) {
                int v_left = height[left];
                int v_right = height[right];
                int curr = (right - left) * Math.min(v_left, v_right);
                ans = Math.max(ans, curr);
                int v_next_left = height[left + 1];
                int v_next_right = 0;
                if (right != height.length - 1) {
                    v_next_right = height[right + 1];
                } else {
                    v_next_right = height[height.length - 1];
                }

                int lNextSquare = (right - left - 1) * Math.min(v_next_left, v_right);
                int rNextSquare = (right - left - 1) * Math.min(v_left, v_next_right);

                if (right == height.length - 1) {
                    left += 1;
                } else if (right == left + 1) {
                    right++;
                }
                // 谁最优，谁优先
                else if (rNextSquare > curr && rNextSquare >= lNextSquare) {
                    right++;
                } else if (lNextSquare > curr) {
                    left++;
                }
                // 都不最优，则变长长度
                else {
                    right++;
                }
                // 移动左边
                if (right == left) {
                    break;
                }
            }
            return ans;
        }
    }

}