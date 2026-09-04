import java.util.*;

class LongestCommonSubstring {

    public static void lcs(String str1,String str2) {

        int n = str1.length();
        int m = str2.length();
        int[][] dp = new int[n + 1][m + 1];

        int maxLength = 0;
        int endIndex = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {

                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    
                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        endIndex = i;
                    }

                } else {
                    dp[i][j] = 0;
                }
            }
        }
        String result = str1.substring(
                endIndex - maxLength,
                endIndex
        );
        System.out.println("\nDP Table:");
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("\nLength of Longest Common Substring: "+ maxLength);

        System.out.println("Longest Common Substring: "+ result);
        
    }
}