import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Ex2 {

    public static void cls()  {
        System.out.println("\033[H\033[2J");
        System.out.flush();
    }


    public static Date StringToDate(String dateInput) throws ParseException {
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

        return formatter.parse(dateInput);
    }


    public static void main(String args[]) throws ParseException {
        Scanner sc = new Scanner(System.in);

        cls();

        System.out.println("Introduza a primeira data (dd/MM/yyyy): ");
        Date date1 = StringToDate(new Scanner(System.in).next());

        cls();

        System.out.println("Introduza a segunda data (dd/MM/yyyy): ");
        Date data2 = StringToDate(new Scanner(System.in).next());



    }
}