import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;

public class FBFeedMap {

    private Map<String, List<FBPost>> feed;

    public FBFeedMap(){
        this.feed = new HashMap<>();
    }

    public FBFeedMap(Map<String, List<FBPost>> f){
        setFeed(f);
    }

    public FBFeedMap(FBFeedMap fmap){
        this.feed = fmap.getFeed();
    }

    public Map<String,List<FBPost>> getFeed(){
        Map<String,List<FBPost>> res = new HashMap<>();
        this.feed.forEach((key,value) -> res.put(key, new ArrayList<>(geraClone(value))));
        return res;
    }

    public void setFeed(Map<String,List<FBPost>> f){
        this.feed = new HashMap<>();

        //f.forEach((key,value) -> this.feed.put(key, (List<FBPost>) (new ArrayList<>(value)).clone()));
        f.forEach((key,value) -> this.feed.put(key, new ArrayList<>(geraClone(value))));
    }

    //função auxiliar
    public List<FBPost> geraClone(List<FBPost> list){
        List<FBPost> res = new ArrayList<>();

        for(FBPost fb : list){
            res.add(fb.clone());
        }
        return res;
    }


    //i
    public void addPost(String user, FBPost post){
        this.feed.get(user).add(post.clone());
    }

    //ii
    public void removePosts(String user, LocalDateTime di, LocalDateTime df){
        this.feed.get(user).removeIf(f -> f.getData().isAfter(di) && f.getData().isBefore(df));
    }

    //iii
    public int postsNumPeriodo(LocalDateTime di, LocalDateTime df){

        return (int) this.feed.values().stream()
                                    .flatMap(Collection::stream)
                                    .filter(f -> f.getData().isAfter(di) && f.getData().isBefore(df))
                                    .count();
    }
/**
    int res = 0;
    for(List<FBPost> list : this.feed.values()){

        for(FBPost fb : list)
            if(fb.getData().isAfter(di) && fb.getData().isBefore(df)) res++;

    }
    return res;
*/

    //iv
    public String utilizadorMaisActivo(LocalDateTime di, LocalDateTime df){
        String res = "n/a";
        int max = 0;

        for(Map.Entry<String,List<FBPost>> entry : this.feed.entrySet()){

            int count = (int) entry.getValue().stream()
                                   .filter(f -> f.getData().isAfter(di) && f.getData().isBefore(df))
                                   .count();

            if(max < count) {
                max = count;
                res = entry.getKey();
            }
        }
        return res;
    }

    //v
    




    public String toString(){
        StringBuilder sb = new StringBuilder();

        this.feed.forEach((key,value) -> sb.append(key).append(" -> ").append(value.toString()).append("\n"));

        return sb.toString();
    }

    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        FBFeedMap fbFeed = (FBFeedMap) obj;

        return this.feed.equals(fbFeed.getFeed());
    }

    public FBFeedMap clone(){
        return new FBFeedMap(this);
    }






}
