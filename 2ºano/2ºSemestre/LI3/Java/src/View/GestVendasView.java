package View;

import Adicionais.*;
import Model.IVenda;

import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class GestVendasView implements IGestVendasView {


    DecimalFormat newFormat = new DecimalFormat("#.0000");
    DecimalFormat newFormat2 = new DecimalFormat("#.00");

    public void menu(int menu){

        switch(menu){

            case 0:
                this.menuPrincipal();
                break;

            case 1:
                this.menuEstatistico();
                break;

            case 2:
                this.menuQueries();
                break;

        }
    }



    public void menuPrincipal(){
        Adicionais.Terminal.clear();
        Arrays.stream(MenuOptions.parteCimaMenuPrincipal).forEach(System.out::println);
        Arrays.stream(MenuOptions.menuPrincipal).forEach(System.out::println);
        Arrays.stream(MenuOptions.opcoesMenuPrincipal).forEach(System.out::println);
        Arrays.stream(MenuOptions.parteBaixoMenuPrincipal).forEach(System.out::println);
        System.out.print(MenuOptions.opcao);
    }


    public void menuEstatistico(){
        Adicionais.Terminal.clear();
        Arrays.stream(MenuOptions.parteCimaMenuEstatistico).forEach(System.out::println);
        Arrays.stream(MenuOptions.menuEstatistico).forEach(System.out::println);
        Arrays.stream(MenuOptions.opcoesMenuEstatisticas).forEach(System.out::println);
        Arrays.stream(MenuOptions.parteBaixoMenuEstatistico).forEach(System.out::println);
        System.out.print(MenuOptions.opcao);
    }

    public void menuQueries(){
        Adicionais.Terminal.clear();
        Arrays.stream(MenuOptions.parteCimaMenuQueries).forEach(System.out::println);
        Arrays.stream(MenuOptions.menuQueries).forEach(System.out::println);
        Arrays.stream(MenuOptions.opcoesQueries).forEach(System.out::println);
        Arrays.stream(MenuOptions.parteBaixoMenuQueries).forEach(System.out::println);
        System.out.print(MenuOptions.opcao);
    }

    public static void enterParaContinuar(){
        System.out.println(Colors.ANSI_RED + "                                                                                          Enter Para Continuar" + Colors.ANSI_RESET);
        Input.lerString();
    }

    public static void enterParaContinuar(String tempo){
        System.out.println(Colors.ANSI_GREEN + "\n                                                                                   Tempo de Execucao : " + Colors.ANSI_RESET +  tempo);
        System.out.println(Colors.ANSI_RED + "                                                                                          Enter Para Continuar" + Colors.ANSI_RESET);
        Input.lerString();
    }




    public void dadosEstatisticos_UltiFicheiro(String ultiFicheiro,int vendasErradas, int produtos,
                                               int diffProdutos, int produtosNComprados, int clientes,
                                               int diffClientes, int clientesNComprados, int vendasValor0,
                                               double faturacaoTotal){
        Adicionais.Terminal.clear();
        System.out.println("                                                             -> Ultimo Ficheiro Lido : " + ultiFicheiro);
        System.out.println("                                                             -> Numero de Vendas Erradas : " + vendasErradas);
        System.out.println("                                                             -> Numero Total de Produtos : " + produtos);
        System.out.println("                                                             -> Numero Total de Diferentes Produtos Comprados : " + diffProdutos);
        System.out.println("                                                             -> Numero Total de Produtos Nao Comprados : " + produtosNComprados);
        System.out.println("                                                             -> Numero Total de Clientes : " + clientes);
        System.out.println("                                                             -> Numero Total de Diferentes Clientes que Efutaram Compra : " + diffClientes);
        System.out.println("                                                             -> Numero de Clientes que Nunca Compram : " + clientesNComprados);
        System.out.println("                                                             -> Numero de Compras de Valor 0 : " + vendasValor0);
        System.out.println("                                                             -> Faturação Total : " + faturacaoTotal);
        System.out.println("");
        View.GestVendasView.enterParaContinuar();
    }


    public void dadosEstatisticos_Gerais(List<Integer> numComprasMensal, List<Double> fatMensalGlobal
            ,List<List<Double>> fatMensalFilial,List<List<Integer>> clientesMensalFilial) {
        int j;

        Adicionais.Terminal.clear();

        System.out.println(Colors.ANSI_RED + "\n                                    ╔═════════════╦═════════════╦═════════════╦═════════════╦═════════════╦═════════════╦═════════════╦═════════════╦═════════════╦═════════════╦═════════════╦═════════════╗" + Colors.ANSI_RESET);
        System.out.println("                                    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 1    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 2    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 3    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 4    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 5    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 6    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "     Mes 7   " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 8    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 9    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 10   " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 11   " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    Mes 12   " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET);
        System.out.println(Colors.ANSI_RED +"                                    ╠═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╣" + Colors.ANSI_RESET);

        System.out.print("Numero Total de Compras Mensal      " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    ");
        numComprasMensal.forEach(i -> System.out.print( i + "    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET +"    "));
        System.out.println(Colors.ANSI_RED +"\n                                    ╠═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╣" + Colors.ANSI_RESET);

        System.out.print("Faturacao Total Por Mês (Global)    " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET );
        fatMensalGlobal.forEach(i -> System.out.print(newFormat2.format(i) + Colors.ANSI_RED +"║" + Colors.ANSI_RESET ));
        System.out.println(Colors.ANSI_RED +"\n                                ╔═══╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╣" + Colors.ANSI_RESET);

        System.out.print("Faturcao Total Por Mês (Filial) " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET  + " 1 " + Colors.ANSI_RED +"║" + Colors.ANSI_RESET);
        for(j=0 ; j<3 ; j++) {
            fatMensalFilial.get(j).forEach(i -> System.out.print(newFormat2.format(i) + Colors.ANSI_RED +"║" + Colors.ANSI_RESET ));
            if(j!=2) System.out.print(Colors.ANSI_RED +"\n                                ║ "+ Colors.ANSI_RESET +(j+2)+ Colors.ANSI_RED +" ║" + Colors.ANSI_RESET);
        }
        System.out.println(Colors.ANSI_RED +"\n                                ╠═══╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╣" + Colors.ANSI_RESET);


        System.out.print("Num. de Clientes Mensal (Fil.)  "+ Colors.ANSI_RED +"║" + Colors.ANSI_RESET + " 1 "+ Colors.ANSI_RED +"║" + Colors.ANSI_RESET + "    ");
        for(j=0 ; j<3 ; j++) {
            clientesMensalFilial.get(j).forEach(i -> System.out.print(i + Colors.ANSI_RED + "    ║    " + Colors.ANSI_RESET));
            if(j!=2) System.out.print(Colors.ANSI_RED +"\n                                ║ "+ Colors.ANSI_RESET +(j+2)+ Colors.ANSI_RED +" ║    " + Colors.ANSI_RESET);
        }
        System.out.println(Colors.ANSI_RED +"\n                                ╚═══╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╝" + Colors.ANSI_RESET);




        /*
        System.out.println("                                                            -> Faturação Total Por Mês (Global) : " + fatMensalFilial);
        System.out.println("                                                            -> Faturação Total Por Mês (Filiais) : " + fatMensalGlobal);
        System.out.println("                                                            -> Numero de Clientes Mensal que Efeturam Compras (Filiais): " + clientesMensalFilial);

         */
        enterParaContinuar();
        Terminal.clear();
    }


    public void query1(Set<String> produtos,String tempo){
        Adicionais.Terminal.clear();
        int i = 1;

        for(String s : produtos){
            System.out.print(s + "   ");
            if(i == 20) {
                System.out.println("");
                i=0;
            }
            i++;
        }
        System.out.println("");
        enterParaContinuar(tempo);
    }


    public void query2(int mes, int[] array,String tempo){ //0-2 n_clientes , 3-5 n-vendas
        Adicionais.Terminal.clear();
        System.out.println("                                                                                                 MÊS " + mes);
        System.out.println("                                                                                 FILIAL 1      FILIAL 2      FILIAL 3      TOTAL");
        System.out.println("                                                           Numero de Clientes :   " + array[0] + "         " + array[1] + "         " + array[2] + "        " + (array[0]+array[1]+array[2]));
        System.out.println("                                                           Numero de Vendas   :   " + array[3] + "         " + array[4] + "         " + array[5] + "        " + (array[3]+array[4]+array[5]));
        enterParaContinuar(tempo);
    }

    public void query3(String cliente,double[] array,String tempo){
        Adicionais.Terminal.clear();
        System.out.println("                                                                                              Cliente " + cliente);
        System.out.println("                                                  Mes       Numero de Compras       Numero de Produtos Diferentes       Faturacao");
        for(int i = 0; i<12 ; i++) {
            if(i<9) System.out.println("                                                   " + (i + 1) + "               " + ((int) array[i]) + "                             " + ((int) array[12 + i]) + "                    " + array[24 + i]);
            else System.out.println("                                                  " + (i + 1) + "               " + ((int) array[i]) + "                             " + ((int) array[12 + i]) + "                    " + array[24 + i]);
        }
        System.out.println("");
        enterParaContinuar(tempo);
    }

    public void query4(String produto, double[] array,String tempo){ //0-11 qtas vezes foi comprado ; 12-23 por qtos clientes diferentes ; 24-35 faturacao
        Adicionais.Terminal.clear();
        System.out.println("                                                                                            Produto " + produto);
        System.out.println("                                                  Mes       Numero de Compras       Numero de Clientes Diferentes       Faturacao");
        for(int i = 0; i<12 ; i++) {
            if(i<9) System.out.println("                                                   " + (i + 1) + "               " + ((int) array[i]) + "                             " + ((int) array[12 + i]) + "                         " + array[24 + i]);
            else System.out.println("                                                  " + (i + 1) + "               " + ((int) array[i]) + "                             " + ((int) array[12 + i]) + "                         " + array[24 + i]);
        }
        System.out.println("");
        enterParaContinuar(tempo);
    }


    public void query5(String cliente, List<IVenda> vendas, String tempo){
        Adicionais.Terminal.clear();

        System.out.println("                                                                                              Cliente " + cliente);
        System.out.println("                                                                                        Produtos       Quantidade");

        vendas.forEach(v -> System.out.println("                                                                                         " + v.getCodigoProduto() + "           " + v.getQt()));


        System.out.println("");
        enterParaContinuar(tempo);
    }


    public void query6(int n, List<IQuery6Aux> top,String tempo){
        Adicionais.Terminal.clear();
        int i = 1;
        List<IQuery6Aux> topList = top.stream().limit(n).collect(Collectors.toList());

        System.out.println("                                                                         Top       Produto       Numero de Clientes       Quantidade");

        for(IQuery6Aux q : topList){
            if(i < 10) System.out.println("                                                                          " + (i++) + "         " + q.getProduto() + "              " + q.getNumeroClientes() + "                  " + q.getQuantidade());
            else System.out.println("                                                                         " + (i++) + "         " + q.getProduto() + "              " + q.getNumeroClientes() + "                  " + q.getQuantidade());
        }

        System.out.println("");
        enterParaContinuar(tempo);
    }


    public void query7(List<IParClienteCusto> top, String tempo){
        Adicionais.Terminal.clear();

        System.out.println("                                                                      Filial 1                        Filial 2                         Filial 3");
        System.out.println("                                                       Top       Clientes    Faturado             Clientes    Faturado             Clientes    Faturado");

        System.out.println("                                                        1         " + top.get(0).getCliente() + "    " + newFormat.format(top.get(0).getCusto()) + "            " + top.get(3).getCliente() + "    " + newFormat.format(top.get(3).getCusto()) + "            " + top.get(6).getCliente() + "    " + newFormat.format(top.get(6).getCusto()));
        System.out.println("                                                        2         " + top.get(1).getCliente() + "    " + newFormat.format(top.get(1).getCusto()) + "            " + top.get(4).getCliente() + "    " + newFormat.format(top.get(4).getCusto()) + "            " + top.get(7).getCliente() + "    " + newFormat.format(top.get(7).getCusto()));
        System.out.println("                                                        3         " + top.get(2).getCliente() + "    " + newFormat.format(top.get(2).getCusto()) + "            " + top.get(5).getCliente() + "    " + newFormat.format(top.get(5).getCusto()) + "            " + top.get(8).getCliente() + "    " + newFormat.format(top.get(8).getCusto()));

        System.out.println("");
        enterParaContinuar(tempo);
    }

    public void query8(int n, List<IQuery8Aux> topClientes,String tempo){
        Adicionais.Terminal.clear();
        int i = 1;

        List<IQuery8Aux> topList = topClientes.stream().limit(n).collect(Collectors.toList());

        System.out.println("                                                                                   Top       Cliente       Quantidade");

        for(IQuery8Aux q : topList){
            if(i < 10) System.out.println("                                                                                    " + (i++) + "         " + q.getCliente() + "              " + q.getQt());
            else System.out.println("                                                                                   " + (i++) + "         " + q.getCliente() + "              " + q.getQt());
        }

        System.out.println("");
        enterParaContinuar(tempo);
    }

    public void query9(int x, List<IVenda> topX,String tempo){
        Adicionais.Terminal.clear();
        int i=0;

        System.out.println("                                                                                    Top       Clientes       Gasto");

        for(IVenda v : topX){
            if(i < 10) System.out.println("                                                                                     " + (i++) + "          " + v.getCodigoCliente() + "       " + v.getFaturacao());
            else System.out.println("                                                                                    " + (i++) + "          " + v.getCodigoCliente() + "         " + v.getFaturacao());
        }

        System.out.println("");
        enterParaContinuar(tempo);
    }

    public void query10(List<List<Map<String, Double>>> faturacao,String tempo){
        Adicionais.Terminal.clear();
        int filial = 0,mes = 0,k=1;
        boolean flag = true;



        while(flag) {

            Map<String,Double> produtos = faturacao.get(filial).get(mes);

            for(Map.Entry<String,Double> pr : produtos.entrySet()){
                System.out.print(pr.getKey() + " " + newFormat.format(pr.getValue()) + "   ");
                if(k==9){
                    System.out.println("");
                    k=0;
                }
                k++;
            }

            System.out.println(Colors.ANSI_RED+"\n\n                                                                                            Mes : " + (mes+1) + " - " + "Filial : " + (filial+1) + Colors.ANSI_RESET);
            System.out.println("");
            System.out.println(Colors.ANSI_GREEN + "                                                                                     Tempo de Execucao : " + Colors.ANSI_RESET +  tempo);
            System.out.println("                                                                                        1 -> Pesquisar (mes,filial)");
            System.out.println("                                                                                        0 -> Voltar ao Menu Queries");
            System.out.print(Colors.ANSI_GREEN + "                                                                                                Opcao : " + Colors.ANSI_RESET);

            switch(Input.lerInt()){

                case 1:
                    System.out.print("Indique o mes : ");
                    mes = Input.lerMes() - 1;
                    boolean valid = false;
                    while(!valid) {
                        System.out.print("Indique a filial : ");
                        filial = Input.lerInt();
                        if(filial > 0 && filial < 4) {
                            filial--;
                            valid = true;
                        }
                    }
                    break;

                default:
                    flag = false;
                    break;
            }
        }

    }



}
