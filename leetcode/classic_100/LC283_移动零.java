

import java.util.Arrays;

/**
 * class Solution {
 *     public void moveZeroes(int[] nums) {
 *         int n = nums.length, left = 0, right = 0;
 *         while (right < n) {
 *             if (nums[right] != 0) {
 *                 swap(nums, left, right);
 *                 left++;
 *             }
 *             right++;
 *         }
 *     }
 *
 *     public void swap(int[] nums, int left, int right) {
 *         int temp = nums[left];
 *         nums[left] = nums[right];
 *         nums[right] = temp;
 *     }
 * }
 */
public class LC283_移动零 {
    public static void main(String[] args) {
        Solution solution = new LC283_移动零().new Solution();
//        solution.moveZeroes(new int[]{0, 1, 0, 3, 12});
        solution.moveZeroes(new int[]{0, 0, 1});

    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {

        public void swap(int[] arr, int i, int j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        public void moveZeroes(int[] nums) {
            int zeroIndex = -1;
            int numberIndex = -1;
            if (nums.length == 0 || nums.length == 1) {
                System.out.println(Arrays.toString(nums));
                return;
            }
            // 指针初始化
            boolean flag = false;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == 0 && zeroIndex == -1) {
                    zeroIndex = i;
                }
                if (nums[i] != 0&&numberIndex == -1) {
                    numberIndex = i;
                }
                if (zeroIndex != -1 && numberIndex != -1) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                System.out.println(Arrays.toString(nums));
                return;
            }
            // 指针初始化
            while (true) {
                if (zeroIndex > numberIndex) {
                    int f = 0;
                    for (int i = zeroIndex + 1; i < nums.length; i++) {
                        if (nums[i] != 0) {
                            numberIndex = i;
                            f = 1;
                            break;
                        }
                    }
                    if (f == 0) {
                        break;
                    }
                }
                // 交换
                else if (zeroIndex < numberIndex) {
                    int temp = numberIndex;
                    swap(nums, zeroIndex, numberIndex);
                    numberIndex = zeroIndex;
                    // 下一个0位置
                    int f = 0;
                    for (int i = numberIndex + 1; i < nums.length; i++) {
                        if (nums[i] == 0) {
                            zeroIndex = i;
                            f = 1;
                            break;
                        }
                    }
                    if (f == 0) {
                        break;
                    }
                }
            }
            System.out.println(Arrays.toString(nums));
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}