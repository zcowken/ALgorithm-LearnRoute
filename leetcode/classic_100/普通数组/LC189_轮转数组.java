public class LC189_轮转数组 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] t = { 1, 2, 3, 4, 5, 6, 7 };
        s.rotate(t, 3);

        // for (int t2 = 0; t2 < t.length; t2++) {
        //     System.out.println(t[t2]);
        // }

    }

    static class Solution {
        public void rotate(int[] nums, int k) {
            int k2 = k % nums.length;
            int n = nums.length;
            reverse(nums, 0, n - 1);
            reverse(nums, 0, k2 - 1);
            reverse(nums, k2, n - 1);
        }

        void reverse(int[] nums, int i, int j) {
            int start = i;
            int end = j;
            for (; start < end;) {
                swap(nums, start, end);
                start++;
                end--;
            }

        }

        void swap(int[] nums, int a, int b) {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;

        }
    }
}