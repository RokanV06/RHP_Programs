import java.util.Scanner;

public class Main {

    public static int[] getFSmaxCol(int[][] dp, int r, int col) {
        int[] ans = new int[2];

        int fmax = 0;
        int smax = 0;

        for (int row = 0; row < r; row++) {
            if (dp[row][col] > fmax) {
                smax = fmax;
                fmax = dp[row][col];
            } else if (dp[row][col] > smax) {
                smax = dp[row][col];
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
        int[][] dp = new int[r][c];

        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                matrix[row][col] = sc.nextInt();

                if (col == 0) {
                    dp[row][col] = matrix[row][col];
                }
            }
        }

        for (int col = 1; col < c; col++) {
            
            int[] fsmax = getFSmaxCol(dp, r, col - 1); 

            for (int row = 0; row < r; row++) {
                dp[row][col] = matrix[row][col]
                        + (dp[row][col - 1] == fsmax[0]
                                ? fsmax[1]
                                : fsmax[0]);
            }
        }

    System.out.println(getFSmaxCol(dp, r, c - 1)[0]);

    }
}