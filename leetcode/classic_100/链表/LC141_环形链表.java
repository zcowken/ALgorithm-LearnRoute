public class LC141_环形链表 {

    /**
     * Definition for singly-linked list.
     * class ListNode {
     * int val;
     * ListNode next;
     * ListNode(int x) {
     * val = x;
     * next = null;
     * }
     * }
     */
    /**
     * 快慢指针法
     */
    class Solution {
        public boolean hasCycle(ListNode head) {
            if (head == null) {
                return false;
            }
            ListNode fptr = head.next;
            ListNode sptr = head;
            while (sptr != fptr) {
                if (fptr == null || fptr.next == null) {
                    return false;
                }
                fptr = fptr.next.next;
                sptr = sptr.next;
            }
            return true;
        }
    }
}
