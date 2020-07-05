import java.time.LocalDate;
import java.util.Scanner;

public class Ex3 {

    public static void main(String[] args){
        int i;
        Scanner sc = new Scanner(System.in);

        System.out.print("Indique o numero do tamanho do array : ");

        int n = sc.nextInt();

        ArrayLocalDate array = new ArrayLocalDate(n);

        for(i=0 ; i < n ; i++) {
            System.out.print("Indique a data a acrescentar ao array (dd MM yyyy) : ");

            Scanner scanner = new Scanner(System.in);

            String lines = scanner.nextLine();

            String[] strs = lines.trim().split("\\s+");

            LocalDate data = LocalDate.of(Integer.parseInt(strs[2]),Integer.parseInt(strs[1]),Integer.parseInt(strs[0]));

            array.insereData(data,i);

        }


        if(n > 0) {
            System.out.print("Introduza um data : ");

            Scanner s = new Scanner(System.in);

            String lines = s.nextLine();

            String[] strs = lines.trim().split("\\s+");

            LocalDate proc = LocalDate.of(Integer.parseInt(strs[2]),Integer.parseInt(strs[1]),Integer.parseInt(strs[0]));

            System.out.println("Data mais proxima de " + proc + " é a data " + array.dataMaisProxima(proc));
        }

    }
}
