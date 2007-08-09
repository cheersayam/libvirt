/*
 * xml.h: internal definitions used for XML parsing routines.
 */

#ifndef __VIR_XML_H__
#define __VIR_XML_H__

#include "libvirt/libvirt.h"
#include "internal.h"

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#ifdef __cplusplus
extern "C" {
#endif

int		virXPathBoolean	(const char *xpath,
				 xmlXPathContextPtr ctxt);
char *		virXPathString	(const char *xpath,
				 xmlXPathContextPtr ctxt);
int		virXPathNumber	(const char *xpath,
				 xmlXPathContextPtr ctxt,
				 double *value);
int		virXPathLong	(const char *xpath,
				 xmlXPathContextPtr ctxt,
				 long *value);
xmlNodePtr	virXPathNode	(const char *xpath,
				 xmlXPathContextPtr ctxt);
int		virXPathNodeSet	(const char *xpath,
				 xmlXPathContextPtr ctxt,
				 xmlNodePtr **list);

char *virDomainParseXMLDesc(virConnectPtr conn, const char *xmldesc, char **name, int xendConfigVersion);
char *virParseXMLDevice(virConnectPtr conn, char *xmldesc, int hvm, int xendConfigVersion);
int virDomainXMLDevID(virDomainPtr domain, char *xmldesc, char *class, char *ref);

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __VIR_XML_H__ */
