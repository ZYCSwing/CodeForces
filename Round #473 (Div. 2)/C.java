import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            if (n < 6) {
                out.println(-1);
            } else {
                out.println("1 2");
                for (int i = 3; i <= n; ++i) {
                    if (i % 2 == 0) {
                        out.println("2 " + i);
                    } else {
                        out.println("1 " + i);
                    }
                }
            }

            for (int i = 1; i < n; ++i) {
                out.print(i);
                out.print(" ");
                out.println(i + 1);
            }
        }

    }
}

