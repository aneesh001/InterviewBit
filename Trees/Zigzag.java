import java.util.*;
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

public class Zigzag {
	public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode A) {
		ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
		if(A == null) {
			return ans;
		}

		Queue<TreeNode> q = new LinkedList<>();
		q.add(A);
		int dir = 1;

		while(!q.isEmpty()) {
			Queue<TreeNode> next = new LinkedList<>();
			ArrayList<Integer> level = new ArrayList<>();

			while(!q.isEmpty()) {
				TreeNode top = q.poll();
				level.add(top.val);

				if(top.left != null) {
					next.add(top.left);
				}
				if(top.right != null) {
					next.add(top.right);
				}
			}

			q = next;
			if(dir == 1) {
				ans.add(level);
				dir = -1;
			}
			else {
				Collections.reverse(level);
				ans.add(level);
				dir = 1;
			}
		}

		return ans;
	}

	public static void main(String[] args) {
		System.out.println("Zigzag.java");
	}
}