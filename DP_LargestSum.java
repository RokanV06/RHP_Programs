import java.util.*;

public class Main {

    public static int[] getFSmax(long[][] dp, int row, int c) {

        int[] ans = new int[2];

        int fmax = 0;
        int smax = 0;

        for (int col = 0; col < c; col++) {

            if (dp[row][col] > fmax) {
                smax = fmax;
                fmax = (int) dp[row][col];
            } else if (dp[row][col] > smax) {
                smax = (int) dp[row][col];
            }
        }

        ans[0] = fmax;
        ans[1] = smax;

        return ans;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int r = sc.nextInt();
        int c = sc.nextInt();

        int[][] matrix = new int[r][c];
        long[][] dp = new long[r][c];

        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                matrix[row][col] = sc.nextInt();

                if (row == 0) {
                    dp[row][col] = matrix[row][col];
                }
            }
        }

        for (int row = 1; row < r; row++) {

            int[] fsmax = getFSmax(dp, row - 1, c);

            for (int col = 0; col < c; col++) {

                dp[row][col] = matrix[row][col]
                        + (dp[row - 1][col] == fsmax[0]
                           ? fsmax[1]
                           : fsmax[0]);
            }
        }

        System.out.println(getFSmax(dp, r - 1, c)[0]);

        sc.close();
    }
}