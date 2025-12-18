using System;
using System.Linq;
using System.Collections.Generic;

namespace ProjetoPDG
{
    internal class PauDeGiz
    {
        private int _peso;


        /// <summary>
        /// Inicializa uma instância da classe PausDeGiz, fornecendo o peso do giz
        /// </summary>
        /// <param name="p">peso do giz em gramas</param>
        public PauDeGiz(int p)
        {
            this.Peso = p;
        }

        public int Peso
        {
            get => this._peso;
            set
            {
                if (value <= 0)
                {
                    value = 1;
                }

                this._peso = value;
            }
        }
    };

    internal class FabricaDeGiz
    {
        public List<PauDeGiz> ObterGiz(int p)
        {
            var temp = new List<PauDeGiz>();

            for (var i = 0; i < p; i++)
            {
                temp.Add(new PauDeGiz(1));
            }

            return temp;
        }

        public bool MudarPeso(PauDeGiz pau, int novoPeso)
        {
            pau.Peso = novoPeso;
            return pau.Peso == novoPeso;
        }
    };

    internal class Belial
    {
        private List<PauDeGiz> _aMinhaCopiaPrivadaDeGiz;

        public Belial(List<PauDeGiz> lista)
        {
            this._aMinhaCopiaPrivadaDeGiz = lista;
        }

        public int NPausDeGiz
        {
            get => this._aMinhaCopiaPrivadaDeGiz.Count;
            set
            {
                if (this.NPausDeGiz != value)
                {
                    this._aMinhaCopiaPrivadaDeGiz = new FabricaDeGiz().ObterGiz(value);
                }
            }
        }

        public int PesoTotal
        {
            get => this._aMinhaCopiaPrivadaDeGiz.Sum(pau => pau.Peso);
            set
            {
                if (this.PesoTotal != value)
                {
                    this._aMinhaCopiaPrivadaDeGiz = new FabricaDeGiz().ObterGiz(value);
                }
            }
        }

        public bool MudarPesoTotal(int novoPeso, List<PauDeGiz> lista)
        {
            var pesoAcumulado = 0;

            for (var i = 0; i < lista.Count; i++)
            {
                var pau = lista[i];

                if (pesoAcumulado + pau.Peso <= novoPeso)
                {
                    pesoAcumulado += pau.Peso;
                }
                else
                {
                    lista.RemoveRange(i, lista.Count - i);
                }
            }

            if (pesoAcumulado < novoPeso)
            {
                lista.Add(new PauDeGiz(novoPeso - pesoAcumulado));
            }

            return true;
        }

        public bool MudarPesoTotal(int novoPeso)
        {
            if (this.PesoTotal == novoPeso)
            {
                return true;
            }

            var pesoAcumulado = 0;
            for (var i = 0; i < this._aMinhaCopiaPrivadaDeGiz.Count; i++)
            {
                var pau = this._aMinhaCopiaPrivadaDeGiz[i];

                if (pesoAcumulado + pau.Peso <= novoPeso)
                {
                    pesoAcumulado += pau.Peso;
                }
                else
                {
                    this._aMinhaCopiaPrivadaDeGiz.RemoveRange(i, this._aMinhaCopiaPrivadaDeGiz.Count - i);
                }
            }

            if (this.PesoTotal < novoPeso)
            {
                this._aMinhaCopiaPrivadaDeGiz.Add(new PauDeGiz(novoPeso - this.PesoTotal));
            }

            return true;
        }

        public int PesoMedio()
        {
            return this.PesoTotal / this.NPausDeGiz;
        }
    }

    internal class Program
    {
        private readonly FabricaDeGiz _fabrica = new FabricaDeGiz();

        private static List<PauDeGiz> _oMeuGiz;

        public void Amadis(int gramas)
        {
            _oMeuGiz = this._fabrica.ObterGiz(gramas);
        }

        private static void Main(string[] args)
        {
            var programa = new Program();

            //Obter giz para o cliente Dante.
            programa.Amadis(10);
            Console.WriteLine("Obtive corretamente 10 gramas de giz para o cliente Dante.");

            // Obter giz para o cliente Gil Vicente.
            // Usar para o exemplo do garbage collector
            programa.Amadis(44);
            Console.WriteLine("Obtive corretamente 44 gramas de giz para o cliente Gil Vicente.");

            var belial = new Belial(_oMeuGiz);
            Console.WriteLine($"Não sabem que meti aqui esta linha, mas posso dizer que os {belial.PesoTotal} gramas de giz vêm em {belial.NPausDeGiz} paus.");
            Console.WriteLine($"Em média, {belial.PesoMedio()} gramas por pau.");

            belial.MudarPesoTotal(100);
            Console.WriteLine($"No Belial estão {belial.NPausDeGiz} paus de giz, que pesam {belial.PesoTotal}");

            belial.MudarPesoTotal(85);
            Console.WriteLine($"No Belial estão agora {belial.NPausDeGiz} paus de giz, que pesam {belial.PesoTotal}");

            belial.MudarPesoTotal(88);
            Console.WriteLine($"No Belial estão agora {belial.NPausDeGiz} paus de giz, que pesam {belial.PesoTotal}");

            var listaDeTeste = new FabricaDeGiz().ObterGiz(20);
            Console.WriteLine($"Na lista de teste estão agora {listaDeTeste.Count} paus de giz, que pesam {listaDeTeste.Count} gramas.");

            belial.MudarPesoTotal(100, listaDeTeste);
            Console.WriteLine($"Na lista de teste estão agora {listaDeTeste.Count} paus de giz, que pesam 100 gramas.");

            belial.MudarPesoTotal(18, listaDeTeste);
            Console.WriteLine($"Na lista de teste estão agora {listaDeTeste.Count} paus de giz, que pesam 18 gramas.");

            Console.WriteLine(Environment.NewLine);
            Console.WriteLine(Environment.NewLine);

            var fabrica = new FabricaDeGiz();
            var pauDeGiz = new PauDeGiz(10);
            Console.WriteLine($"O pau tem {pauDeGiz.Peso} gramas.");

            fabrica.MudarPeso(pauDeGiz, 20);
            Console.WriteLine($"O pau tem {pauDeGiz.Peso} gramas. Devia ter 20, tem?");

            Console.WriteLine("<<CARO ALUNO: pode pressionar qualquer tecla para concluir este exemplo.>>");
            Console.ReadKey();
        }
    }
}