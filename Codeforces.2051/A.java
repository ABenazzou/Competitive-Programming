/*
 * Created: 12/22/24
 * Author: @adnanebenazzou
 * File: A.java
 */

import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];

            for (int i = 0; i < n; i ++) {
                a[i] = sc.nextInt();
            }

            for (int i = 0; i < n; i ++) {
                b[i] = sc.nextInt();
            }
            solve(a, b, n);
        }

        out.close();
        sc.close();
    }

    public static void solve(int[] a, int[] b, int n) {
       long result = a[n - 1];
       for (int i = n - 2; i >= 0; i --) {
           int diff = a[i] - b[i + 1];
           if (diff > 0) {
               result += diff;
           }
       }
       out.println(result);

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