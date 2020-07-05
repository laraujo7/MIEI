import java.util.Scanner;
import java.lang.Math;

public class Ex5 {

    public static void cls()  {
        System.out.println("\033[H\033[2J");
        System.out.flush();
    }

    public static void main(String[] arg){
        double base,altura;
        boolean valido = true;

        cls();

        while (valido) {

            System.out.println("Indique a base e a altura do triangulo : ");

            Scanner scanner = new Scanner(System.in);

            String lines = scanner.nextLine();

            String[] strs = lines.trim().split("\\s+");

            if (strs.length == 2) {

                base = Double.parseDouble(strs[0]);
                altura = Double.parseDouble(strs[1]);

                if (base == 0.0) valido = false;

                else {
                    System.out.println("Area do triangulo : " + ((base * altura) / 2 + "\n" +
                            "Periodo do triangulo " + (base + altura + (Math.sqrt(base * base + altura * altura)))));
                }
            }
        }
    }
}
