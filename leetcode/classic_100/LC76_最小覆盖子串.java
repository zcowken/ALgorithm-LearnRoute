import java.util.Arrays;

public class LC76_最小覆盖子串 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String ans = s.minWindow("a", "a");
        System.out.println(ans);

    }

    static class Solution {
        public String minWindow(String s, String t) {
            int ansR = -1, ansL = 0;
            int r = 0;
            int[] counts = new int[128];
            int[] curr = new int[128];
            Arrays.fill(counts, 0);
            Arrays.fill(curr, 0);
            for (int i = 0; i < t.length(); i++) {
                counts[t.charAt(i)] += 1;
            }
            // 移动左指针
            for (int i = 0; i < s.length(); i++) {
                // 右指针移动的情况
                while (r < s.length() && !isCoverd(counts, curr)) {
                    curr[s.charAt(r)]++;
                    r++;
                }
                // 如果更短，且满足覆盖条件，更新左右边界
                if ((ansR - ansL > r - i || ansR == -1) && isCoverd(counts, curr)) {
                    ansL = i;
                    ansR = r;
                }
                curr[s.charAt(i)]--;
            }
            // System.out.println(ansL);
            // System.out.println(ansR);
            if (ansR == -1) {
                return "";
            }
            return s.substring(ansL, ansR);
        }

        boolean isCoverd(int[] counts, int[] currState) {
            // 如果没有覆盖所有的字符，返回false，满足了，返回true
            for (int i = 'A'; i <= 'Z'; i++) {
                if (currState[i] < counts[i]) {
                    return false;
                }
            }
            for (int i = 'a'; i <= 'z'; i++) {
                if (currState[i] < counts[i]) {
                    return false;
                }
            }
            return true;
        }
    }

}