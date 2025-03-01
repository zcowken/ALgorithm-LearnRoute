public class LC23_合并K个升序链表 {
    public static void main(String[] args) {
        int[][] t = { { 1, 4, 5 }, { 1, 3, 4 }, { 2, 6 } };
        Solution s = new LC23_合并K个升序链表().new Solution();
        ListNode[] t2 = new ListNode[t.length];
        for (int i = 0; i < t.length; i++) {
            t2[i] = createList(t[i]);
        }

        ListNode mergeKLists = s.mergeKLists(t2);
        out(mergeKLists);
    }

    static void out(ListNode o) {
        for (; o != null;) {
            System.out.println(o.val);
            o = o.next;
        }
    }

    static ListNode createList(int[] a) {
        ListNode ptr = new ListNode(-1);
        ListNode curr = ptr;
        for (int i = 0; i < a.length; i++) {
            curr.next = new ListNode(a[i]);
            curr = curr.next;
        }
        return ptr.next;
    }

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
    // 分治写法
    class Solution {
        public ListNode mergeKLists(ListNode[] lists) {
            if (lists.length == 0) {
                return null;
            }
            ListNode ptr = new ListNode(-1);
            int len = lists.length;
            for (int slen = 1; slen < len; slen = slen * 2) {
                int gap = slen * 2;
                for (int curr = 0; curr < len - slen; curr += gap) {
                    ListNode h1 = lists[curr];
                    ListNode h2 = lists[curr + slen];
                    ListNode merged = merge(h1, h2);
                    lists[curr] = merged;
                }
            }
            ptr.next = lists[0];

            return ptr.next;
        }

        ListNode merge(ListNode h1, ListNode h2) {

            ListNode ptr = new ListNode(-1);
            ListNode curr = ptr;
            for (; h1 != null && h2 != null;) {
                if (h1.val < h2.val) {
                    curr.next = h1;
                    h1 = h1.next;
                } else {
                    curr.next = h2;
                    h2 = h2.next;
                }
                curr = curr.next;
            }
            if (h1 != null) {
                curr.next = h1;
            }
            if (h2 != null) {
                curr.next = h2;
            }
            return ptr.next;
        }
    }
}