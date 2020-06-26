import java.util.Scanner;

public class Ex3 {


    public static void main(String[] arg) {

        System.out.println("Indique as n classificacoes das UCS ");

        Scanner scanner = new Scanner(System.in);

        String lines = scanner.nextLine();

        String[] strs = lines.trim().split("\\s+");

        int n = strs.length;

        int b[] = new int[4];
        int aux;

        for (int i = 0; i < n; i++) {
            aux = Integer.parseInt(strs[i]);
            if (aux >= 0 && aux < 5) b[0]++;
            else if (aux >= 5 && aux < 10) b[1]++;
            else if (aux >= 10 && aux < 15) b[2]++;
            else if (aux >= 15 && aux < 20) b[3]++;
        }

        System.out.println("[0,5[ -> " + b[0] + "\n" + "[5,10[ -> " + b[1] + "\n" + "[10,15[ -> " + b[2] + "\n" + "[15,20[ -> " + b[3]);

    }
}
