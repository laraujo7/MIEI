import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class FBPost implements Comparable<FBPost>{

    private int id;
    private String utilizador;
    private LocalDate data;
    private String conteudo;
    private int nLikes;
    private List<String> comentarios;


    public FBPost(){
        this.id = 0;
        this.utilizador = "n/a";
        this.data = LocalDate.now();
        this.conteudo = "n/a";
        this.nLikes = 0;
        this.comentarios = new ArrayList<>();

    }

    public FBPost(int id, String utilizador, LocalDate data, String contiudo, int nLikes, ArrayList<String> comentarios) {
        this.id = id;
        this.utilizador = utilizador;
        this.data = data;
        this.conteudo = contiudo;
        this.nLikes = nLikes;
        setComentarios(comentarios);
    }

    public FBPost(FBPost fb){
        this.id = fb.getId();
        this.utilizador = fb.getUtilizador();
        this.data = fb.getData();
        this.conteudo = fb.getConteudo();
        this.nLikes = fb.getNLikes();
        this.comentarios = fb.getComentarios();
    }


    public int getId() {
        return this.id;
    }

    public String getUtilizador() {
        return this.utilizador;
    }

    public LocalDate getData() {
        return this.data;
    }

    public String getConteudo() {
        return this.conteudo;
    }

    public int getNLikes() {
        return this.nLikes;
    }

    public List<String> getComentarios() {
        return new ArrayList<>(this.comentarios);
    }

    public void setUtilizador(String utilizador) {
        this.utilizador = utilizador;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public void setConteudo(String conteudo) {
        this.conteudo = conteudo;
    }

    public void setNLikes(int nLikes) {
        this.nLikes = nLikes;
    }

    public void setComentarios(List<String> comentarios) {
        this.comentarios = new ArrayList<>();
        this.comentarios.addAll(comentarios);
    }


    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Utilizador -> ").append(this.getUtilizador()).append("\n");

        for(String s : this.comentarios) sb.append(s).append("\n");

        return sb.toString();
    }

    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        FBPost fb = (FBPost) obj;

        return this.utilizador.equals(fb.getUtilizador())
                && this.id == fb.getId()
                && this.conteudo.equals(fb.getConteudo());
    }

    public FBPost clone(){
        return new FBPost(this);
    }

    @Override
    public int compareTo(FBPost fb){
        return this.getComentarios().size() - fb.getComentarios().size();
    }

}
