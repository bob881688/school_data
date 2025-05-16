import java.math.BigDecimal;
import java.util.Scanner;
import java.util.StringTokenizer;

public class token1 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        String str = input.nextLine();

        StringTokenizer token = new StringTokenizer(str, "+-*/()% ",true);

        String[] numberarray = new String[100];
        String[] tokenarray = new String[100];
        int numberarray_count = 0, tokenarray_count = 0;

        BigDecimal sum = new BigDecimal(0);
        
        while (token.hasMoreTokens()) {
            String tmp = new String(token.nextToken());
            try {
                BigDecimal transfer = new BigDecimal(tmp);
                sum = sum.add(transfer);
                numberarray[numberarray_count] = tmp;
                numberarray_count++;
            } catch (Exception e) {
                tokenarray[tokenarray_count] = tmp;
                tokenarray_count++;
            }
        }

        for ( int i = 0; i < numberarray_count; i++ ){
            if ( i != numberarray_count - 1 ){
                System.out.print(numberarray[i] + " "); //ff
            }else{
                System.out.print(numberarray[i]);
            }
        }

        System.out.println();

        for ( int i = 0; i < tokenarray_count; i++ ){
            if ( i != tokenarray_count - 1 ){
                System.out.print(tokenarray[i] + " "); //ff
            }else{
                System.out.print(tokenarray[i]);
            }
        }
        System.out.printf("\n%.3f\n", sum);
        input.close();
    }
}