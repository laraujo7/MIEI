import java.util.Scanner;
import static java.lang.Math.abs;

public class Ex4 {

    public static void main(String[] arg){

        System.out.println("Indique as n temperaturas : ");

        Scanner scanner = new Scanner(System.in);

        String lines = scanner.nextLine();

        String[] strs = lines.trim().split("\\s+");

        int n = strs.length;

        int media = 0;
        int aux;
        int dia = 0;
        int maior = 0;
        int temperatura;

        for(int i=0 ; i<n ; i++){
            temperatura = Integer.parseInt(strs[i]);
            media += temperatura;

            if(i>0){
                aux = Integer.parseInt(strs[i-1]);
                if(abs(temperatura - aux) > maior) {
                    maior = abs(temperatura - aux);
                    dia = i;
                }
            }
        }

        media /= n;

        System.out.println("A media das " + n + " temperaturas doi de " + media + " graus\n" +
                            "A maior variação registou-se entre os dias " + dia + " e " + (dia+1) + " tendo a temperatudo sudido/descido " + maior + " graus");

    }
}
