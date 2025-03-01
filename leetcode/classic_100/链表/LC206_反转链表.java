public class LC206_反转链表 {

    public static void main(String[] args) {
        Solution s = new Solution();
        ListNode  node = new ListNode();
        s.reverseList();
    }

    /*
     * Definition for singly-linked list.
     * 
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

    static class Solution {
        public ListNode reverseList(ListNode head) {
            ListNode pre = head;
            ListNode curr = head.next;
            ListNode next = head.next.next;
            for (; next != null;) {
                curr.next = pre;
                pre = curr;
                curr = next;
                next = next.next;
            }
            return curr;
        }
    }
}