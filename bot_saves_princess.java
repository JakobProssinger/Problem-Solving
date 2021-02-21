import java.io.*;
import java.util.*;
import java.util.Scanner;

// Aufgabenstellung: https://www.hackerrank.com/challenges/saveprincess/problem

public class hello {

    public static void main(String[] args) {
        Scanner scan = new Scanner( System.in );




        int m_x = 0;
        int m_y = 0;

        int p_x = 0;
        int p_y = 0;
        char c;
        String s;

        int n = 3;
        n = Integer.parseInt(scan.nextLine());
        char [][]arr = new char[n][n];

        for(int y = 0; y < n; y++) {
            s = scan.nextLine();
            for(int x = 0; x < n; x++){

                c = s.charAt(x);
                arr[x][y] = c;

                if(arr[x][y] == 'm'){
                    m_x = x;
                    m_y = y;
                } else if (arr[x][y] == 'p' ){
                    p_x = x;
                    p_y = y;
                }
            }
        }
        int x_diff = m_x - p_x;
        int y_diff = m_y - p_y;


        while (y_diff != 0) {

            if(y_diff < 0) {
                System.out.println("DOWN");
                y_diff++;
            } else if (y_diff > 0) {
                System.out.println("UP");
                y_diff--;
            }


        }
        while (x_diff != 0) {

            if(x_diff < 0) {
                System.out.println("RIGHT");
                x_diff++;
            } else if (x_diff > 0) {
                System.out.println("LEFT");
                x_diff--;
            }


        }


        scan.close();
    }
}