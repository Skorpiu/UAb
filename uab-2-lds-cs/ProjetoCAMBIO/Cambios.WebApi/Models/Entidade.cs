using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text.Json.Serialization;
using System.Threading.Tasks;
using Cambios.WebApi.Helpers;
using Microsoft.AspNetCore.Hosting.Builder;

namespace Cambios.WebApi.Models
{
    public class Entidade
    {
        public Entidade(
            string codigo,
            string descricao,
            string url,
            string logoFilename,
            Func<Moeda, (decimal?, decimal?)> getTaxaCambio)
        {
            this.Codigo = codigo;
            this.Descricao = descricao;
            this.Url = new(url);
            this.LogoFilename = logoFilename;
            this.GetTaxaCambio = getTaxaCambio;
        }

        public string Codigo { get; set; }

        /// <summary>
        /// Descrição da entidade
        /// </summary>
        public string Descricao { get; set; }


        /// <summary>
        /// URL do site público da entidade
        /// </summary>
        public Uri Url { get; set; }

        [JsonIgnore]
        public string LogoFilename { get; set; }

        public string LogoUrl => CambiosHttpContext.AppBaseUrl + "/assets/logos/" + this.LogoFilename;

        [JsonIgnore]
        public Func<Moeda, (decimal? compra, decimal? venda)> GetTaxaCambio { get; set; }
    }
}
