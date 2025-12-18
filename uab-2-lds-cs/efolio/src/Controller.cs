{//Classe de configurações
public class IPCfg { 
public const string srvIP = "127.0.0.1"; 
public const int srvPort = 17666; 
}

namespace Exame {
    class Controller {
        Model model;
        View view;
        public Controller()
        {
            view = new View(this, model);
            model = new Model(this, view);
        }
        public void IniciarPrograma() {
			strint texto;
            model.newconnection();
			texto=view.getText();
        }
        public void UtilizadorInseriuTexto(string texto) {
			model.sendText(texto);
        }       
    }
}