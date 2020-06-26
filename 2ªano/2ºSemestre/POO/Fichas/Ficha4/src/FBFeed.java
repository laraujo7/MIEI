import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.stream.Collectors;

public class FBFeed {

    private List<FBPost> feed;


    public FBFeed(){
        this.feed = new ArrayList<>();
    }

    public FBFeed(List<FBPost> posts){
        setPosts(posts);
    }

    public FBFeed(FBFeed ff){
        this.feed = ff.getFeed();
    }

    public List<FBPost> getFeed(){
        List<FBPost> aux = new ArrayList<>();
        for(FBPost fb : this.feed) aux.add(fb.clone());
        return aux;
    }

    public void setPosts(List<FBPost> posts){
        this.feed = new ArrayList<>();
        for(FBPost fb : posts) this.feed.add(fb.clone());
    }


    //i
    public int nrPosts(String user){
        return (int) this.feed.stream().filter(f -> f.getUtilizador().equals(user)).count();
    }

    //ii
    public List<FBPost> postsOf(String user){
        return this.feed.stream().filter(f -> f.getUtilizador().equals(user)).collect(Collectors.toList());
    }

    //iii
    public List<FBPost> postsOf(String user, LocalDate inicio, LocalDate fim){
        return this.feed.stream().filter(f -> (f.getUtilizador().equals(user)
                && f.getData().isAfter(inicio)
                && f.getData().isBefore(fim))).collect(Collectors.toList());
    }

    //iv
    public FBPost getPost(int id){
        boolean encontrado = false;
        FBPost res = new FBPost();
        Iterator<FBPost> it = this.feed.iterator();

        while(it.hasNext() && !encontrado){

            FBPost fb = it.next();

            if(fb.getId() == id) {
                encontrado = true;
                res = fb;
            }
        }

        return res;
    }

    //v
    public void comment(FBPost post, String comentario){
        List<String> list = new ArrayList<>(post.getComentarios());
        list.add(comentario);
        post.setComentarios(list);
    }

    //vi
    public void comment(int postid, String comentario){
        boolean encontrado = false;
        Iterator<FBPost> it = this.feed.iterator();

        while(it.hasNext() && !encontrado){

            FBPost fb = it.next();

            if(fb.getId() == postid){
                encontrado = true;
                comment(fb,comentario);
            }

        }
    }

    //vii
    public void like(FBPost post){
        post.setNLikes(post.getNLikes() + 1);
    }

    //viii
    public void like(int postid){
        boolean encontrado = false;
        Iterator<FBPost> it = this.feed.iterator();

        while(it.hasNext() && !encontrado){

            FBPost fb = it.next();

            if(fb.getId() == postid){
                encontrado = true;
                like(fb);
            }
        }
    }

    //ix
    public List<Integer> top5Comments(){
        int i;
        List<Integer> res = new ArrayList<>();
        List<FBPost> fb = new ArrayList<>(this.getFeed());

        Collections.sort(fb);

        for(i=0 ; i<5 ; i++) res.add(fb.get(i).getId());

        return res;
    }


}
