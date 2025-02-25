import java.util.HashSet;
import java.util.Set;

public class LC73_矩阵置零 {
    static class Solution {
        public void setZeroes(int[][] matrix) {
            Set<Integer> cols = new HashSet<>();
            Set<Integer> rows = new HashSet<>();
            for (int row = 0; row < matrix.length; row++) {
                for (int col = 0; col < matrix[row].length; col++) {
                    if (matrix[row][col] == 0) {
                        cols.add(col);
                        rows.add(row);
                    }
                }
            }

            for (int row = 0; row < matrix.length; row++) {
                for (int col = 0; col < matrix[row].length; col++) {
                    if (cols.contains(col)||rows.contains(row)) {
                        matrix[row][col] = 0;  
                    }
                }
            }
        }
    }

}
