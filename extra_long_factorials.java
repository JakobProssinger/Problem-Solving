import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;


// Aufgabenstellung: https://www.hackerrank.com/challenges/extra-long-factorials/problem
public class Solution {

    // Complete the extraLongFactorials function below.
    static void extraLongFactorials(int n) {
        int len = 256;
        int []fac = new int[len];
        fac[0] = 1;
        int carry = 0;
        for(int i = 2; i <= n; i++) {

            for(int j = 0; j < len ; j++) {

                fac[j] = fac[j] * i + carry;

                if(fac[j] >= 10) {
                    carry = fac[j] / 10;
                    fac[j] = fac[j] % 10;
                } else {
                    carry = 0;
                }

            }
        }

        boolean numm = false;
        for(int i = 0; i< fac.length; i++) {


            if(fac[fac.length-1-i] != 0 || numm)
            {
                System.out.print(fac[fac.length-1-i]);
            }

            if(fac[fac.length-1-i] != 0 ) {
                numm = true;
            }
        }

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}
