/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rand.h"

bool_t
xdr_datos (XDR *xdrs, datos *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_double (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->b))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->r))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->message, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}