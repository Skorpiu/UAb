using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading.Tasks;
using Cambios.WebApi.Helpers;
using Cambios.WebApi.Interfaces;
using Cambios.WebApi.Models;
using HtmlAgilityPack;

namespace Cambios.WebApi.Services
{
    public class ServiceEntidades : IServiceEntidades
    {
        private static readonly IEnumerable<Entidade> Entidades =
            new List<Entidade>
            {
                GetBNA(),
                GetBFA(),
                GetATLANTICO()
            };

        public IEnumerable<Entidade> Get()
        {
            return Entidades;
        }

        public static Entidade GetBNA() => new (
            "BNA",
            "Banco Nacional de Angola",
            "https://www.bna.ao",
            "bna.png",
            moeda =>
            {
                var web = new HtmlWeb();
                var doc = web.Load("https://www.bna.ao/Servicos/cambios_table.aspx");

                return moeda switch
                {
                    Moeda.Eur => (
                       GetDecimalValueFromNode(doc, "//tr[td/text() = 'EUR']/td[2]"),
                       GetDecimalValueFromNode(doc, "//tr[td/text() = 'EUR']/td[2]")),
                    Moeda.Usd => (
                        GetDecimalValueFromNode(doc, "//tr[td/text() = 'USD']/td[2]"),
                        GetDecimalValueFromNode(doc, "//tr[td/text() = 'USD']/td[2]")),
                    _ => (null, null),
                };
            });

        public static Entidade GetBFA() => new(
            "BFA",
            "Banco de Fomento Angola",
            "https://www.bfa.ao",
            "bfa.png",
            moeda =>
            {
                var web = new HtmlWeb();
                var doc = web.Load("http://www.bfa.ao/Servicos/Cambios/Divisas.aspx");

                return moeda switch
                {
                    Moeda.Eur => (
                        GetDecimalValueFromNode(doc, "//td[@headers='compra eur']"),
                        GetDecimalValueFromNode(doc, "//td[@headers='venda eur']")),
                    Moeda.Usd => (
                        GetDecimalValueFromNode(doc, "//td[@headers='compra usd']"),
                        GetDecimalValueFromNode(doc, "//td[@headers='venda usd']")),
                    _ => (null, null),
                };
            });

        public static Entidade GetATLANTICO() => new(
            "ATLANTICO",
            "Banco Millenium Atlântico",
            "https://www.atlantico.ao",
            "atlantico.png", 
            moeda => {
                var web = new HtmlWeb();
                var doc = web.Load("http://www.atlantico.ao/pt/particulares/cambios/Pages/CurrencyExchange.aspx");

                return moeda switch
                {
                    Moeda.Eur => (
                        GetDecimalValueFromNode(doc, "//div[div[contains(@class,'EUR')]]/div[3]"),
                        GetDecimalValueFromNode(doc, "//div[div[contains(@class,'EUR')]]/div[4]")),
                    Moeda.Usd => (
                        GetDecimalValueFromNode(doc, "//div[div[contains(@class,'USD')]]/div[3]"),
                        GetDecimalValueFromNode(doc, "//div[div[contains(@class,'USD')]]/div[4]")),
                    _ => (null, null),
                };
            });

        private static decimal? GetDecimalValueFromNode(HtmlDocument doc, string node)
        {
            var nodeStrValue = doc.DocumentNode.SelectSingleNode(node)?
                .InnerHtml.Replace(" ", string.Empty).Replace(",", ".");

            return string.IsNullOrWhiteSpace(nodeStrValue)
                ? null
                : (decimal?)Convert.ToDecimal(nodeStrValue, CultureInfo.InvariantCulture);
        }
    }
}
