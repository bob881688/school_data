import java.util.Scanner;

class Square {
    private int size;
    private int row;
    private int col;
    private int[][] arr;

    public Square( int n ){
        size = n;
        row = n - 1;
        col = n / 2;
        arr = new int[size][size];
    }


    public void fillsquare(){
        for ( int key = 1; key <= size * size; key++ ){
            if ( row < 0 ){
                row = size - 1;
            }
            if ( col < 0 ){
                col = size - 1;
            }
            if ( row >= size ){
                row = 0;
            }
            if ( col >= size ){
                col = 0;
            }

            arr[row][col] = key;

            if ( key % size == 0 ){
                row--;
            }else{
                row++;
                col++;
            }
        }
    }

    public void printsquare(){
        System.out.println( (1 + size * size ) * size / 2 );
        for ( int i = 0; i < size; i++ ){
            for ( int j = 0; j < size; j++ ){
                System.out.printf("%5d", arr[i][j]);
            }
            System.out.println();
        }
    }
    
}


public class Magic_Square {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int flag = 0;
        while ( input.hasNext() ){
            int n = input.nextInt();
            if ( flag == 0 ){
                flag = 1;
            }else{
                System.out.println();
            }

            if ( n % 2 == 0 ){
                System.out.println("It is not an odd number.");
            }else{
                Square square = new Square(n);
                square.fillsquare();
                square.printsquare();
            }
        }
        input.close();
    }
}