public class Telemovel {

    private String marca;
    private String modelo;
    private double resolucaoX;
    private double resolucaoY;
    private int dimensaoMensagens;
    private String[] Mensagens;
    private int dimensaoFotos;
    private int dimensaoApps;
    private byte espacoOcupado;
    private byte espacoTotal;
    private int nMensagens;
    private int nFotos;
    private int nApps;
    private String[] nomeApps;

    public Telemovel(){
        this.marca = "n/a";
        this.modelo = "n/a";
        this.resolucaoX = 0;
        this.resolucaoY = 0;
        this.dimensaoMensagens = 0;
        this.Mensagens = new String[0];
        this.dimensaoFotos = 0;
        this.dimensaoMensagens = 0;
        this.dimensaoApps = 0;
        this.espacoOcupado = 0;
        this.espacoTotal = 0;
        this.nMensagens = 0;
        this.nFotos = 0;
        this.nApps = 0;
        this.nomeApps = new String[0];
    }

    public Telemovel(String marc, String model, double resolX, double resolY,
                     int dimMensagens, String[] Men, int nMens, int dimFotos, int dimApps,
                     byte espacoOcup, byte espacoTot, int nFots, int nAps, String[] nomeAps){

        this.marca = marc;
        this.modelo = model;
        this.resolucaoX = resolX;
        this.resolucaoY = resolY;
        this.dimensaoMensagens = dimMensagens;
        this.Mensagens = Men;
        this.nMensagens = nMens;
        this.dimensaoFotos = dimFotos;
        this.dimensaoApps = dimApps;
        this.espacoOcupado = espacoOcup;
        this.espacoTotal = espacoTot;
        this.nFotos = nFots;
        this.nApps = nAps;
        this.nomeApps = nomeAps;
    }

    public Telemovel(Telemovel tel){
        this.marca = tel.getMarca();
        this.modelo = tel. getModelo();
        this.resolucaoX = tel.getResolucaoX();
        this.resolucaoY = tel.getResolucaoY();
        this.dimensaoMensagens = tel.getDimensaoMensagens();
        this.Mensagens = tel.getMensagens();
        this.nMensagens = tel.getNMensagens();
        this.dimensaoFotos = tel.getDimensaoFotos();
        this.dimensaoApps = tel.getDimensaoApps();
        this.espacoOcupado = tel.getEspacoOcupado();
        this.espacoTotal = tel.getEspacoTotal();
        this.nFotos = tel.getNFotos();
        this.nApps = tel.getNApps();
        this.nomeApps = tel.getNomeApps();
    }


    public String getMarca(){
        return this.marca;
    }

    public String getModelo(){
        return this.modelo;
    }

    public double getResolucaoX() {
        return resolucaoX;
    }

    public double getResolucaoY() {
        return resolucaoY;
    }

    public int getDimensaoMensagens() {
        return dimensaoMensagens;
    }

    public String[] getMensagens(){
        return this.Mensagens;
    }

    public int getNMensagens(){
        return this.nMensagens;
    }

    public int getDimensaoFotos(){
        return this.dimensaoFotos;
    }

    public int getDimensaoApps(){
        return this.dimensaoApps;
    }

    public byte getEspacoOcupado(){
        return this.espacoOcupado;
    }

    public byte getEspacoTotal(){
        return this.espacoTotal;
    }

    public int getNFotos(){
        return this.nFotos;
    }

    public int getNApps(){
        return this.nApps;
    }

    public String[] getNomeApps(){
        return this.nomeApps;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void setResolucaoX(double resolucaoX) {
        this.resolucaoX = resolucaoX;
    }

    public void setResolucaoY(double resolucaoY) {
        this.resolucaoY = resolucaoY;
    }

    public void setDimensaoMensagens(int dimensaoMensagens) {
        this.dimensaoMensagens = dimensaoMensagens;
    }

    public void setMensagens(String[] mens){
        this.Mensagens = mens;
    }

    public void setNMensagens(int nMensagens) {
        this.nMensagens = nMensagens;
    }

    public void setDimensaoFotos(int dimensaoFotos) {
        this.dimensaoFotos = dimensaoFotos;
    }

    public void setDimensaoApps(int dimensaoApps) {
        this.dimensaoApps = dimensaoApps;
    }

    public void setEspacoOcupado(byte espacoOcupado) {
        this.espacoOcupado = espacoOcupado;
    }

    public void setEspacoTotal(byte espacoTotal) {
        this.espacoTotal = espacoTotal;
    }

    public void setNFotos(int nFotos) {
        this.nFotos = nFotos;
    }

    public void setNApps(int nApps) {
        this.nApps = nApps;
    }

    public void setNomeApps(String[] nomeApps) {
        this.nomeApps = nomeApps;
    }

    public boolean equals(Telemovel tel){
        return (this.marca == tel.marca && this.modelo == tel.modelo);
    }

    public String toString(){
        return "Marca -> " + this.marca + "\n"
             + "Modelo -> " + this.modelo + "\n"
             + "Resolucao -> " + this.resolucaoX + "x" + this.resolucaoY + "\n"
             + "Dimensao Mensagens -> " + this.dimensaoMensagens + "\n"
             + "Dimensao Fotos -> " + this.dimensaoFotos + "\n"
             + "Dimensao Apps -> " + this.dimensaoApps + "\n";
    }

    public Telemovel clone(){
        return new Telemovel(this);
    }


    public boolean existeEspaco(int numeroBytes){
        return (this.espacoOcupado + numeroBytes <= this.espacoTotal);
    }

    public void instalaApp(String nome, int tamanho){

        if(this.existeEspaco(tamanho)){

            this.espacoOcupado += tamanho;
            this.dimensaoApps += tamanho;
            this.Mensagens[this.nApps++] = nome;

        }

    }

    public void recebeMsg(String msg){
        this.Mensagens[this.nMensagens++] = msg;
    }

    public double tamMedioApps(){
        return this.dimensaoApps / this.nApps;
    }

    public String maiorMsg(){
        int maior = 0;
        String maiorMsg = "n/a";

        for(String msg : this.Mensagens) if (msg.length() > maior) maiorMsg = msg;

        return maiorMsg;
    }

    public void removeApp(String nome, int tamanho){
        int j,i;

        if(this.existeApp(nome)) {
            for(i=j=0 ; i < this.nApps ; i++) if(this.nomeApps[i] != nome)
                                                this.nomeApps[j++] = this.nomeApps[i];

            }

        this.nomeApps[this.nApps--] = "n/a";
        this.dimensaoApps -= tamanho;
        this.espacoOcupado -= tamanho;

    }


    public boolean existeApp(String nome){

        for(String n : this.nomeApps) if(n == nome) return true;
        return false;
    }



}
