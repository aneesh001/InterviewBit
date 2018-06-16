import java.uitl.*;
import java.io.*;

class TreeNode {
	public int val;
	public TreeNode left;
	public TreeNode right;

	public TreeNode(int val) {
		this.val = val;
		this.left = this.right = null;
	}
}

public class Flatten {
	public TreeNode flatten(TreeNode a) {
		if(a == null) {
			return null;
		}
		else if(a.left == null && a.right == null) {
			return a;
		}
		else if(a.left == null) {
			a.right = flatten(a.right);
			return a;
		}
		else if(a.right == null) {
			a.right = flatten(a.left);
			a.left = null;
			return a;
		}
		else {
			TreeNode nl = flatten(a.left);
			TreeNode nr = flatten(a.right);

			TreeNode tail = nl;
			while(tail.right != null) {
				tail = tail.right;
			}

			a.right = nl;
			a.left = null;
			tail.right = nr;
			return a;
		}
	}

	public static void main(String[] args) {
		System.out.println("Flatten.java");
	}
}