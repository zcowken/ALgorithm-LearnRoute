import java.util.*;

public class LC49_字母异位词分组 {
    public static void main(String[] args) {
        Solution solution = new LC49_字母异位词分组().new Solution();
        List<List<String>> list = solution.groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"});
        System.out.println(list);
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        /**
         * 制作伪哈希
         *
         * @param strs
         * @return
         */
        public List<List<String>> groupAnagrams(String[] strs) {
            Map<String, List<String>> map = new HashMap<>();
            for (String str : strs) {
                int[] charCount = new int[26];
                for(char c : str.toCharArray()){
                    charCount[c - 'a']++;
                }
                String key = Arrays.toString(charCount);
//                System.out.println(key);
                // address getting
                List<String> list = map.get(key);
                if (list == null) {
                    list = new ArrayList<>();
                    map.put(key, list);
                }
                list.add(str);
            }
            return new ArrayList<List<String>>(map.values());
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}