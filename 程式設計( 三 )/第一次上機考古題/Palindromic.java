import java.util.Scanner;

public class Palindromic{
    public static boolean isPrime(int n){
        if(n <= 1){
            return false;
        }
        for(int i = 2; i <= Math.sqrt(n); ++i){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        while ( input.hasNext() ){
            int N = input.nextInt();
            int a = 0;
            for(int i = 2;/* 這裡空著不要寫東西 */; i++){ //這樣就類似進入無窮迴圈，因為沒有設定終止條件例如 i < N
                if ( N == 0 ){
                    break;
                }
                if(isPrime(i)){
                    String str = Integer.toString(i);
                    int flag = 1;
                    for(int j = 0; j <= (str.length() - 1) / 2; ++j){
                        if(str.charAt(j) != str.charAt(str.length() - 1 - j)){
                            flag = 0;
                            break;
                        }
                    }

                    if(flag == 1){ // 代表已經是質數且是回文數
                        a++; // 計算有多少數字符合
                        if ( a % 10 == 0 && a != N ){ //每10個就換行，這樣寫是因為格式要求(又是空格和換行)
                            System.out.println(i);
                        }else if ( a % 10 == 0 && a == N ){
                            System.out.print(i);
                        }else{
                            System.out.print(i + " ");
                        }
                    }
                    
                    if ( a == N ){ // 當a++ 一直到60時，代表已經印出60個數字了，就break跳出for迴圈
                        break;
                    }
                }
            }
            System.out.println();
        }
        input.close(); // 編譯器表示它不開心
    }
}