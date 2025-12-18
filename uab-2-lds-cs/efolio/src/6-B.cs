{//Classe de configurações
public class IPCfg { 
public const string srvIP = "127.0.0.1"; 
public const int srvPort = 17666; 
}

namespace Exame {
    class Controller {
        Model model;
        View view;
		
		public delegate void setnewconnection(object origem);
        public event setnewconnection newconnection;
		
        public Controller()
        {
            view = new View(this, model);
            model = new Model(this, view);
			
			view.UtilizadorInseriuTexto += model.sendText(System.EventArgs args);		
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