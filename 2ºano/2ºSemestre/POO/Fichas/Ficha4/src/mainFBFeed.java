import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class mainFBFeed {

    public static void main(String[] args){
        int i;
        FBFeed fbFeed = new FBFeed();
        Scanner scanner = new Scanner(System.in);
        List<FBPost> list = new ArrayList<>();

        System.out.print("Indique quantos posts quer : ");

        int n = scanner.nextInt();

        for(i=0 ; i<n ; i++){
            FBPost fbPost = new FBPost();
            Scanner sc = new Scanner(System.in);

            System.out.print("Indique o Utilizador : ");
            fbPost.setUtilizador(sc.next());

            list.add(fbPost);
        }

        fbFeed.setPosts(list);

        System.out.println("Numero de posts de luis -> " + fbFeed.nrPosts("luis"));


    }


}
