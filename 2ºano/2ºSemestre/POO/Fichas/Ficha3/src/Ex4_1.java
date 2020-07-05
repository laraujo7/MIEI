public class Ex4_1 {

    public static void main(String[] args){
        Circulo c1 = new Circulo();
        Circulo c2 = new Circulo();

        c1.alteraCentro(4.5 , 5.4);
        c2.alteraCentro(5.4,4.5);

        c1.setRaio(5);
        c2.setRaio(5);

        double area1 = c1.calculaArea();
        double area2 = c2.calculaArea();

        double perimetro1 = c1.calculaPerimetro();
        double perimetro2 = c2.calculaPerimetro();

        boolean isEqual = c1.equals(c2);

        String circulo1 = c1.toString();
        String circulo2 = c2.toString();

        Circulo c3 = c1.clone();


        System.out.println("c1 -> " + circulo1);
        System.out.println("c2 -> " + circulo2);
        System.out.println("c3 -> " + c3.toString());
        System.out.println("\n");
        System.out.println("c1 ->" + area1 + " - " + perimetro1);
        System.out.println("c2 ->" + area2 + " - " + perimetro2);
        System.out.println("\n");
        System.out.println("IsEqual (c1,c2) -> " + isEqual);

    }

}
