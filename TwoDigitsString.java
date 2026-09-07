import java.util.Scanner;

public class TwoDigitsString {
    static void main() {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        int[] mx = new int[s1.length()];
        int[] my = new int[s2.length()];
        mx[0] = s1.charAt(0) - '0';
        my[0] = s2.charAt(0) - '0';
        for (int i = 1; i < s1.length(); i++) {
            mx[i] = (mx[i - 1] + (s1.charAt(i) - '0')) % 10;
        }
        for (int i = 1; i < s2.length(); i++) {
            my[i] = (my[i - 1] + (s2.charAt(i) - '0')) % 10;
        }
        if (mx[mx.length - 1] != my[my.length - 1]) {
            System.out.println("-1");

        } else {
            int[][] dp = new int[s1.length() + 1][s2.length() + 1];
            for (int i = 1; i <= mx.length; i++) {
                for (int j = 1; j <= my.length; j++) {
                    if (mx[i - 1] == my[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            System.out.println(dp[mx.length][my.length]);
        }
    }
}