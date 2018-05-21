import java.util.ArrayList;

public class PascalTriangle {
    public ArrayList<ArrayList<Integer>> generate(int A) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();

        if(A > 0) {
            ret.add(new ArrayList<>());
            ret.get(0).add(1);

            if(A == 1) {
                return ret;
            }

            for(int i = 1; i < A; ++i) {
                ArrayList<Integer> r = new ArrayList<>();
                ArrayList<Integer> prev = ret.get(i - 1);
                for(int j = 0; j <= i; ++j) {
                    if(j == 0 || j == i) {
                        r.add(1);
                    }
                    else {
                        r.add(prev.get(j) + prev.get(j - 1));
                    }
                }
                ret.add(r);
            }
        }

        return ret;
    }
}
