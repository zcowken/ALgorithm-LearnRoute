import java.util.HashSet;

public class LC3_无重复字符的最长子串 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.lengthOfLongestSubstring("pwwkew"));
    }

    static class Solution {
        public int lengthOfLongestSubstring(String s) {
            int r = 0;
            int ans = 0;
            HashSet<Character> set = new HashSet<>();
            int n = s.length();
            for (int i = 0; i < n; i++) {
                // 移除窗口外侧的字符
                if (i != 0) {
                    set.remove(s.charAt(i - 1));
                }
                // 无重复字符，就一直更新
                while (r < n && !set.contains(s.charAt(r))) {
                    set.add(s.charAt(r));
                    ++r;
                }
                ans = Math.max(ans, r - i);
            }
            return ans;
        }
    }
}
