import java.math.BigDecimal;
import java.util.Stack;
import java.util.StringTokenizer;

class InputExpression {
    public static String[] split_token( String str ){
        StringTokenizer token = new StringTokenizer(str, "+-*/%() ", true);
        Stack<String> stack = new Stack<>();

        while (token.hasMoreTokens()){
            stack.push(token.nextToken());
        }

        return stack.toArray(new String[0]);
    }

    public static String[] postfixStrings( String str ){
        String[] input = split_token(str);
        Stack<String> output = new Stack<>();
        Stack<String> operator = new Stack<>();

        for ( int i = 0; i < input.length; i++ ){
            try{
                BigDecimal num = new BigDecimal(input[i]);
                output.push(num.toString());

            }catch (Exception e) {
                if ( input[i] == "(" ){
                    operator.push(input[i]);
                }else if ( input[i] == ")" ){
                    while ( operator.peek() != "(" ){
                        output.push(operator.pop());
                    }
                    operator.pop();
                }else{
                    while ( !operator.isEmpty() && priority(operator.peek()) >= priority(input[i])){
                        output.push(operator.pop());
                    }
                    operator.pop();
                }
            }
        }

        while ( !operator.isEmpty() ){
            output.push(operator.pop());
        }

        return output.toArray(new String[0]);
    }

    

    public static int priority( String operator ){
        if ( operator == "+" || operator == "-" ){
            return 1;
        }else if ( operator == "*" || operator == "/" || operator == "%" ){
            return 2;
        }else{
            return 0;
        }
    }
    
}
    
public class token3 {
    public static void main(String[] args) {
        InputExpression i = new InputExpression();
        System.out.println(i.split_token("166+2")[1]);
    }
}