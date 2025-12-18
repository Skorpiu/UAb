using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Cambios.WebApi.Models;

namespace Cambios.WebApi.Interfaces
{
    public interface IServiceEntidades
    {
        IEnumerable<Entidade> Get();
    }
}
