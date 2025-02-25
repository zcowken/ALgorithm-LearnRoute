import java.util.ArrayList;
import java.util.Comparator;
import java.util.Deque;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.stream.IntStream;

public class LC239_滑动窗口最大值 {
    public static void main(String[] args) {
        Solution2 s = new Solution2();
        int[] arr = { 1, 3, -1, -3, 5, 3, 6, 7 };
        int[] ans = s.maxSlidingWindow(arr, 3);

        for (int i = 0; i < ans.length; i++) {
            System.out.println(ans[i]);
        }
    }

    /**
     * 写法1，使用nlogn写法，使用栈进行维护书写
     */
    static class Solution {
        public int[] maxSlidingWindow(int[] nums, int k) {
            ArrayList<Integer> ans = new ArrayList<Integer>();
            // 定于优先队列
            PriorityQueue<PP> pQueue = new PriorityQueue<PP>(new Comparator<PP>() {
                public int compare(PP p1, PP p2) {
                    if (p1.val == p2.val) {
                        return p2.index - p1.index;
                    }
                    return p2.val - p1.val;
                }
            });
            for (int i = 0; i < k; i++) {
                PP p = new PP();
                p.index = i;
                p.val = nums[i];
                pQueue.offer(p);
            }
            ans.add(pQueue.peek().val);
            for (int i = k; i < nums.length; i++) {
                PP p = new PP();
                p.index = i;
                p.val = nums[i];
                // 移动区间，加入新的数值
                pQueue.offer(p);
                while (pQueue.peek().index <= i - k) {
                    pQueue.poll();
                }
                ans.add(pQueue.peek().val);

            }
            // 返回答案数组，转换为数值流
            int[] ansList = IntStream.range(0, ans.size())
                    .map(i -> ans.get(i))
                    .toArray();
            return ansList;
        }

        class PP {
            int index;
            int val;
        }
    }

    /**
     * 写法2，使用n写法，利用单调队列
     */
    static class Solution2 {
        public int[] maxSlidingWindow(int[] nums, int k) {
            ArrayList<Integer> ans = new ArrayList<Integer>();
            Deque<Integer> q = new LinkedList<Integer>();
            for (int i = 0; i < k; i++) {
                // 维护单调队列的的最大值
                // 右边开始小的移除
                while (!q.isEmpty() && nums[q.peekLast()] <= nums[i]) {
                    q.pollLast();
                }
                q.add(i);
                // 左边移除坐标不满足的
                // 这个弹出条件在此循环一定不成立
                // while (!q.isEmpty() && q.getFirst() <= i - k) {
                // q.pop();
                // }
            }
            ans.add(nums[q.getFirst()]);
            for (int i = k; i < nums.length; i++) {
                // 弹出右侧更小的值
                while (!q.isEmpty() && nums[q.peekLast()] <= nums[i]) {
                    q.pollLast();
                }
                q.add(i);
                // 左边移除坐标不满足的
                // 这个弹出条件在此循环一定不成立
                while (!q.isEmpty() && q.getFirst() <= i - k) {
                    q.pop();
                }
                ans.add(nums[q.getFirst()]);
            }
            return IntStream.range(0, ans.size()).map(i -> ans.get(i)).toArray();
        }
    }
}
