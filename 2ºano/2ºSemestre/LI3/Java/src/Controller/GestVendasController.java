package Controller;

import Adicionais.*;
import Model.GestVendasModel;
import Model.IGestVendasModel;
import Model.IVenda;
import View.IGestVendasView;


import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class GestVendasController implements IGestVendasController {

    private IGestVendasModel model;
    private IGestVendasView view;

    public GestVendasController(IGestVendasModel model, IGestVendasView view) {
        this.model = model;
        this.view = view;
    }

    /**
     * Método run.
     */
    public void run() {
        this.view.menu(0);

        switch (Input.lerInt()) {

            case 1:
                this.lerFicheiros();
                this.run();
                break;

            case 2:
                Crono.start();
                try {
                    this.guardar();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                Crono.stop();
                System.out.println("Tempo de Execuçao -> " + Crono.getTime());
                this.run();
                break;

            case 3:
                Crono.start();
                try {
                    this.ler();
                } catch (IOException | ClassNotFoundException e) {
                    e.printStackTrace();
                }
                Crono.stop();
                System.out.println("Tempo de Execuçao -> " + Crono.getTime());
                this.run();
                break;
            case 4:
                if (this.model.getUltFicheiroLido() != null) {
                    this.dadosEstatisticos();
                } else {
                    System.out.println("Nenhum Ficheiro Lido");
                }
                this.run();
                break;

            case 5:
                if (this.model.getUltFicheiroLido() != null) {
                    this.queries();
                } else {
                    System.out.println("Nenhum Ficheiro Lido");
                }
                this.run();
                break;

            case 0:
                break;

            default:
                System.out.println("Opcao Invalida");
                this.run();
                break;

        }

    }


    /**
     * Método para os dados estatísticos.
     */
    public void dadosEstatisticos() {
        this.view.menu(1);

        switch (Input.lerInt()) {

            case 1:
                this.dadosEstatisticos_UltFicheiro();
                this.dadosEstatisticos();
                break;

            case 2:
                this.dadosEstatisticos_Gerais();
                this.dadosEstatisticos();
                break;

            case 0:
                break;

            default:
                System.out.println("Opcao Invalida");
                this.dadosEstatisticos();
                break;
        }


    }


    /**
     * Método para as queries.
     */
    public void queries() {
        this.view.menu(2);

        switch (Input.lerInt()) {

            case 1:
                Crono.start();
                Set<String> res1 = model.query1();
                this.view.query1(res1, Crono.getTime());
                this.queries();
                break;

            case 2:
                System.out.println("Insira um mes");
                int mes = Input.lerMes();
                Crono.start();
                int[] res2 = model.query2(mes);
                this.view.query2(mes, res2, Crono.getTime());
                this.queries();
                break;

            case 3:
                System.out.println("Insira um codigo de cliente");
                String cliente = Input.lerCliente();
                Crono.start();
                double[] res3 = model.query3(cliente);
                this.view.query3(cliente, res3, Crono.getTime());
                this.queries();
                break;

            case 4:
                System.out.println("Insira um codigo de produto");
                String produto = Input.lerProduto();
                Crono.start();
                double[] res4 = model.query4(produto);
                this.view.query4(produto, res4, Crono.getTime());
                this.queries();
                break;

            case 5:
                System.out.println("Insira um codigo de cliente");
                cliente = Input.lerCliente();
                Crono.start();
                List<IVenda> res5 = model.query5(cliente);
                this.view.query5(cliente, res5, Crono.getTime());
                this.queries();
                break;

            case 6:
                System.out.println("Insira um inteiro");
                int n = Input.lerInt();
                Crono.start();
                List<IQuery6Aux> res6 = model.query6(n);
                this.view.query6(n, res6, Crono.getTime());
                this.queries();
                break;

            case 7:
                Crono.start();
                List<IParClienteCusto> res7 = model.query7();
                this.view.query7(res7, Crono.getTime());
                this.queries();
                break;

            case 8:
                System.out.println("Insira um inteiro");
                n = Input.lerInt();
                Crono.start();
                List<IQuery8Aux> res8 = model.query8(n);
                this.view.query8(n, res8, Crono.getTime());
                this.queries();
                break;

            case 9:
                System.out.println("Insira o Produto");
                produto = Input.lerProduto();
                System.out.println("Insira o tamanho X");
                int x = Input.lerInt();
                Crono.start();
                List<IVenda> res9 = model.query9(produto, x);
                this.view.query9(x, res9, Crono.getTime());
                this.queries();
                break;

            case 10:
                Crono.start();
                List<List<Map<String, Double>>> res10 = model.query10();
                this.view.query10(res10, Crono.getTime());
                this.queries();
                break;


            case 0:
                break;

            default:
                System.out.println("Opcao Invalida");
                this.queries();
                break;
        }
    }


    /**
     * Método para guardar.
     *
     * @throws IOException
     */
    public void guardar() throws IOException {
        boolean valido;
        do {
            System.out.println("Insira o nome do ficheiro!\n Exemplo : exemplo.txt");
            String fileName = Input.lerString();
            valido = Input.nomeFicheiro(fileName);
            model.writeObject(fileName);
        } while (!valido);
    }

    /**
     * Método para ler.
     *
     * @throws IOException
     * @throws ClassNotFoundException
     */
    public void ler() throws IOException, ClassNotFoundException {
        System.out.println(("Insira o nome do ficheiro!"));
        String fileName = Input.lerString();
        IGestVendasModel modelLido;
        modelLido = model.readObject(fileName);
        model = modelLido;
    }

    /**
     * Método para ler ficheiros iniciais.
     */
    public void lerFicheiros() {
        String fd_clientes, fd_produtos, fd_vendas;

        System.out.print("Ficheiro de Clientes : ");
        fd_clientes = Input.lerString().trim();
        System.out.print("Ficheiro de Produtos : ");
        fd_produtos = Input.lerString().trim();
        System.out.print("Ficheiro de Vendas : ");
        fd_vendas = Input.lerString().trim();


        if (fd_clientes.isEmpty()) {
            File file = new File("DadosIniciais/Clientes.txt");
            fd_clientes = file.getAbsolutePath();
        }
        if (fd_produtos.isEmpty()) {
            File file = new File("DadosIniciais/Produtos.txt");
            fd_produtos = file.getAbsolutePath();
        }

        if (fd_vendas.isEmpty()){
            File file = new File("DadosIniciais/Vendas_1M.txt");
            fd_vendas = file.getAbsolutePath();
        }


        Crono.start();
        this.model.criarData(fd_clientes, fd_produtos, fd_vendas);
        Crono.stop();

        System.out.println("Tempo de Execuçao -> " + Crono.getTime());

    }


    /**
     * Dados estatísticos do ùltimo ficheiro.
     */
    public void dadosEstatisticos_UltFicheiro() {
        this.view.dadosEstatisticos_UltiFicheiro(this.model.getUltFicheiroLido()
                , this.model.getVendasErradas()
                , this.model.getPRDS().size()
                , (this.model.getPRDS().size() - this.model.produtosNaoComprados().size())
                , this.model.produtosNaoComprados().size()
                , this.model.getCLS().size()
                , (this.model.getCLS().size() - this.model.clientesNuncaCompraram().size())
                , this.model.clientesNuncaCompraram().size()
                , this.model.getVendasValorZero()
                , this.model.faturacaoTotal());


    }

    /**
     * Dados estatísticos gerais.
     */
    public void dadosEstatisticos_Gerais() {
        this.view.dadosEstatisticos_Gerais(this.model.numComprasMensal()
                , this.model.faturacaoMensalGlobal()
                , this.model.faturacaoMensalFilial()
                , this.model.numClientesMensalFilial());
    }

}
