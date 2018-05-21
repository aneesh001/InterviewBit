import java.util.List;
import java.util.ArrayList;

public class MaxSumSubArray {
    public static int maxSubArray(final List<Integer> A) {
        int maxSoFar = A.get(0);
        int maxTillHere = A.get(0);

        for(int i = 1; i < A.size(); ++i) {
            maxTillHere = Math.max(maxTillHere + A.get(i), A.get(i));
            maxSoFar = Math.max(maxSoFar, maxTillHere);
        }

        return maxSoFar;
    }

    public static void main(String[] args) {
        List<Integer> a = new ArrayList<Integer>();
        a.add(1);
        a.add(2);
        a.add(3);
        System.out.println(maxSubArray(a));
    }
}
