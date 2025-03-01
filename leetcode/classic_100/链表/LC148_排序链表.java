public class LC148_排序链表 {

    public static void main(String[] args) {
        Solution s = new LC148_排序链表().new Solution();
        ListNode t = new ListNode(-1);
        int[] ta = { 1 };
        ListNode c = t;
        for (int i = 0; i < ta.length; i++) {
            ListNode newNode = new ListNode(ta[i]);
            c.next = newNode;
            c = c.next;
        }
        ListNode sortList = s.sortList(t.next);
        out(sortList);
    }

    static void out(ListNode o) {
        for (; o != null;) {
            System.out.println(o.val);
            o = o.next;
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
        public ListNode sortList(ListNode head) {
            if (head == null) {
                return head;
            }
            int tlen = getLength(head);
            ListNode newListPtr = new ListNode(-1, head);
            ListNode ans = newListPtr;

            for (int slen = 1; slen < tlen; slen = slen * 2) {
                ListNode curr = newListPtr.next;
                ListNode prev = newListPtr;
                ListNode mList = null;
                for (; curr != null;) {
                    ListNode h1 = curr;
                    for (int i = 1; curr != null && i < slen; i++) {
                        curr = curr.next;
                    }

                    ListNode h1_tail = curr;
                    ListNode h2 = null;
                    // 长度不足时刻
                    if (h1_tail != null) {
                        h2 = h1_tail.next;
                        curr = h1_tail.next;
                        h1_tail.next = null;

                        for (int i = 1; curr != null && i < slen; i++) {
                            curr = curr.next;
                        }
                        // 第二个子链表长度不足
                        if (curr != null) {
                            ListNode h2_tail = curr;
                            curr = h2_tail.next;
                            h2_tail.next = null;
                        }
                    }

                    mList = merge(h1, h2);
                    prev.next = mList;
                    // 移动prev
                    for (; prev.next != null;) {
                        prev = prev.next;
                    }
                }
                ans = newListPtr;
            }

            return ans.next;
        }

        ListNode getTail(ListNode l1) {
            for (; l1 != null;) {
                if (l1.next == null) {
                    return l1;
                }
                l1 = l1.next;
            }
            return null;
        }

        int getLength(ListNode node) {
            int length = 0;
            for (; node != null;) {
                length++;
                node = node.next;
            }
            return length;
        }

        /**
         * 归并合并
         * 使用要求，两个链表是分离开的，他们的tail都是null，否则会有环
         * 
         * @param l1
         * @param l2
         * @return
         */
        ListNode merge(ListNode l1, ListNode l2) {
            ListNode c1 = l1;
            ListNode c2 = l2;
            ListNode ptr = new ListNode(-1);
            ListNode c = ptr;
            for (; c1 != null && c2 != null;) {
                if (c1.val < c2.val) {
                    c.next = c1;
                    c1 = c1.next;
                } else {
                    c.next = c2;
                    c2 = c2.next;
                }
                c = c.next;
            }
            if (c1 != null) {
                c.next = c1;
            }
            if (c2 != null) {
                c.next = c2;
            }
            return ptr.next;
        }
    }
}
