/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rand.h"

datos *
suma_1_svc(datos *argp, struct svc_req *rqstp)
{
	static datos  result;

  result.r = argp->a + argp->b;
  memcpy(result.message, "Suma exitosa", 100);

	return &result;
}

datos *
producto_1_svc(datos *argp, struct svc_req *rqstp)
{
	static datos  result;

  result.r = argp->a * argp->b;
  memcpy(result.message, "Producto exitosa", 100);

	return &result;
}

datos *
cociente_1_svc(datos *argp, struct svc_req *rqstp)
{
	static datos  result;

  result.r = argp->a / argp->b;
  memcpy(result.message, "Cociente exitosa", 100);

	return &result;
}
