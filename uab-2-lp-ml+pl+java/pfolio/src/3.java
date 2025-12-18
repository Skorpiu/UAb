public class videos
{
    String titulo;
    String duracao;
    String dataLancamento;
    String classificacao;
    String genero;

    public String getTitulo() {return titulo;} 
    public String settitulo(String titulo) {this.titulo = titulo;} 
    
    public String getValor() {return sinopse;} 
    public String setValor(String duracao) {this.duracao = duracao;}

    public String getDataLancamento() {return dataLancamento;} 
    public String setDataLancamento(String dataLancamento) {this.dataLancamento = dataLancamento;} 

    public String getClassificacao() {return classificacao;} 
    public String setClassificacao(String classificacao) {this.classificacao = classificacao;} 

    public String getGenero() {return genero;} 
    public String setGenero(String genero) {this.genero = genero;}
    
    public Void listaVideosDisponiveis(String titulo, String duracao, String dataLancamento, String classificacao, String genero)
    {
        this.titulo = titulo;
        this.duracao = duracao;
        this.dataLancamento = dataLancamento;
        this.classificacao = classificacao;
        this.genero = genero;
    }
};

public class filme
{
    Bool disponibilidade;
    String sinopse;
    String urlImagem;

    public Bool getDisponibilidade() {return disponibilidade;} 
    public Bool setDisponibilidade(String disponibilidade) {this.disponibilidade = disponibilidade;} 
    
    public String getSinopse() {return sinopse;} 
    public String setSinopse(String sinopse) {this.sinopse = sinopse;}

    public String getUrlImagem() {return urlImagem;} 
    public String setUrlImagem(String urlImagem) {this.urlImagem = urlImagem;} 
};

public class visualizacao
{
    String referencia;
    String dataVisualizacao;
    Bool subricao;

    public Bool getReferencia() {return referencia;} 
    public Bool setReferencia(String referencia) {this.referencia = referencia;} 
    
    public String getDataVisualizacao() {return dataVisualizacao;} 
    public String setDataVisualizacao(String dataVisualizacao) {this.dataVisualizacao = dataVisualizacao;}

    public Bool getSubricao() {return subricao;} 
    public Bool setSubricao(String subricao) {this.subricao = subricao;} 

    public Int listaVisualizacoesPorVideo(String referencia, String dataVisualizacao, Bool subricao)
    {
        this.referencia = referencia;
        this.dataVisualizacao = dataVisualizacao;

        Int acumulaVisualizacoes = 0;

        for (int i = 0; i < this.referencia; i++)
        {
            acumulaVisualizacoes += this.referencia;
        }

        return acumulaVisualizacoes;
    }

    public Int totalGostosPorVideo(String referencia, Bool subricao)
    {
        this.referencia = referencia;
        this.subricao = subricao;

        Int acumulaGostos = 0;

        for (int = i; this.referencia; i++)
        {
            if(subricao = 'Gosto'){
                acumulaGostos += this.subricao;
            }
            if(subricao != 'Gosto'){
                return false;
            }
        }

        return acumulaGostos;
    }
};

public class streaming
{
    private ArrayList<videos> = new ArrayList<videos>();
    private ArrayList<visualizacao> = new ArrayList<visualizacao>();

    listaVisualizacoesPorVideo(String referencia, String dataVisualizacao, Bool subricao);
    totalGostosPorVideo(String referencia, Bool subricao);

    for (int = i; streaming.size(); i++)
    {   
        System.out.println("Título: " + this.titulo);
        System.out.println("Género: " + this.genero); 
        System.out.println("Total de visualizações: " + acumulaVisualizacoes); 
        System.out.println("Total de gostos: " + acumulaGostos);
    
        System.out.println("");
    }
};