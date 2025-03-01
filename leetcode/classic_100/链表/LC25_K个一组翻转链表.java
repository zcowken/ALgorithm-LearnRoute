
public class LC25_K个一组翻转链表 {
    public static void main(String[] args) {
        Solution s = new LC25_K个一组翻转链表().new Solution();
        int[] t = { 1, 2, 3, 4, 5 };
        ListNode head = new ListNode(-1);
        ListNode rec = head;

        for (int i = 0; i < t.length; i++) {
            ListNode next = new ListNode(t[i]);
            head.next = next;
            head = next;
        }
        out(rec);
        System.out.println();
        ListNode ans = s.reverseKGroup(rec.next, 2);
        out(ans);

    }

    static void out(ListNode node) {
        for (; node != null;) {
            System.out.print(node.val + " ");
            node = node.next;
        }
    }

    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode() {}
     * ListNode(int val) { this.val = val; }
     * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    class Solution {

        // 1->2->3->4
        public ListNode reverseKGroup(ListNode head, int k) {
            ListNode so = new ListNode(-1);
            ListNode pre = so;
            so.next = head;
            ListNode curr = head;
            int complete = 0;
            for (; curr != null;) {
                ListNode tail = curr;
                for (int cnt = k; cnt > 1; cnt--) {
                    if (tail.next == null) {
                        complete = 1;
                        break;
                    }
                    tail = tail.next;
                }
                if (complete == 1) {
                    break;
                }
                ListNode tailNextBefore = tail.next;
                ListNode[] res = reverseList(curr, tail);
                // 补充连接
                pre.next = res[0];
                res[1].next = tailNextBefore;
                // 下一轮
                pre = curr;
                curr = tailNextBefore;
            }
            return so.next;
        }

        /**
         * 返回反转后的头和尾巴
         */
        ListNode[] reverseList(ListNode head, ListNode tail) {
            ListNode curr = head;
            ListNode pre = null;
            ListNode end = tail.next;
            for (; curr != end;) {
                ListNode next = curr.next;
                curr.next = pre;
                pre = curr;
                curr = next;
            }
            return new ListNode[] { tail, head };
        }
    }
}