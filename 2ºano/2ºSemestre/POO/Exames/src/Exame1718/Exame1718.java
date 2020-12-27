package Exame1718;

public class Exame1718 {
    //1.a)
    void adicionaTicket(Ticket t){
        this.ticketsPorResolver.add(t.clone());
    }

    //1.b)
    void resolveTicket(String ident) throws TecnicoNaoExisteException{
        try{
            this.ticketsPorResolver.stream().filter(t -> t.getNome0.equals(ident)).
        }
        catch(TecnicoNaoExisteException e){

        }
    }

}
