import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class TurmaAlunos {

    private String nome;
    private String numero;
    private Map<String,Aluno> alunos;


    public TurmaAlunos(){
        this.nome = "n/a";
        this.numero = "n/a";
        this.alunos = new HashMap<>();
    }

    public TurmaAlunos(String nome, String numero, Map<String,Aluno> alunos){
        this.nome = nome;
        this.numero = numero;
        setAlunos(alunos);
    }

    public TurmaAlunos(TurmaAlunos turmaAls){
        this.nome = turmaAls.getNome();
        this.numero = turmaAls.getNumero();
        this.alunos = turmaAls.getAlunos();
    }

    public String getNome() {
        return this.nome;
    }

    public String getNumero() {
        return this.numero;
    }

    public Map<String, Aluno> getAlunos() {
        Map<String,Aluno> aux = new HashMap<>();
        this.alunos.values().forEach(a -> aux.put(a.getNome(),a.clone()));
        return aux;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public void setAlunos(Map<String,Aluno> als){
        this.alunos = new HashMap<>();
        als.values().forEach(a -> this.alunos.put(a.getNome(),a.clone()));
    }

    public boolean isAlunoHere(String codAluno){
        return this.alunos.containsKey(codAluno);
    }


    //ii
    public void insereAluno(Aluno a){
       this.alunos.put(a.getNome(),a);
    }

    //iii
    public Aluno getAluno(String codAluno){
        return this.alunos.get(codAluno).clone();
    }

    //iv
    public void removeAluno(String codAluno){
        if(isAlunoHere(codAluno)) this.alunos.remove(codAluno);
    }

    //v
    public Set<String> todosOsCodigos(){
        return new TreeSet<String>(this.alunos.keySet());
    }

    //vi
    public int qtsAlunos(){
        return this.alunos.size();
    }

    //vii
    /**
    public Set<Aluno> alunosOrdemAlfabetica(){
        Set<Aluno> res = new TreeSet<>();
        for(Aluno al : this.alunos.values()) res.add(al.clone());
        return res;
    }
*/
    public Set<Aluno> alunosOrdemAlfabetica(){
        return this.alunos.values().stream()
                .map(Aluno::clone).collect(Collectors.toCollection(TreeSet::new));
    }

    //viii
    /**
    public Set<Aluno> alunosOrdemDecrescenteNumero() {
        TreeSet<Aluno> res = new TreeSet<>(new ComparatorAlunoNumero());
        for (Aluno a: this.alunos.values())
            res.add(a.clone());
        return res;

    }

    public Set<Aluno> alunosOrdemDescrescenteNumero(){
        return this.alunos.values().stream()
                                     .map(Aluno::clone)
                                     .collect(Collectors.toCollection(() -> new TreeSet<Aluno>(new ComparatorAlunoNumero())));
    }
*/

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Turma -> ").append(this.nome).append(" (")
                              .append(this.numero).append(")\n")
                              .append(this.alunos);

        return sb.toString();
    }

    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        TurmaAlunos tAls = (TurmaAlunos) obj;

        return this.nome.equals(tAls.getNome())
                && this.numero.equals(tAls.getNumero())
                && this.alunos.equals(tAls.getAlunos());

    }

    public TurmaAlunos clone(){
        return new TurmaAlunos(this);
    }


}
