
import java.util.*;

public class LC15_三数之和 {
    public static void main(String[] args) {
        Solution solution = new LC15_三数之和().new Solution();
        List<List<Integer>> lists = solution.threeSum(new int[]{-1, 0, 1, 0});
        System.out.println(lists);
    }

    /**
     * 存在第二种枚举方式
     * 枚举两个数字，第三个数字通过哈希表查询
     * 速度为3*（N-1)N
     */
    // 指针法
    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> ans = new ArrayList<>();
            int[] array = Arrays.stream(nums).sorted().toArray();
            // 选择标定物target
            for (int i = 0; i <= array.length - 3; i++) {
                // 保证不枚举相同的target,保证了答案的不重复
                if (i >= 1 && array[i] == array[i - 1]) {
                    continue;
                }
                int l = i + 1;
                int r = array.length - 1;
                // 对l，r顺序指针寻找目标target
                int target = -array[i];
                while (l < r) {
                    // 保证不枚举相同的左指针（保证了左指针对应的值不重复，右指针的值必然不重复
                    if (l >= i + 2 && array[l] == array[l - 1]) {
                        l++;
                        continue;
                    }
                    int sum = array[l] + array[r];
                    if (sum == target) {
                        List<Integer> list = new ArrayList<>();
                        list.add(array[i]);
                        list.add(array[l]);
                        list.add(array[r]);
                        ans.add(list);
                        l++;
                    } else if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    }
                }
            }

            return ans;
        }

    }
//leetcode submit region end(Prohibit modification and deletion)

}