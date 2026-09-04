import java.util.*;

public class MaximumValueColumnWise {

    static long[] getFSmax(long[][] dp, int col, int n) {
        long fmax = Long.MIN_VALUE;
        long smax = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            if (dp[i][col] > fmax) {
                smax = fmax;
                fmax = dp[i][col];
            } else if (dp[i][col] > smax) {
                smax = dp[i][col];
            }
        }

        return new long[]{fmax, smax};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] a = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        long[][] dp = new long[n][m];

        for (int i = 0; i < n; i++) {
            dp[i][0] = a[i][0];
        }

        for (int j = 1; j < m; j++) {
            long[] fmax = getFSmax(dp, j - 1, n);

            for (int i = 0; i < n; i++) {
                dp[i][j] = a[i][j]
                        + (dp[i][j - 1] == fmax[0] ? fmax[1] : fmax[0]);
            }
        }

        long ans = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, dp[i][m - 1]);
        }

        System.out.println(ans);

        sc.close();
    }
}