import java.util.Scanner;
import java.util.Vector;
import java.util.Comparator;
import java.util.Collections;

class Students implements Comparator<Students>{
    private int math;
    private int english;
    private int chinese;
    private double average;
    public Students( int m, int e, int c ){
        math = m;
        english = e;
        chinese = c;
        average = ( m + e + c ) / 3.0;
    }

    public Students() {}

    public int getmath(){
        return math;
    }
    public int getenglish(){
        return english;
    }
    public int getchinese(){
        return chinese;
    }
    public double getaverage(){
        return average;
    }

    @Override
    public int compare( Students a, Students b ){
        if ( a.getaverage() != b.getaverage() ){
            return (int)Double.compare(b.getaverage(), a.getaverage());
        }
        if ( a.getmath() != b.getmath() ){
            return Integer.compare(b.getmath(), a.getmath());
        }
        if ( a.getenglish() != b.getenglish() ){
            return Integer.compare(b.getenglish(), a.getenglish());
        }

        return Integer.compare(b.getmath(), a.getmath());
    }
}

public class Sorting_the_Students_Scores {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        Vector<Students> list = new Vector<>();
        for ( int i = 0; i< n; i++ ){
            input.next();
            int m = input.nextInt();
            input.next();
            int e = input.nextInt();
            input.next();
            int c = input.nextInt();
            list.add(new Students(m, e, c));
        }

        Collections.sort(list, new Students());

        for ( int i = 0; i < list.size(); i++ ){
            System.out.printf( "%d [M: %d, E: %d, C: %d] Average = %.2f%n", i + 1, list.get(i).getmath(), list.get(i).getenglish(), list.get(i).getchinese(), list.get(i).getaverage() );
        }

        input.close();
    }
}
