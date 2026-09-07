import java.io.*;
import java.util.*;

public class NikithaAndBooks {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        if (!br.ready()) return;
        st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            long[] a = new long[n];
            
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st.nextToken());
            }
            
            long surplus = 0;
            boolean possible = true;
            
            for (int i = 0; i < n; i++) {
                long required = i + 1;
                long available = a[i] + surplus;
                
                if (available < required) {
                    possible = false;
                    break;
                }
                
                surplus = available - required;
            }
            
            if (possible) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }
        System.out.print(sb);
    }
}