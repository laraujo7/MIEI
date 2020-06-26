import java.util.*;

public class Grafo {

    private Map<Integer, Set<Integer>> adj;

    public Grafo(){
        this.adj = new HashMap<>();
    }

    public Grafo(Map<Integer,Set<Integer>> m){
        setAdj(m);
    }

    public Grafo(Grafo g){
        this.adj = g.getAdj();
    }


    public Map<Integer,Set<Integer>> getAdj(){
        Map<Integer,Set<Integer>> res = new HashMap<>();
        this.adj.forEach(res::put);
        return res;
    }

    public void setAdj(Map<Integer,Set<Integer>> m){
        this.adj = new HashMap<>();
        m.forEach(this.adj::put);
    }



    //ii
    void addArco(Integer vOrig, Integer vDest){
        this.adj.putIfAbsent(vOrig,new HashSet<>());
        this.adj.putIfAbsent(vDest,new HashSet<>());
        this.adj.get(vOrig).add(vDest);
    }

    //iii
    boolean isSink(Integer v){
        return this.adj.get(v).isEmpty();
    }

    //iv
    boolean isSource(Integer v){
        boolean source = false;
        Iterator<Set<Integer>> it = this.adj.values().iterator();

        while(it.hasNext() && !source){

            Set<Integer> st = it.next();

            if(st.contains(v)) source = true;
        }
        return source;
    }

    //v
    int size(){
        int res = this.adj.size();

        for(Set<Integer> st : this.adj.values()){
            res += st.size();
        }

        return res;
    }


    //vi
    boolean haCaminho(Integer vOrig, Integer vDest, Set<Integer> st) {

        if(vOrig == vDest) return true;
        if(!this.adj.containsKey(vOrig) || st.contains(vOrig)) return false;

        Iterator<Integer> it = this.adj.get(vOrig).iterator();

        boolean res = false;
        st.add(vOrig);

        while(it.hasNext() && !res) res = haCaminho(it.next(),vDest,st);

        return res;
    }


    boolean haCaminho(Integer vOrig, Integer vDest){
        return haCaminho(vOrig,vDest,new HashSet<>());
    }

    //vii



    public String toString(){
        StringBuilder sb = new StringBuilder();

        this.adj.forEach((key,value) -> sb.append(key).append(" -> ").append(value.toString()));

        return sb.toString();
    }

    public boolean eqauls(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        Grafo g = (Grafo) obj;

        return this.adj.equals(g.getAdj());
    }

    public Grafo clone(){
        return new Grafo(this);
    }


}
