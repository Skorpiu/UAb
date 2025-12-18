using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Cambios.WebApi.Models;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.DependencyInjection;

namespace Cambios.WebApi.Helpers.Extensions
{
    public static class HttpContextExtensions
    {
        //public static void AddHttpContextAccessor(this IServiceCollection services)
        //{
        //    services.AddSingleton<IHttpContextAccessor, HttpContextAccessor>();
        //}

        public static IApplicationBuilder UseHttpContext(this IApplicationBuilder app)
        {
            CambiosHttpContext.Configure(app.ApplicationServices.GetRequiredService<IHttpContextAccessor>());
            return app;
        }
    }
}
