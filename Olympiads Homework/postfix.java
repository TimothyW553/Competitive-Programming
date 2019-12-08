import java.util.*;
import java.io.*;

public class postfix {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    static Stack<Double> stack;

    static boolean isExpression(String c) {
        return c.equals("*") || c.equals("/") || c.equals("+") || c.equals("-") || c.equals("%") || c.equals("^");
    }

    static double compute(double n, double m, String c) {
        if(c.equals("*")) {
            return n * m;
        } else if(c.equals("/")) {
            return 1 / n * m;
        } else if(c.equals("+")) {
            return n + m;
        } else if(c.equals("-")) {
            return -n + m;
        } else if(c.equals("%")) {
            return m % n;
        } else if(c.equals("^")) {
            return Math.pow(m, n);
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        String str = readLine();
        stack = new Stack<>();
        String[] equation = str.split(" ");
        for(int i = 0; i < equation.length; i++) {
            if(equation[i].charAt(0) >= '0' && equation[i].charAt(0) <= '9') {
                stack.push(Double.parseDouble(equation[i]));
            } else if(isExpression(equation[i])) {
                double n = stack.pop();
                double m = stack.pop();
                stack.push(compute(n, m, equation[i]));
            }
        }
        System.out.printf("%.1f", stack.peek());
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong () throws IOException {
        return Long.parseLong(next());
    }

    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter () throws IOException {
        return next().charAt(0);
    }

    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}
