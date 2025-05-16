import java.util.Scanner;

public class p5_Prime_Factorization {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] arr = new int[1000];
        int index = 0;
        int max = 0;
        while ( input.hasNext() ){
            arr[index] = input.nextInt();
            if ( arr[index] > max ){
                max = arr[index];
            }
            index++; 
        }
        System.out.println( max + " " + (int)Math.sqrt(max) );

        for ( int i = 0; i < index; i++ ){
            System.out.println( PrimeFactorization(arr[i]) );
        }
        input.close();
    }

    public static boolean[] PrimeArray(long N) {
        boolean[] arr = new boolean[(int)N - 1];
        for ( int i = 0; i < N - 1; i++ ) {
            arr[i] = true;
        }
        for ( int p = 2; p * p <= N; p++ ) {
            if ( arr[p - 2] ) {
                for ( int i = p * p; i <= N; i += p ) {
                    arr[i - 2] = false;
                }
            }
        }
        return arr;
    }
    
    public static String PrimeFactorization( long N ){
        StringBuilder str = new StringBuilder();
        long num = N;
        int flag = 0;
        boolean[] bool = PrimeArray(N);
        for ( int i = 0; i < N - 1 && num > 1; i++ ){
            int count = 0;
            if ( bool[i] == true ){
                while ( num % (i + 2) == 0 ){
                    count++;
                    num /= i + 2;
                }

                if ( count > 0 ){
                    if ( count == 1 ){
                        if ( flag == 0 ){
                            str.append(i + 2);
                            flag = 1;
                        }else{
                            str.append(" * ").append(i + 2);
                        }
                    }else{
                        if ( flag == 0 ){
                            str.append(i + 2).append("^").append(count);
                            flag = 1;
                        }else{
                            str.append(" * ").append(i + 2).append("^").append(count);
                        }
                    }
                }
            }
        }
        return str.toString();
    }
}