import java.util.Scanner;

//Reads three parameters and evaluates solutions of quadratic equation
public class Quadratic {
    public static void main(String[] args){
        Scanner reader = new Scanner(System.in);

        System.out.println("Enter parameter that stands by second power of polynomial:");
        double a = reader.nextDouble();
        System.out.println("Enter parameter that stands by first power of polynomial:");
        double b = reader.nextDouble();
        System.out.println("Enter parameter that stands by null power of polynomial:");
        double c = reader.nextDouble();

        double delta = b*b - 4.0D*a*c;

        if(delta < 0){
            System.out.println("Solution no 1:");
            System.out.println(-b/(2.0D*a) + " + " + Math.sqrt(-delta) /(2.0D*a) + "i");
            System.out.println("Solution no 2:");
            System.out.println(-b/(2.0D*a) + " - " + Math.sqrt(-delta) /(2.0D*a) + "i");
        } else {
            System.out.println("Solution no 1:");
            System.out.println(-b/(2.0D*a) + Math.sqrt(delta) /(2.0D*a));
            System.out.println("Solution no 2:");
            System.out.println(-b/(2.0D*a) - Math.sqrt(delta) /(2.0D*a));
        }
    }
}
