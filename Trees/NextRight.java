import java.util.*;
import java.io.*;

class TreeLinkNode {
	public int val;
	public TreeLinkNode left;
	public TreeLinkNode right;
	public TreeLinkNode next;

	public TreeLinkNode(int val) {
		this.val = val;
		this.next = this.left = this.right = null;
	}
}

public class NextRight {
	public TreeLinkNode getNextRight(TreeLinkNode node) {
		assert node != null;

		TreeLinkNode tmp = node.next;
		while(tmp != null) {
			if(tmp.left != null) {
				return tmp.left;
			}
			else if(tmp.right != null) {
				return tmp.right;
			}
			else {
				tmp = tmp.next;
			}
		}

		return null;
	}

	public void connect(TreeLinkNode root) {
		TreeLinkNode cur = root;

		while(cur != null) {
			TreeLinkNode tmp = cur;

			while(cur != null) {
				if(cur.left != null && cur.right != null) {
					cur.left.next = cur.right;
					cur.right.next = getNextRight(cur);
				}
				else if(cur.left != null) {
					cur.left.next = getNextRight(cur);
				}
				else if(cur.right != null) {
					cur.right.next = getNextRight(cur);
				}

				cur = cur.next;
			}

			if(tmp.left != null) {
				cur = tmp.left;
			}
			else if(tmp.right != null) {
				cur = tmp.right;
			}
			else {
				cur = getNextRight(tmp);
			}
		}
	}

	public static void main(String[] args) {
		System.out.println("NextRight.java");
	}
}