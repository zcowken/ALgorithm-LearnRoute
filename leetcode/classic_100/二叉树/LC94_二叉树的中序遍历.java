package 二叉树;

import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

import org.w3c.dom.Node;

public class LC94_二叉树的中序遍历 {
    public static void main(String[] args) {
        Integer[] t = { 1, null, 2, 3 };
        TreeNode node = createNode(t, 0);
        // out(node);
        Solution s = new LC94_二叉树的中序遍历().new Solution();
        List<Integer> ans = s.inorderTraversal(node);

        for (Integer it : ans) {
            System.out.println(it);
        }
    }

    /**
     * Definition for a binary tree node.
     */
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    // static void createTreeByArray(Integer[] arr) {
    // // 左子树优先建树法
    // TreeNode root = createNode(arr, 0);
    // }
    // 左子树优先建树法，先建立左子树，再建立右子树
    static TreeNode createNode(Integer[] arr, int index) {

        if (index >= arr.length || arr[index] == null) {
            return null;
        }
        TreeNode node = new TreeNode(arr[index]);
        node.left = createNode(arr, index + 1);
        node.right = createNode(arr, index + 2);
        return node;
    }

    // 先序遍历输出
    static void out(TreeNode node) {
        if (node == null) {
            return;
        }
        System.out.println(node.val);
        out(node.left);
        out(node.right);
    }

    class Solution {
        void midOut(TreeNode node, List<Integer> record) {
            if (node == null) {
                return;
            }
            midOut(node.left, record);
            record.add(node.val);
            midOut(node.right, record);
        }

        class Pii {
            int op;// op =0,普通操作，无进行输出；op=1，进行输出，需要弹出一个数据栈
            TreeNode node;

            Pii() {
                op = 0;
                node = null;
            }

            Pii(int op, TreeNode node) {
                this.op = op;
                this.node = node;
            }
        }

        List<Integer> structOut(TreeNode node) {

            List<Integer> record = new ArrayList<Integer>();

            Deque<Pii> stack = new LinkedList<>();

            stack.push(new Pii(0, node));

            for (; !stack.isEmpty();) {
                Pii curr = stack.pop();
                TreeNode currNode = curr.node;
                if (currNode == null) {
                    continue;
                }
                if (curr.op == 0) {
                    stack.push(new Pii(0, currNode.right));
                    stack.push(new Pii(1, currNode));
                    stack.push(new Pii(0, currNode.left));
                } else if (curr.op == 1) {
                    record.add(currNode.val);
                }
            }
            return record;
        }

        public List<Integer> inorderTraversal(TreeNode root) {
            List<Integer> ans = new ArrayList<Integer>();
            ans = structOut(root);
            return ans;
        }
    }
}
