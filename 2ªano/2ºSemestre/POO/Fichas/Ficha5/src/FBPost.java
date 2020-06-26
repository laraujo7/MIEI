import java.time.LocalDateTime;
import java.util.List;


public class FBPost
{

    private int id;
    private String nome;
    private String conteudo;
    private LocalDateTime data;
    private int likes;
    private List<String> comentarios;

    public String getNome(){
        return this.nome;
    }

    public int getId(){
        return this.id;
    }

    public String getConteudo(){
        return this.conteudo;
    }
    public LocalDateTime getData(){
        return this.data;
    }
    public int getLikes(){
        return this.likes;
    }
    public List<String> getComentarios(){
        return this.comentarios;
    }

    public int setLikes(int likes) {
        return this.likes;
    }


    public FBPost(FBPost l){
        this.id = l.getId();
        this.nome = l.getNome();
        this.conteudo = l.getConteudo();
        this.data = l.getData();
        this.likes = l.getLikes();
        this.comentarios = l.getComentarios();
    }


    public FBPost clone(){
        return new FBPost(this);
    }

    public boolean isFromUser(String username){
        return(this.getNome().equals(username));
    }


}
