import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class LC160_相交链表 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode(int x) {
     * val = x;
     * next = null;
     * }
     * }
     */

    static class Solution {
        class ListNode {
            ListNode next;
            int val;

            ListNode(int x) {
                val = x;
                next = null;
            }
        }

        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            HashSet<ListNode> aSet = new HashSet<ListNode>();
            ListNode curr = headA;
            for (; curr != null;
            curr = curr.next
            ) {
                aSet.add(curr);
            }
            curr = headB;
            for (; curr != null;
            curr = curr.next
            ) {
                if (aSet.contains(curr)) {
                    return curr;
                }
            }
            return null;
        }
    }

}
