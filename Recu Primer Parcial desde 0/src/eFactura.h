
#ifndef EFACTURA_H_
#define EFACTURA_H_

 typedef struct
 {
	 int idFactura;
	 char tipoFactura[20];
	 char medioDePago[20];
 }eFactura;


 int factura_searchIndexById(eFactura* unaFactura, int size, int id);
 void factura_listarFacturas(eFactura* listaFacturas, int size);
 void factura_mostrarUnaFactura (eFactura* unaFactura, int index);
 int factura_getIdFactura(eFactura* listaFacturas, int size4);

#endif /* EFACTURA_H_ */

