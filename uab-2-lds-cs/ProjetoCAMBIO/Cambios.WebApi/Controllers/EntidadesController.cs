using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Cambios.WebApi.Interfaces;
using Cambios.WebApi.Models;

namespace Cambios.WebApi.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class EntidadesController : ControllerBase
    {
        private readonly IServiceEntidades _serviceEntidades;

        public EntidadesController(IServiceEntidades serviceEntidades)
        {
            this._serviceEntidades = serviceEntidades;
        }

        [HttpGet]
        public IEnumerable<Entidade> Get()
        {
            return this._serviceEntidades.Get();
        }
    }
}
