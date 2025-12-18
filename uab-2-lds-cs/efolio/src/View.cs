namespace Exame {
    public partial class View {
        private Controller controller;
        private Model model;

        internal View(Controller c, Model m)
        {
            controller = c;
            model = m;
        }

        public void getText()
        {
            //Explicar ao utilizador o modo de interação
			Console.WriteLine("\nEscreva 'sair' para parar o cliente!");
			//Obter comando
			string ipt = Console.ReadLine();
			return ipt;
        }
    }
}