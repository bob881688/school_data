import java.util.Arrays;
import java.util.Scanner;
import java.awt.geom.Point2D;

class Point{
    protected Point2D p1 = new Point2D.Double(0.0, 0.0);
    protected Point2D p2 = new Point2D.Double(0.0, 0.0);
    protected Point2D p3 = new Point2D.Double(0.0, 0.0);

    public Point( double x1, double y1, double x2, double y2, double x3, double y3 ){
        p1.setLocation(x1, y1);
        p2.setLocation(x2, y2);
        p3.setLocation(x3, y3);
    }
};

class Triangle extends Point{
    protected double[] distance = new double[3];
    private double area;

    public Triangle( double x1, double y1, double x2, double y2, double x3, double y3 ){
        super(x1, y1, x2, y2, x3, y3);
        distance[0] = p1.distance(p2);
        distance[1] = p2.distance(p3);
        distance[2] = p3.distance(p1);
        double s = ( distance[0] + distance[1] + distance[2] ) / 2 ;
        area = Math.sqrt(s * ( s - distance[0] ) * ( s - distance[1] ) * ( s - distance[2] ));
    }

    public boolean check(){
        if ( area > 0 ){
            return true;
        }else{
            return false;
        }
    }

    public double getarea(){
        return area;
    }
};

public class p2_Triangle {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        for ( int i = 0; i < n; i++ ){
            double x1 = input.nextDouble();
            double y1 = input.nextDouble();
            double x2 = input.nextDouble();
            double y2 = input.nextDouble();
            double x3 = input.nextDouble();
            double y3 = input.nextDouble();
            Triangle point = new Triangle(x1, y1, x2, y2, x3, y3);

            if ( !point.check() ){
                System.out.println("Just Line!");
            }else{
                Arrays.sort(point.distance);
                System.out.printf("%.3f %.3f %.3f %.3f\n", point.distance[0], point.distance[1], point.distance[2], point.getarea());
            }
        }
        input.close();
    }
}