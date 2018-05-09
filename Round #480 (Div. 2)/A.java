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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            int cntp = 0, cntl = 0;
            for (char ch : s.toCharArray()) {
                if (ch == 'o') {
                    ++cntp;
                } else {
                    ++cntl;
                }
            }
            if (cntp == 0 || cntl % cntp == 0) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }

    }
}

