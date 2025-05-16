import java.util.Scanner;

public class p2_StringBuffer_or_Stringbuilder {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for ( int i = 0; i < n; i++ ){
            String str_0 = input.nextLine();
            String str_old = input.nextLine();
            String str_new = input.nextLine();
            StringBuilder builder = new StringBuilder(str_0);
            while ( builder.indexOf(str_old) != -1 ){
                builder.replace( builder.indexOf(str_old), builder.indexOf(str_old) + str_old.length(), str_new );
            }
            System.out.println(builder.reverse());
        }
        input.close();
    }
}