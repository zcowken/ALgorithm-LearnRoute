/**
 * 此题目可以尝试一下，学习答案的分治写法
 */
public class LC53_最大子数组和 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] t = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        int ans = s.maxSubArray(t);
        ;
        System.out.println(ans);
    }
    
    static class Solution {
        public int maxSubArray(int[] nums) {
            int[] f = new int[nums.length];
            f[0] = nums[0];
            for (int i = 1; i < nums.length; i++) {
                f[i] = Math.max(nums[i] + f[i - 1], nums[i]);
            }
            int ans = f[0];
            for (int i = 0; i < nums.length; i++) {
                ans = Math.max(ans, f[i]);
            }
            // for (int i : f) {
            //     System.err.println(i);
            // }
            return ans;
        }
    }
}
