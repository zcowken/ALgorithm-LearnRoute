public class LC238_除自身以外数组的乘积 {

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] t = { 1, 2, 3, 4 };
        int[] ans = s.productExceptSelf(t);;
        for (int ans2 : ans) {
            System.out.println(ans2);
        }
    }

    static class Solution {
        public int[] productExceptSelf(int[] nums) {
            int n = nums.length;
            int[] lPre = new int[n];
            int[] rPre = new int[n];
            lPre[0] = 1;
            rPre[n - 1] = 1;
            for (int i = 1; i < n; i++) {
                lPre[i] = lPre[i - 1] * nums[i - 1];
            }
            for (int i = n - 2; i >= 0; i--) {
                rPre[i] = rPre[i + 1] * nums[i + 1];
            }
            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                ans[i] = lPre[i] * rPre[i];
            }
            return ans;
        }
    }
}
