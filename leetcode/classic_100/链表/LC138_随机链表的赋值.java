import java.util.HashMap;

public class LC138_随机链表的赋值 {

    // Definition for a Node.
    static class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }

    class Solution {
        public Node copyRandomList(Node head) {
            Node ptr = new Node(-1);
            Node curr = head;
            Node newList = ptr;
            Node head2 = head;
            HashMap<Node, Integer> originPosRecord = new HashMap<Node, Integer>();

            for (int i = 0; head2 != null; i++) {
                originPosRecord.put(head2, i);
                head2 = head2.next;
            }
            HashMap<Integer, Node> posRecord = new HashMap<Integer, Node>();
            HashMap<Integer, Integer> randRecord = new HashMap<Integer, Integer>();
            for (; curr != null;) {
                Node newNode = copNode(curr);
                newList.next = newNode;
                newList = newNode;
                int index = posRecord.size();
                posRecord.put(index, newNode);
                if (curr.random == null) {
                    randRecord.put(index, -1);

                } else {
                    randRecord.put(index, originPosRecord.get(curr.random));

                }
                curr = curr.next;
            }
            // 重新连接新的链表
            Node relinkList = ptr.next;
            int cnt = 0;
            for (; relinkList != null;) {
                int r = randRecord.get(cnt);
                if (r == -1) {
                    relinkList.random = null;
                } else {
                    relinkList.random = posRecord.get(r);
                }
                cnt++;
                relinkList = relinkList.next;
            }
            return ptr.next;

        }

        Node copNode(Node node) {
            Node copy = new Node(node.val);
            return copy;
        }
    }
}