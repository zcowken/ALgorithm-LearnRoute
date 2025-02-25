public class LC41_缺失的第一个正数 {

    public static void main(String[] args) {
        int[] t = { 0 };
        Solution s = new Solution();
        int a = s.firstMissingPositive(t);
        ;
        System.out.println(a);
    }

    /**
     * 方法--原地哈希
     */
    static class Solution {
        public int firstMissingPositive(int[] nums) {
            /**
             * 规定正值的映射含义为数字未出现在nums中。
             */
            int n = nums.length;
            // 负数和0数mapping为正数
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] <= 0) {
                    nums[i] = n + 1;
                }
            }
            // 标记已有的数对应下标为负数(标记范围为1-n。
            for (int i = 0; i < nums.length; i++) {
                int curr = Math.abs(nums[i]);
                // 0 的位置存放数字n是否存在（负数和0--存在，正数--不存在
                // 只操作范围内的数
                if (curr < n) {
                    // 记录nums[i]位置已经被使用,负数标记已经使用
                    nums[curr] = -1 * Math.abs(nums[curr]);
                } else if (curr == n) {
                    nums[0] = -1 * Math.abs(nums[0]);
                }
            }
            // 答案检测
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] > 0) { // 正值代表数字i存在
                    return i;
                }
            }
            if (nums[0] > 0) {
                return n;
            }
            return n + 1;
        }
    }
}