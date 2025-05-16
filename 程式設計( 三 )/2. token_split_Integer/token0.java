import java.util.Scanner;
import java.util.StringTokenizer;
public class token0 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int sum = 0, flag = 0;
        
        StringTokenizer token = new StringTokenizer( str, "+-*/ " );

        while (token.hasMoreTokens()) {
            try {
                int num = Integer.parseInt(token.nextToken());
                sum += num;
                if ( flag == 1 ){
                    System.out.printf(" ");
                }else{
                    flag = 1;
                }
                System.out.printf( "%s", num );
            } catch (Exception e) {

            }
        }

        System.out.printf( "\n%d\n", sum );
        input.close();
    }
}