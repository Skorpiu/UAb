using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Threading.Tasks;

namespace Cambios.WebApi.Helpers
{
    public enum Moeda
    {
        [Description("Kwanza")]
        Aoa = 0,

        [Description("Euro")]
        Eur = 1,

        [Description("Dólar Americano")]
        Usd = 2
    }
}
