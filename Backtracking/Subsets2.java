import java.util.*;

public class Subsets2 {
	public ArrayList<ArrayList<Integer>> subsetsWithDup(ArrayList<Integer> A) {
		Collections.sort(A);

		ArrayList<ArrayList<Integer>> ans = util(A, A.size() - 1);

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

    public ArrayList<ArrayList<Integer>> util(ArrayList<Integer> A, int i) {
    	ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

    	if(i < 0) {
    		ans.add(new ArrayList<>());
    		return ans;
    	}

    	Set<ArrayList<Integer>> uniques = new HashSet<>();
    	ArrayList<ArrayList<Integer>> other = util(A, i - 1);
    	for(ArrayList<Integer> a: other) {
    		ArrayList<Integer> n = new ArrayList<>(a);
    		n.add(A.get(i));

    		uniques.add(a);
    		uniques.add(n);
    	}

    	for(ArrayList<Integer> a: uniques) {
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

    	Subsets2 solver = new Subsets2();
    	for(ArrayList<Integer> a: solver.subsetsWithDup(arr)) {
    		for(int i: a) {
    			System.out.print(i + " ");
    		}
    		System.out.println();
    	}
    }
}