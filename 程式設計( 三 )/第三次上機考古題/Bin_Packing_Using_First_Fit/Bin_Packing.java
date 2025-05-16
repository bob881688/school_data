import java.util.Scanner;
import java.util.Vector;

public class Bin_Packing {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
    
        while ( input.hasNext() ){
            int weight = input.nextInt();
            int number = input.nextInt();
            
            Vector<Integer> old = new Vector<>();
            for ( int i = 0; i < number; i++ ){
                old.add(input.nextInt());
            }

            Vector<Vector<Integer>> packages = new Vector<>();

            while ( !old.isEmpty() ){
                int sum = 0;
                int index = 0;
                Vector<Integer> bin = new Vector<>();
                
                while ( index < old.size() ){
                    if ( sum + old.get(index) <= weight ){
                        sum += old.get(index);
                        bin.add(old.get(index));
                        old.remove(index);
                        index--;
                    }
                    index++;
                }

                packages.add(bin);
            }

            for ( int i = 0; i < packages.size(); i++ ){
                System.out.print( "Container " + (i + 1) + " has : " );
                for ( int j = 0; j < packages.get(i).size(); j++ ){
                    System.out.print( packages.get(i).get(j) + " " );
                }
                System.out.println();
            }
        }
        
        input.close();
    }
}
