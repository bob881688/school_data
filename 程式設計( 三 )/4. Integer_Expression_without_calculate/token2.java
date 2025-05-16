import java.math.BigDecimal;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class token2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] array = new String[200];
        int count = 0;
        Stack<String> stack = new Stack<>();
        StringTokenizer token = new StringTokenizer( str, "+-*/()% ", true );
        while ( token.hasMoreTokens() ) {
            array[count] = token.nextToken();
            count++;
        }
        for ( int i = 0; i < count; i++ ){
            try{
                new BigDecimal(array[i]);
                System.out.print( array[i] + " " );
            }catch(Exception e){
                if ( array[i].charAt(0) == '(' ){
                    stack.push(array[i]);
                }else if ( array[i].charAt(0) == '+' || array[i].charAt(0) == '-' || array[i].charAt(0) == '*' || array[i].charAt(0) == '/' || array[i].charAt(0) == '%' ){
                    if ( stack.empty() == false ){
                        while ( priority(stack.peek()) >= priority(array[i]) ){
                            System.out.print( stack.pop() + " " );
                            if ( stack.empty() == true ){
                                break;
                            }
                        }
                    }
                    stack.push(array[i]);
                    
                }else if ( array[i].charAt(0) == ')' ){
                    while ( stack.peek().charAt(0) != '(' ){
                        System.out.print( stack.pop() + " " );
                    }
                    stack.pop();
                }else{
                    System.out.print("12345 ");
                }
            }    
        }
        while (stack.empty() == false) {
            System.out.print(stack.pop() + " ");
        }
        System.out.println();
        input.close();
    }
    public static int priority( String s ){
        if ( s.charAt(0) == '+' || s.charAt(0) == '-' ){
            return 1;
        }else if ( s.charAt(0) == '*' || s.charAt(0) == '/' || s.charAt(0) == '%' ){
            return 2;
        }else{
            return 0;
        }
    }
}