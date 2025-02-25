
import java.util.List;

public class LC42_接雨水 {
    public static void main(String[] args) {
//        Solution solution = new TrappingRainWater().new Solution();
//        int s = solution.trap(new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
//        System.out.println(s);
        new LC42_接雨水().sol2();
    }

    void sol2() {
        Solution2 solution = new Solution2();
        int s = solution.trap(new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
        System.out.println(s);
    }

    // 指针分段解决--错误（无法分段）
    class Solution2 {
        int l;
        int r;

        void init(int[] height) {
            for (int i = 0; i < height.length; i++) {
                if (height[i] > 0) {
                    l = i;
                    break;
                }
            }
            for (int i = l + 1; i < height.length; i++) {
                if (height[i] >= height[l]) {
                    r = i;
                    break;
                }
            }
        }

        public int trap(int[] height) {
            int ans = 0;
            init(height);
            while (l < r) {
                // 遇到一个分段
                if (height[l] <= height[r]) {
                    for (int i = l; i < r; i++) {
                        ans = ans + height[l] - height[i];
                    }
                    l = r;
                    for (int i = l + 1; i < height.length; i++) {
                        if (height[i] >= height[l]) {
                            r = i;
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
            return ans;
        }
    }

    // 找规律形式解决
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int trap(int[] height) {
            int ans = 0;
            int[] leftMax = new int[height.length];
            int[] rightMax = new int[height.length];
            leftMax[0] = height[0];
            for (int i = 1; i < height.length; i++) {
                leftMax[i] = Math.max(leftMax[i - 1], height[i]);
            }
            rightMax[height.length - 1] = height[height.length - 1];
            for (int i = height.length - 2; i >= 0; i--) {
                rightMax[i] = Math.max(rightMax[i + 1], height[i]);
            }
            for (int i = 0; i < height.length; i++) {
                int diff = Math.min(leftMax[i], rightMax[i]) - height[i];
                ans += diff;
            }
            return ans;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}