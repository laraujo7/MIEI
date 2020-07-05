public class Circulo {

    private double x;
    private double y;
    private double raio;

    public Circulo(){
        this.x = 0;
        this.y = 0;
        this.raio = 0;
    }

    public Circulo(double x1,double y1,double raio1){
        this.x = x1;
        this.y = y1;
        this.raio = raio1;
    }

    public Circulo(Circulo c){
        this.x = c.getX();
        this.y = c.getY();
        this.raio = c.getRaio();
    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }

    public double getRaio(){
        return this.raio;
    }

    public void setX(double x1){
        this.x = x1;
    }

    public void setY(double y1){
        this.y = y1;
    }

    public void setRaio(double raio1){
        this.raio = raio1;
    }

    public void alteraCentro(double x1, double y1){
        this.x = x1;
        this.y = y1;
    }

    public double calculaArea(){
        return (Math.PI * Math.pow(this.raio,2));
    }

    public double calculaPerimetro(){
        return (2*Math.PI * this.raio);
    }

    public boolean equals(Circulo c){
        return(this.x == c.x && this.y == c.y && this.raio == c.raio);
    }

    public String toString(){
        return "(" + this.x + "," + this.y + "," + this.raio + ")";
    }

    public Circulo clone(){
        return new Circulo(this);
    }


}
