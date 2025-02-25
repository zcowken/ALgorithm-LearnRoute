import java.util.List;

public class LC48_旋转图像 {
    public static void main(String[] args) {
        int[][] t = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        Solution s = new LC48_旋转图像().new Solution();
        s.rotate(t);
        for (int[] row : t) {
            for (int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }

    }

    class Solution {
        /**
         * 沿着x和y对称后，再沿y轴对称，就等效旋转45度
         * 如果x是col，y是row
         * x,y-> y,x -> {x_max-y},x
         * 对应的
         * row,col -> col,row -> col, {col_max_index-row}
         */
        class Pii {
            int x;
            int y;
        }

        Pii getRorateXY(int row, int col, int[][] matrix) {
            int row_max = matrix.length - 1;
            int col_max = matrix[0].length - 1;
            Pii pii = new Pii();
            pii.x = col;
            pii.y = col_max - row;
            return pii;
        }

        public void rotate(int[][] matrix) {
            int maxIndex = matrix.length;
            // 旋转区域规划
            int border_x = maxIndex / 2;
            int border_y = maxIndex / 2 + (maxIndex % 2 == 1 ? 1 : 0);

            for (int row = 0; row < border_x; row++) {
                for (int col = 0; col < border_y; col++) {
                    Pii curr = new Pii();
                    curr.x = row;
                    curr.y = col;
                    int cValue = matrix[curr.x][curr.y];
                    while (true) {
                        Pii nextPii = getRorateXY(curr.x, curr.y, matrix);
                        int nextValue = matrix[nextPii.x][nextPii.y];
                        matrix[nextPii.x][nextPii.y] = cValue;
                        curr = nextPii;
                        cValue = nextValue;
                        if (row == curr.x && col == curr.y) {
                            break;
                        }
                    }
                }

            }
        }
    }
}
