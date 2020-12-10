import java.lang.Runnable;
import java.lang.Thread;

public class Main {

    public static class NThreads implements Runnable{

        public void run(){
            final long I=100;

            for (long i = 0; i < I; i++)
                System.out.println(i);
        }

    }

    public static void main(String[] arg) throws InterruptedException {
        final int N = 10;
        Thread tv[] = new Thread[N];

        for (int i = 0; i < N; i++) {
            tv[i] = new Thread(new NThreads());

        }

        for(int i = 0; i < N ; i++){
            tv[i].start();
        }

        for(int i = 0; i < N ; i++){
            try {
                tv[i].join();
            }
            catch (InterruptedException e){
                e.printStackTrace();
            }
            System.out.println("fim");
        }


    }

}
