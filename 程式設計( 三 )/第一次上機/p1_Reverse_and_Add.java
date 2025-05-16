import java.util.Scanner;

public class p1_Reverse_and_Add {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        
        for ( int i = 0; i < n; i++ ){
            long num = input.nextLong();
            int count = 0;
            while ( !palindrome(num) ){
                num += reverse_num(num);
                count++;
            }
            System.out.println( count + " " + num );
        }
        input.close();
    }

    public static long reverse_num( long n ){
        long reverse = 0;
        while ( n != 0 ){
            reverse = reverse * 10 + n % 10;
            n /= 10;
        }
        return reverse;
    }

    public static boolean palindrome( long n ){
        String str = new String(n + "");
        for ( int i = 0; i < str.length() / 2; i++ ){
            if ( str.charAt(i) != str.charAt(str.length() - i - 1) ){
                return false;
            }
        }
        return true;
    }
}
