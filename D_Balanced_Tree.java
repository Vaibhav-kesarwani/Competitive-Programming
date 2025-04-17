import java.io.*;
import java.util.*;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static List<Integer>[] adj;
    static int[] l, r;
    static List<Integer> fixedNodes;
    static boolean possible;

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        int t = fr.nextInt();
        while (t-- > 0) {
            int n = fr.nextInt();
            l = new int[n + 1];
            r = new int[n + 1];
            fixedNodes = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                l[i] = fr.nextInt();
                r[i] = fr.nextInt();
                if (l[i] == r[i]) {
                    fixedNodes.add(i);
                }
            }
            adj = new List[n + 1];
            for (int i = 1; i <= n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                int u = fr.nextInt();
                int v = fr.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }

            possible = true;
            int S = 0;
            for (int node : fixedNodes) {
                S = Math.max(S, l[node]);
            }

            for (int node : fixedNodes) {
                if (l[node] > S) {
                    possible = false;
                    break;
                }
                boolean found = false;
                for (int parent : adj[node]) {
                    if (l[parent] <= S - (S - l[node]) && S - (S - l[node]) <= r[parent]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    possible = false;
                    break;
                }
            }

            System.out.println(possible ? S : -1);
        }
    }
}

