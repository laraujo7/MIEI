import java.time.LocalDate;
import java.util.Scanner;

public class Ex1 {

    public static int exerc1(LocalDate data){

        return ((data.getYear() - 1900) * 365 + data.getDayOfYear());

    }


    public static void main(String[] arg){

        System.out.println("Indique o dia :");
        int dia = (new Scanner(System.in)).nextInt();

        System.out.println("Indique o mes :");
        int mes = (new Scanner(System.in)).nextInt();

        System.out.println("Indique o ano :");
        int ano = (new Scanner(System.in)).nextInt();

        LocalDate data = LocalDate.of(ano,mes,dia);

        int nDias = exerc1(data);

        System.out.println("Numero de dias entre 01/01/1990 e " + ano + "/" + mes + "/" + dia + " : " + nDias);

    }
}
