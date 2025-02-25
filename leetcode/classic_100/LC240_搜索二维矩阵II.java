public class LC240_搜索二维矩阵II {
    class Solution {
        public boolean searchMatrix(int[][] matrix, int target) {
            int n = matrix.length;
            int m = matrix[0].length;
            int x = 0;
            int y = m - 1;
            boolean ans = false;
            for (; x < n && y >= 0;) {
                if (matrix[x][y] == target) {
                    ans = true;
                    break;
                }
                if (matrix[x][y] < target) {
                    x++;
                } else {
                    y--;
                }
            }
            return ans;
        }
    }

}
