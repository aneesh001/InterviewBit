import java.util.*;

public class MinStepsInGrid {
    public static int minSteps(int x, int y, int a, int b) {
        int xSteps = Math.abs(x - a);
        int ySteps = Math.abs(y - b);

        int steps1 = 0, steps2 = 0;
        int tmpx = x, tmpy = y;

        steps1 += xSteps;
        x = a;
        if(y > b) y -= xSteps;
        else y += xSteps;
        steps1 += Math.abs(y - b);

        x = tmpx; y = tmpy;
        steps2 += ySteps;
        y = b;
        if(x > a) x -= ySteps;
        else x += ySteps;
        steps2 += Math.abs(x - a);

        System.out.println(steps1 + " " + steps2);
        return Math.min(steps1, steps2);
    }

    public static int coverPoints(ArrayList<Integer> A, ArrayList<Integer> B) {
        int steps = 0;
        int x = A.get(0);
        int y = B.get(0);

        for(int i = 1; i < A.size(); ++i) {
            steps += minSteps(x, y, A.get(i), B.get(i));
        }

        return steps;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        ArrayList<Integer> x = new ArrayList<>();
        ArrayList<Integer> y = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            x.add(sc.nextInt());
            y.add(sc.nextInt());
        }

        System.out.println(coverPoints(x, y));

        sc.close();
    }
}
