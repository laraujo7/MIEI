package Ex2;

import java.lang.Runnable;
import java.lang.Thread;

public class Ex2 {

    public static class Deposits implements Runnable{
        private Bank b;

        Deposits (Bank b) {this.b = b;}

        public void run(){
            final long I=1000;

            for (long i = 0; i < I; i++)
                b.deposit(100);
        }

    }
    public static void main(String[] arg) {
        final int N = 10;
        Thread tv[] = new Thread[N];
        Bank account = new Bank();

        for (int i = 0; i < N; i++) {
            tv[i] = new Thread(new Deposits(account));

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
        }
        System.out.println(account.balance());

    }

}

