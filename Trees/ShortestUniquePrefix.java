import java.util.*;
import java.io.*;

public class ShortestUniquePrefix {
	class Node {
		static final int SZ = 26;
		int[] next;
		int[] count;

		Node() {
			next = new int[SZ];
			count = new int[SZ];
			for(int i = 0; i < SZ; ++i) {
				next[i] = -1;
				count[i] = 0;
			}
		}
	}

	int charToInt(char ch) {
		return Character.getNumericValue(ch) - Character.getNumericValue('a');
	}

	ArrayList<Node> buildTrie(ArrayList<String> list) {
		ArrayList<Node> trie = new ArrayList<>();
		trie.add(new Node());

		for(String s: list) {
			int current = 0;
			for(int i = 0; i < s.length(); ++i) {
				char c = s.charAt(i);
				if(trie.get(current).next[charToInt(c)] != -1) {
					trie.get(current).count[charToInt(c)] += 1;
					current = trie.get(current).next[charToInt(c)];
				}
				else {
					trie.add(new Node());
					trie.get(current).count[charToInt(c)] += 1;
					trie.get(current).next[charToInt(c)] = trie.size() - 1;
					current = trie.size() - 1;
				}
			}
		}

		return trie;
	}

	public void printTrie(ArrayList<Node> trie) {
		for(int i = 0; i < trie.size(); ++i) {
			System.out.print(i + " : ");
			for(int i = 0; i < Node.SZ; ++i) {
				if(trie.get(current).next[i] != -1) {
					System.out.print("{" + ('a' + i) + " , " + trie.get(current).next[i] + "}");
				}
				System.out.println();
			}
		}
	}

	public String findPrefix(ArrayList<Node> trie, String s) {
		int current = 0;
		for(int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if(trie.get(current).count[charToInt(c)] == 1) {
				return s.substring(0, i + 1);
			}
			else {
				current = trie.get(current).next[charToInt(c)];
			}
		}
		return s;
	}

	public ArrayList<String> prefix(ArrayList<String> list) {
		ArrayList<Node> trie = buildTrie(list);

		ArrayList<String> ans = new ArrayList<>();
		for(String s: list) {
			ans.add(findPrefix(trie, s));
		}

		return ans;
	}

	public static void main(String[] args) {
		System.out.println("ShortestUniquePrefix.java");
	}
}