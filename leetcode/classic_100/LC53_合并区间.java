import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class LC53_合并区间 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] t = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
        int[][] merge = s.merge(t);
        for (int[] is : merge) {
            for (int it : is) {
                System.out.print(it + " ");
            }
            System.out.println();
        }

    }

    static class Solution {
        public int[][] merge(int[][] intervals) {
            // sort
            Arrays.sort(intervals, new Comparator<int[]>() {
                public int compare(int[] interval1, int[] interval2) {
                    return interval1[0] - interval2[0];
                }
            });
            int[] curr = intervals[0];

            List<int[]> ansList = new ArrayList<int[]>();
            for (int i = 1; i < intervals.length; i++) {
                if (curr[1] >= intervals[i][0]) {
                    curr[1] = Math.max(intervals[i][1], curr[1]);
                } else {
                    ansList.add(curr);
                    curr = intervals[i];
                }
            }
            ansList.add(curr);
            return ansList.toArray(new int[ansList.size()][]);
        }

    }
}
