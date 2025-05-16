import java.text.DecimalFormat;
import java.util.Scanner;

class Complex implements Cloneable{
    private double real;
    private double imag;

    public Complex(){
        real = 0;
        imag = 0;
    }
    public Complex( double real, double imag ){
        this.real = real;
        this.imag = imag;
    }

    public Complex add( Complex other ){
        double newreal = real + other.real;
        double newimag = imag + other.imag;
        return new Complex(newreal, newimag);
    }
    public Complex sub( Complex other ){
        double newreal = real - other.real;
        double newimag = imag - other.imag;
        return new Complex(newreal, newimag);
    }
    public Complex mul( Complex other ){
        double newreal = real * other.real - imag * other.imag;
        double newimag = imag * other.real + real * other.imag;
        return new Complex(newreal, newimag);
    }
    public Complex div( Complex other ){
        double denom = other.real * other.real + other.imag * other.imag;
        double newreal = ( real * other.real + imag * other.imag ) / denom;
        double newimag = ( imag * other.real - real * other.imag ) / denom;
        return new Complex(newreal, newimag);
    }
    public double abs(){
        return Math.sqrt(real * real + imag * imag);
    }

    @Override
    public String toString(){
        DecimalFormat df = new DecimalFormat("0.0000");
        if ( real == 0 ){
            return df.format(imag) + "i";
        }else if ( imag == 0 ){
            return df.format(real);
        }else{
            return df.format(real) + " + " + df.format(imag) + "i";
        }
    }
};

public class Complex_Class {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int flag = 0;

        while ( input.hasNext() ){
            double a = input.nextDouble();
            double b = input.nextDouble();
            double c = input.nextDouble();
            double d = input.nextDouble();

            Complex left = new Complex(a, b);
            Complex right = new Complex(c, d);

            if ( flag != 0 ){
                System.out.println();
                System.out.println();
            }else{
                flag = 1;
            }

            System.out.printf( "(%s) + (%s) = %s\n", left, right, left.add(right) );
            System.out.printf( "(%s) - (%s) = %s\n", left, right, left.sub(right) );
            System.out.printf( "(%s) * (%s) = %s\n", left, right, left.mul(right) );
            System.out.printf( "(%s) / (%s) = %s\n", left, right, left.div(right) );
            System.out.printf( "|%s| = %.4f", left, left.abs());
        }
        input.close();
    }
}
