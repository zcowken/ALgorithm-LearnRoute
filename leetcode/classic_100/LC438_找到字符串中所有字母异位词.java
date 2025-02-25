import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC438_找到字符串中所有字母异位词 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.findAnagrams("cbaebabacd", "abc"));
    }

    static class Solution {
        // S是原始字符串，p是规则字符串
        public List<Integer> findAnagrams(String s, String p) {
            /**
             * 滑动窗口
             */
            int[] counts = new int[26];

            Arrays.fill(counts, 0);
            int differ = 0;
            // 获取长度
            int sLen = s.length();
            int pLen = p.length();

            // List<Integer> ansList = Collections.emptyList(); // 此种方式创建的列表不可以修改
            if (sLen < pLen) {
                return new ArrayList<Integer>();
            }
            List<Integer> ansList = new ArrayList<Integer>();
            
            // 初始化第一个滑动窗口
            for (int i = 0; i < pLen; i++) {
                // 规定counts的含义为，s字符串，在滑动窗口中和p字符串，含有的对应字符的不相似度
                counts[s.charAt(i) - 'a']++;
                counts[p.charAt(i) - 'a']--;
            }
            // 初始化不相似度
            for (int i = 0; i < 26; i++) {
                if (counts[i] != 0) {
                    differ++;
                }
            }

            // 如果第一个区间复合要求
            if (differ == 0) {
                ansList.add(0);
            }

            // 遍历滑动窗口的左指针
            for (int i = 0; i < sLen - pLen; i++) {
                // 移动滑动窗口
                if (counts[s.charAt(i) - 'a'] == 1) {
                    differ -= 1;
                } else if (counts[s.charAt(i) - 'a'] == 0) {
                    differ += 1;
                }
                // 恢复滑动窗口左侧的性质
                counts[s.charAt(i) - 'a'] -= 1;

                // 右指针的变化，移动到下一个右指针位置
                if (counts[s.charAt(i + pLen) - 'a'] == -1) {
                    differ -= 1;
                } else if (counts[s.charAt(i + pLen) - 'a'] == 0) {
                    differ += 1;
                }
                counts[s.charAt(i + pLen) - 'a'] += 1;

                // 窗口移动完毕，判断答案
                if (differ == 0) {
                    ansList.add(i + 1);
                }
            }

            return ansList;
        }
    }
}
