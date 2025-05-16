import java.util.Scanner;

public class p4_Latin_Square {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n;
        while ( (n = input.nextInt()) != -1 ){
            int flag = 0;
            char[][] latin = new char[n][n];
            for ( int i = 0; i < n; i++ ){
                for ( int j = 0; j < n; j++ ){
                    latin[i][j] = input.next().charAt(0);
                    if ( latin[i][j] - 'A' > n - 1 ){
                        flag = 1;
                    }
                }
            }

            if ( flag != 1 ){
                for ( int i = 0; i < n; i++ ){
                    boolean[] col = new boolean[n];
                    for ( int j = 0; j < n; j++ ){
                        if ( col[latin[i][j] -'A'] != true ){
                            col[latin[i][j] - 'A'] = true;
                        }else{
                            flag = 1;
                            break;
                        }
                    }
                    if ( flag == 1 ){
                        break;
                    }
                }
            }

            if ( flag != 1 ){
                for ( int i = 0; i < n; i++ ){
                    boolean[] row = new boolean[n];
                    for ( int j = 0; j < n; j++ ){
                        if ( row[latin[j][i] -'A'] != true ){
                            row[latin[j][i] - 'A'] = true;
                        }else{
                            flag = 1;
                            break;
                        }
                    }
                    if ( flag == 1 ){
                        break;
                    }
                }
            }

            if ( flag == 1 ){
                System.out.println("The input array is not a Latin square.");
            }else{
                System.out.println("The input array is a Latin square.");
            }
        }
        input.close();
    }
}