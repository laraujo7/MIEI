package Adicionais;

import static java.lang.System.out;

public class Terminal {

    public static final int WINDOW_WIDTH = 208;
    public static final int TEXT_MAX_WIDTH = 90;

    public static void clear() {
        out.print("\033[H\033[2J");
        out.flush();
    }

}
