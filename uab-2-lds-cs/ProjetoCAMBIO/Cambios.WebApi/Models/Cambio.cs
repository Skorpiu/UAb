using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text.Json.Serialization;
using System.Threading.Tasks;
using Cambios.WebApi.Helpers;
using Cambios.WebApi.Helpers.Extensions;

namespace Cambios.WebApi.Models
{
    public class Cambio
    {
        public Cambio(/*Entidade entidade, */Moeda origem, Moeda destino, decimal valor, decimal taxa)
        {
            //this.Entidade = entidade;
            this.MoedaOrigem = origem;
            this.MoedaDestino = destino;
            this.ValorOrigem = valor;
            this.Taxa = taxa;
        }

        // public Entidade Entidade { get; set; }

        [JsonIgnore]
        public Moeda MoedaOrigem { get; set; }

        [JsonIgnore]
        public Moeda MoedaDestino { get; set; }

        public string MoedaOrigemDesc => this.MoedaOrigem.GetDescription();

        public string MoedaDestinoDesc => this.MoedaDestino.GetDescription();

        public decimal ValorOrigem { get; set; }

        public decimal Taxa { get; set; }

        public decimal ValorDestino => MoedaOrigem == Moeda.Aoa ? this.ValorOrigem / this.Taxa : this.ValorOrigem * this.Taxa;
    }
}
