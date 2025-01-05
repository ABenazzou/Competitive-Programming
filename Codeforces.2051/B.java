/*
 * Created: 12/23/24
 * Author: @adnanebenazzou
 * File: B.java
 */

import java.util.*;
import java.lang.*;
import java.io.*;

public class B {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            solve(n, a, b, c);
        }

        out.close();
        sc.close();
    }

    public static int recurseHelper(int n, int a, int b, int c) {
        if (n == 0) return 0;
        if (n <= a) return 1;
        if (n <= a + b) return 2;
        if (n <= a + b + c) return 3;
        int result = 0;
        int left = 0;
//        if (n >= a + b + c) { // by default
        result += 3 * (int) ((double) n / (double) (a + b + c));
        left = n % (a + b + c);
//        }
        return result + recurseHelper(left, a, b, c);

    }

    public static void solve(int n, int a, int b, int c) {
        int res = recurseHelper(n, a, b, c);
        out.println(res);
    }

    //-----------PrintWriter for faster output-------------
    public static PrintWriter out;

    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public MyScanner() {
            this.reader = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (this.tokenizer == null || !this.tokenizer.hasMoreElements()) {
                try {
                    tokenizer = new StringTokenizer(this.reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return this.tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(this.next());
        }

        public long nextLong() {
            return Long.parseLong(this.next());
        }

        public double nextDouble() {
            return Double.parseDouble(this.next());
        }

        public String nextLine() {
            String str = "";
            try {
                str = this.reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public void close() {
            try {
                this.reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
    //-----------------------------------------------------
}