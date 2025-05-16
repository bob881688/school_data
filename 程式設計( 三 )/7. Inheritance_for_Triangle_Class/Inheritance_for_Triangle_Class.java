import java.text.DecimalFormat;
import java.util.Scanner;

abstract class GeometricObject {
    protected double area;
    protected double perimeter;
    private String color;
    private boolean filled;

    public GeometricObject( String color, boolean filled ){
        this.color = color;
        this.filled = filled;
    }
    public double getarea(){
        return area;
    }
    public double getperimeter(){
        return perimeter;
    }
    public String getcolor(){
        return color;
    }
    public boolean getfilled(){
        return filled;
    }
}
    
class Triangle extends GeometricObject{
    private double side1, side2, side3;
    public Triangle( double side1, double side2, double side3, String color, boolean filled ){
        super(color, filled);
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
        perimeter = side1 + side2 + side3;
        double s = perimeter / 2;
        area = Math.sqrt(s * ( s - side1 ) * ( s - side2 ) * ( s - side3 ));
    }

    public double getside1(){
        return side1;
    }
    public double getside2(){
        return side2;
    }
    public double getside3(){
        return side3;
    }
}

public class Inheritance_for_Triangle_Class {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double side1 = input.nextDouble();
        double side2 = input.nextDouble();
        double side3 = input.nextDouble();
        String color = input.next();
        boolean filled = input.nextBoolean();
        Triangle triangle = new Triangle(side1, side2, side3, color, filled);

        DecimalFormat df = new DecimalFormat("#.#################"); // 最多保留 16 位有效小數

        System.out.printf("Triangle: side1 = %.1f side2 = %.1f side3 = %.1f\n", triangle.getside1(), triangle.getside2(), triangle.getside3());
        System.out.println("The area is " + df.format(triangle.getarea()));
        System.out.printf("The perimeter is %.1f\n", triangle.getperimeter());
        System.out.printf("%s\n", triangle.getcolor());
        System.out.printf("%s\n", triangle.getfilled());
        input.close();
    }
}
