import java.util.*;

public class CombinationSum2 {
    public ArrayList<ArrayList<Integer>> combinationSum(ArrayList<Integer> A, int B) {
    	Collections.sort(A);

    	ArrayList<ArrayList<Integer>> ans = util(A, A.size() - 1, B);

        Set<ArrayList<Integer>> uniques = new HashSet<>();
        for(ArrayList<Integer> a: ans) {
            uniques.add(a);
        }

        ans.clear();
        for(ArrayList<Integer> a: uniques) {
            ans.add(a);
        }

    	Collections.sort(ans, new Comparator<ArrayList<Integer>>() {
    		public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
    			int i = 0;
    			int j = 0;

    			while(i < a.size() && j < b.size()) {
    				if(a.get(i) != b.get(j)) {
    					return a.get(i) - b.get(j);
    				}
    				++i;
    				++j;
    			}

    			if(i != a.size()) {
    				return 1;
    			}
    			else if(j != b.size()) {
    				return -1;
    			}
    			else {
    				return 0;
    			}
    		}
    	});

    	return ans;
    }

    public ArrayList<ArrayList<Integer>> util(ArrayList<Integer> A, int i, int B) {
    	ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        if(B == 0) {
            ans.add(new ArrayList<>());
            return ans;
        }

    	if(i < 0 || B < 0) {
    		return ans;
    	}

    	ArrayList<ArrayList<Integer>> a1 = util(A, i - 1, B);
    	ArrayList<ArrayList<Integer>> a2 = util(A, i - 1, B - A.get(i));
    	for(ArrayList<Integer> a: a1) {
    		ans.add(a);
    	}
    	for(ArrayList<Integer> a: a2) {
    		a.add(A.get(i));
    		ans.add(a);
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
    	int sum = sc.nextInt();

    	CombinationSum2 solver = new CombinationSum2();

    	for(ArrayList<Integer> a: solver.combinationSum(arr, sum)) {
    		for(int i: a) {
    			System.out.print(i + " ");
    		}
    		System.out.println();
    	}
    }
}
