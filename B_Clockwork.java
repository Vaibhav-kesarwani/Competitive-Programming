import java.util.*;
import java.io.*;
 
public class Main {
   public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int t = Integer.parseInt(br.readLine());
       StringBuilder sb = new StringBuilder();
 
       while (t-- > 0) {
           int n = Integer.parseInt(br.readLine());
           StringTokenizer st = new StringTokenizer(br.readLine());
           int[] a = new int[n];
           boolean allAtLeastTwo = true;
           for (int i = 0; i < n; i++) {
               a[i] = Integer.parseInt(st.nextToken());
               if (a[i] < 2) {
                   allAtLeastTwo = false;
               }
           }
           if (!allAtLeastTwo) {
               sb.append("NO\n");
               continue;
           }
 
           double sum = 0.0;
           for (int num : a) {
               sum += 1.0 / (num - 1);
           }
 
           if (sum > 1.0 + 1e-9) {
               sb.append("NO\n");
           } else {
               sb.append("YES\n");
           }
       }
       System.out.print(sb.toString());
   }
}
