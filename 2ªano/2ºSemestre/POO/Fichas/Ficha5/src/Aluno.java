/*********************************************************************************/
/** DISCLAIMER: Este cÃ³digo foi criado e alterado durante as aulas prÃ¡ticas      */
/** de POO. Representa uma soluÃ§Ã£o em construÃ§Ã£o, com base na matÃ©ria leccionada */
/** atÃ© ao momento da sua elaboraÃ§Ã£o, e resulta da discussÃ£o e experimentaÃ§Ã£o    */
/** durante as aulas. Como tal, nÃ£o deverÃ¡ ser visto como uma soluÃ§Ã£o canÃ³nica,  */
/** ou mesmo acabada. Ã‰ disponibilizado para auxiliar o processo de estudo.      */
/** Os alunos sÃ£o encorajados a testar adequadamente o cÃ³digo fornecido e a      */
/** procurar soluÃ§Ãµes alternativas, Ã  medida que forem adquirindo mais           */
/** conhecimentos de POO.                                                        */
/*********************************************************************************/

/**
 * Classe Aluno (para Ficha 5, exercÃ­cio 2)
 *
 * @author MaterialPOO
 * @version 20200330
 */
public class Aluno implements Comparable<Aluno> {
    private String numero;
    private String nome;
    //mais v.i.

    public Aluno() {
        this.numero = new String();
        this.nome = new String();
    }

    public Aluno (String num, String nom) {
        this.numero = num;
        this.nome = nom;
    }

    public Aluno (Aluno al) {
        this.numero = al.getNumero();
        this.nome = al.getNome();
    }

    public String getNome() {
        return this.nome;
    }

    public String getNumero() { return this.numero; }


    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Aluno: ").append(this.numero).append(" , ")
                .append(this.nome).append("\n");
        return sb.toString();
    }

    public boolean equals (Object o) {
        if (o == this) return true;
        if (o == null || o.getClass() != this.getClass()) return false;
        Aluno a = (Aluno) o;
        return this.numero.equals(a.getNumero()) &&
                this.nome.equals(a.getNome());
    }

    public Aluno clone() {
        return new Aluno(this);
    }


    /**
     * ImplementaÃ§Ã£o da ordem natural.
     * Ordem natural: ordem alfabÃ©tica crescente (utiliza compareTo das Strings)
     */
    public int compareTo(Aluno a) {
        return this.nome.compareTo(a.getNome());
    }

}