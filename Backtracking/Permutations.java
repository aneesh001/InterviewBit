import java.util.*;

public class Permutations {
    public ArrayList<ArrayList<Integer>> permute(ArrayList<Integer> A) {
    	return util(A, A.size() - 1);
    }

    public ArrayList<ArrayList<Integer>> util(ArrayList<Integer> A, int i) {
    	ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

    	if(i < 0) {
    		ans.add(new ArrayList<Integer>());
    		return ans;
    	}

    	ArrayList<ArrayList<Integer>> others = util(A, i - 1);
    	for(ArrayList<Integer> a: others) {
    		for(int j = 0; j <= a.size(); ++j) {
    			ArrayList<Integer> n = new ArrayList<>(a);
    			n.add(j, A.get(i));
    			ans.add(n);
    		}
    	}

    	return ans;
    }

    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	ArrayList<Integer> arr = new ArrayList<>();
    	for(int i = 0; i < n; ++i) {
    		arr.add(sc.nextInt());
    	}

    	Permutations solver = new Permutations();
    	for(ArrayList<Integer> a: solver.permute(arr)) {
    		for(int i: a) {
    			System.out.print(i + " ");
    		}
    		System.out.println();
    	}
    }
}