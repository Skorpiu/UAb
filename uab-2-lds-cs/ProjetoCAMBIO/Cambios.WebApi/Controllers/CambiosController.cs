using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Runtime.Serialization;
using System.Threading.Tasks;
using Cambios.WebApi.Helpers;
using Cambios.WebApi.Interfaces;
using Cambios.WebApi.Models;
using HtmlAgilityPack;

namespace Cambios.WebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class CambiosController : ControllerBase
    {
        private readonly ILogger<CambiosController> _logger;
        private readonly IServiceEntidades _serviceEntidades;
        private readonly IServiceCambios _serviceCambios;

        public CambiosController(
            ILogger<CambiosController> logger,
            IServiceEntidades serviceEntidades,
            IServiceCambios serviceCambios)
        {
            this._logger = logger;
            this._serviceEntidades = serviceEntidades;
            this._serviceCambios = serviceCambios;
        }

        [HttpGet("{moedaOrigem}/{moedaDestino}/{valor}")]
        public ActionResult Get(string moedaOrigem, string moedaDestino, decimal valor)
        {
            if (!TryGetMoedaFromString(moedaOrigem, out var eMoedaOrigem) 
                || !TryGetMoedaFromString(moedaDestino, out var eMoedaDestino))
            {
                return this.BadRequest("A moeda de " + (!eMoedaOrigem.HasValue ? "origem" : "destino") + " não é suportada.");
            }

            if (eMoedaOrigem == eMoedaDestino)
            {
                return this.BadRequest("A moeda de origem é igual à moeda de destino.");
            }

            if (eMoedaOrigem != Moeda.Aoa && eMoedaDestino != Moeda.Aoa)
            {
                return this.BadRequest("Apenas é possível converter de AOA ou para AOA.");
            }

            var cambios = new List<(Entidade entidade, Cambio cambio)>();
            var querComprar = eMoedaOrigem.Value == Moeda.Aoa;

            foreach (var entidade in this._serviceEntidades.Get())
            {
                Cambio cambio = null;

                var (compra, venda) = entidade.GetTaxaCambio(eMoedaOrigem.Value == Moeda.Aoa ? eMoedaDestino.Value : eMoedaOrigem.Value);

                var taxa = querComprar ? venda : compra;
                if (taxa is not null)
                {
                    cambio = new (eMoedaOrigem.Value, eMoedaDestino.Value, valor, taxa.Value);
                }

                cambios.Add((entidade, cambio));
            }

            return this.Ok(
                (querComprar ? cambios.OrderBy(x => x.cambio?.Taxa) : cambios.OrderByDescending(x => x.cambio?.Taxa))
                    .Select(cambio => new { cambio.entidade, cambio.cambio })
                    .ToList());
        }

        [HttpGet("{banco}/{moeda}")]
        public ActionResult Get(string banco, string moeda)
        {
            var entidade = this._serviceEntidades.Get()
                .FirstOrDefault(x => x.Codigo.ToLower() == banco.ToLower().Trim());

            if (entidade is null || !TryGetMoedaFromString(moeda, out var enumMoeda))
            {
                return this.NotFound();
            }

            var (compra, venda) = entidade.GetTaxaCambio(enumMoeda.Value);

            return this.Ok(new
            {
                entidade,
                compra = compra == null ? null : new Cambio(enumMoeda.Value, Moeda.Aoa, 1, compra.Value),
                venda = venda == null ? null : new Cambio(enumMoeda.Value, Moeda.Aoa, 1, venda.Value)
            });
        }


        private static bool TryGetMoedaFromString(string moeda, [NotNull] out Moeda? enumMoeda)
        {
            enumMoeda = moeda.ToLower().Trim() switch
            {
                "eur" => Moeda.Eur,
                "usd" => Moeda.Usd,
                "aoa" => Moeda.Aoa,
                _ => null,
            };

            return enumMoeda is not null;
        }
    }
}
