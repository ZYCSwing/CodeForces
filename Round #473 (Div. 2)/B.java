import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ZYCSwing
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int m = in.nextInt();
            String[] words = new String[n];
            int[] cost = new int[n];
            for (int i = 0; i < n; ++i) {
                words[i] = in.next();
            }
            for (int i = 0; i < n; ++i) cost[i] = in.nextInt();

            int[] min = new int[k];
            Arrays.fill(min, Integer.MAX_VALUE);
            Map<String, Integer> map = new HashMap<>();
            for (int i = 0; i < k; ++i) {
                int x = in.nextInt();
                int index;
                for (int j = 0; j < x; ++j) {
                    index = in.nextInt();
                    map.put(words[index - 1], i);
                    min[i] = Math.min(min[i], cost[index - 1]);
                }
            }
            in.nextLine();

            long res = 0;
            String sen = in.nextLine();
            String[] tmp = sen.split(" ");
            for (String s : tmp) {
                res += min[map.get(s)];
            }
            out.println(res);
        }

    }
}

