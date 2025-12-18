namespace Exame {
    class Model {
        private Controller controller;
        private View view;

        public Model(Controller c, View v)
        {
            controller = c;
            view = v;
        }

        public void newconnection() {
			//Criar e configurar objeto de gestão das comunicações
			cliente = new PESocket<ClientSession, NetMsg>(); 
			cliente.StartAsClient(IPCfg.srvIP, IPCfg.srvPort);
        }
		
		public void sendText(string ipt) {
            //Enviar mensagem pela rede
			cliente.session.SendMsg(new NetMsg {text = ipt});
        }
    }
}