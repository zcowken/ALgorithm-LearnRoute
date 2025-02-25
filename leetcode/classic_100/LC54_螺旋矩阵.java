import java.util.ArrayList;
import java.util.List;

public class LC54_螺旋矩阵 {

    public static void main(String[] args) {
        Solution s = new Solution();
    }

    static class Solution {
        int sel_next(int param) {
            return (param + 1) % 4;
        }

        // 碰撞边界
        boolean willCrash(int x, int y, int mx, int my, int[] di, int[][] matrix) {
            int x2 = x + di[0];
            int y2 = y + di[1];
            // 越界
            if (x2 == -1 || x2 == mx || y2 == -1 || y2 == my) {
                return true;
            }
            // 已经走过的位置
            if (matrix[x2][y2] == Integer.MIN_VALUE) {
                return true;
            }
            return false;
        }

        public List<Integer> spiralOrder(int[][] matrix) {
            // 方向数组
            int[][] dis =  { { 0, 1 },{ 1, 0 }, { 0, -1 }, { -1, 0 }};
            int sel = 0;
            int n = matrix.length;
            int m = matrix[0].length;
            List<Integer> ansList = new ArrayList<Integer>();
            for (int row = 0, cnt = 0; cnt < n * m;) {
                for (int col = 0; cnt < n * m; cnt++) {
                    ansList.add(matrix[row][col]);
                    // 最小值设置为已经问
                    matrix[row][col] = Integer.MIN_VALUE;
                    // 移动+转向
                    if (willCrash(row, col, matrix.length, matrix[row].length, dis[sel], matrix)) {
                        sel = sel_next(sel);
                    }
                    // 移动
                    row = row + dis[sel][0];
                    col = col + dis[sel][1];
                }
            }
            return ansList;
        }
    }
}