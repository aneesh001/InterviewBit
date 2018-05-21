import java.util.ArrayList;

public class AntiDiagonals {
    public ArrayList<ArrayList<Integer>> diagonal(ArrayList<ArrayList<Integer>> A) {
        int n = A.size();
        int m = A.get(0).size();

        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        for(int c = 0; c < m; ++c) {
            ret.add(new ArrayList<>());
            for(int i = 0, j = c; i < n && j >= 0; ++i, --j) {
                ret.get(ret.size() - 1).add(A.get(i).get(j));
            }
        }
        for(int r = 1; r < n; ++r) {
            ret.add(new ArrayList<>());
            for(int i = r, j = m - 1; i < n && j >= 0; ++i, --j) {
                ret.get(ret.size() - 1).add(A.get(i).get(j));
            }
        }

        return ret;
    }
}
