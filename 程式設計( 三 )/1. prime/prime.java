import java.util.Scanner; // 使用scanf的函式，類似 #include <stdio.h>

public class prime { // 用背的，Main 那裡要跟檔名一樣
    public static void main(String[] args) { // 用背的(整行不變)
        Scanner input = new Scanner(System.in); // 使用輸入前要先宣告，input 可以自己改
        while ( input.hasNext() ) { // hasNext() 是如果有下一個輸入，類似scanf() != EOF
            int prime = input.nextInt(); //輸入， nextInt 代表輸入整數型態
            for ( int i = 2; i <= prime; i++ ){
                while ( prime % i == 0 ) {
                    System.out.printf("%d", i);
                    if ( prime != i ){
                        System.out.printf(" ");
                    }
                    prime /= i;
                }
            }
            System.out.printf("\n");
        }
        input.close(); 
    }
}