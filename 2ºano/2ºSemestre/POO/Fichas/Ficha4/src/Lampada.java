public class Lampada {

    //0 - desligado , 1 - ligado , 2 - eco
    private int modo;

    private final double consumoNormal = 0.1;
    private final double consumoEco = 0.05;
    private long total;
    private long stamp;


    public Lampada(){
        this.modo = 0;
        this.total = 0;
        this.stamp = System.currentTimeMillis();
    }

    public Lampada(int md, long tt, long stmp){
        this.modo = md;
        this.total = tt;
        this.stamp = stmp;
    }

    public Lampada(Lampada l){
        this.modo = l.getModo();
        this.total = l.getTotal();
        this.stamp = l.getStamp();
    }

    public int getModo(){
        return this.modo;
    }

    public long getTotal() {
        return this.total;
    }

    public long getStamp(){
        return this.stamp;
    }

    public void setModo(int modo) {
        this.modo = modo;
    }

    public void setTotal(long total) {
        this.total = total;
    }

    public void setStamp(long stamp) {
        this.stamp = stamp;
    }

    public void lampON(){
        this.atualizaConsumo();
        this.modo = 1;
    }

    public void lampOFF(){
        this.atualizaConsumo();
        this.modo = 0;
    }

    public void lampECO(){
        this.atualizaConsumo();
        this.modo = 2;
    }

    public double totalConsumo(){
        return this.total;
    }

    public double periodoConsumo(){
        return System.currentTimeMillis() - this.stamp;
    }


    public void atualizaConsumo(){
        long tempo = System.currentTimeMillis() - this.stamp;

        if(this.modo == 1) this.total += tempo * this.consumoNormal;
        if(this.modo == 2) this.total += tempo * this.consumoEco;

        this.stamp = System.currentTimeMillis();
    }


    public Lampada clone(){
        return new Lampada(this);
    }

}
