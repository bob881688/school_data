import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Vector;

class Rectangle implements Comparator<Rectangle>{
    private int length, width;
    private int area;
    private double diagonal;

    public Rectangle(){};
    public Rectangle( int l, int w ){
        length = l;
        width = w;
        area = computearea();
        diagonal = computediagonal();
    }

    public int computearea(){
        return length * width;
    }
    public double computediagonal(){
        return Math.sqrt( length * length + width * width);
    }

    public int getlen(){
        return length;
    }
    public int getwid(){
        return width;
    }
    public int getArea(){
        return area;
    }
    public double getDia(){
        return diagonal;
    }

    @Override
    public int compare(Rectangle a, Rectangle b){
        if ( a.getArea() > b.getArea() ){
            return -1;
        }else if ( a.getArea() < b.getArea() ){
            return 1;
        }

        if ( a.getDia() < b.getDia() ){
            return -1;
        }else if ( a.getDia() > b.getDia() ){
            return 1;
        }

        return 0;
    }
};

public class Rectangles_Sorting {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        Vector<Rectangle> rectangle = new Vector<>();
        int length, width;
        for ( int i = 0; i < n; i++ ){
            length = input.nextInt();
            width = input.nextInt();
            rectangle.add(new Rectangle(length, width));
        }

        Collections.sort(rectangle, new Rectangle());

        for ( int i = 0; i < rectangle.size(); i++ ){
            System.out.printf("%d:(%d,%d) area= %d diagonal= %.3f\n", i + 1, rectangle.get(i).getlen(), rectangle.get(i).getwid(), rectangle.get(i).getArea(), rectangle.get(i).getDia());
        }

        input.close();
    }
}
