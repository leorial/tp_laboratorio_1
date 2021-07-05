#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int controller_listarTrabajos(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
	int rtn = 0;
	int i;

	printf("idTrabajo  marca  rodado  servicio  precio  fecha  tipoDeFactura medioDePago\n");
    for(i=0; i<size1; i++)
    {
    	controller_listarUnTrabajo(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i);

    }
    return rtn;
}

int controller_listarUnTrabajo (eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4, int index)
{
	int rtn = 0;
	int indexBicicleta;
	int indexServicio;
	int indexFactura;

    if (listaTrabajos[index].idTrabajo != -1 && listaTrabajos[index].isEmpty == OCUPADO)
    {
    	indexBicicleta = bicicleta_searchIndexById(listaBicicletas, size2, listaTrabajos[index].idBicicleta);
    	indexServicio = servicio_searchIndexById(listaServicios, size3, listaTrabajos[index].idServicio);
    	indexFactura = factura_searchIndexById(listaFacturas, size4, listaTrabajos[index].idFactura);

        printf ("%5d  %5s  %5d  %5s  %5.0f  %d/%d/%d  %5s  %5s\n",  listaTrabajos[index].idTrabajo,
																	listaBicicletas[indexBicicleta].marca,
																	listaBicicletas[indexBicicleta].rodado,
																	listaServicios[indexServicio].descripcion,
																	listaServicios[indexServicio].precio,
																	listaTrabajos[index].fecha.dia,
																	listaTrabajos[index].fecha.mes,
																	listaTrabajos[index].fecha.anio,
																	listaFacturas[indexFactura].tipoFactura,
																	listaFacturas[indexFactura].medioDePago);
        rtn = 1;
    }
	return rtn;
}

int controller_agregarUnTrabajo (eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4, int index, int* lastId)
{
	int rtn = 0;
	eTrabajo auxTrabajo;
	int idBicicleta;
	int idServicio;
	int idFactura;

	auxTrabajo.idTrabajo = *lastId;
	bicicleta_listarBicicletas(listaBicicletas, size2);
	idBicicleta = bicicleta_getIdBicicleta(listaBicicletas, size2);
	if(idBicicleta == -1)
	{
		return rtn;
	}
	else
	{
		auxTrabajo.idBicicleta = idBicicleta;
	}

	servicio_listarServicios(listaServicios, size3);
	idServicio = servicio_getIdServicio(listaServicios, size3);
	if(idServicio == -1)
	{
		return rtn;
	}
	else
	{
		auxTrabajo.idServicio = idServicio;
	}

	factura_listarFacturas(listaFacturas, size4);
	idFactura = factura_getIdFactura(listaFacturas, size4);
	if(idFactura == -1)
	{
		return rtn;
	}
	else
	{
		auxTrabajo.idFactura = idFactura;
	}

	trabajo_getDate(&auxTrabajo, size1);

	auxTrabajo.isEmpty = OCUPADO;

	printf("idTrabajo  marca  rodado  servicio  precio  fecha  tipoDeFactura medioDePago\n");
	controller_listarUnTrabajo(&auxTrabajo, 1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, 0);
    if (Validate_YesOrNo("Desea confirma la nueva carga de datos? s/n:\n", "ERROR. seleccione una opcion valida.\nDesea confirma la nueva carga de datos? s/n:\n"))
    {
    	listaTrabajos[index] = auxTrabajo;
        rtn = 1;
        *lastId = *lastId + 1;
    }
	return rtn;
}

int controller_modificarTrabajo(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
    int rtn = 0;
    int auxId;

    controller_listarTrabajos(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4);
    Get_Int("ingrese el id del trabajo a modificar: \n",
            "lo ingresado no es un id o es un id incorrecto. ingrese un id: \n",
			&auxId);

    if (trabajo_validarId(listaTrabajos, size1, auxId) != 0)
    {
        rtn = controller_opcionesAModificar(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, auxId);
    }
    else
    {
        rtn = 0;
    }
    return rtn;
}

int controller_opcionesAModificar(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4, int id)
{
    int i;
    int opcion;
    int rtn = 0;
    int auxiliar;
    int flag;

    for (i=0; i<size1; i++)
    {
    	if (id == listaTrabajos[i].idTrabajo)
    	{
    		printf("\nidTrabajo  marca  rodado  servicio  precio  fecha  tipoDeFactura medioDePago\n");
    		controller_listarUnTrabajo(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i);
    		Get_IntMinMax ("\n1 id de bicicleta\n2 id de servicio \nque desea modificar del trabajo?: \n",
    		               "opcion incorrecta. \n1 id de bicicleta\n2 id de servicio \nque desea modificar del trabajo?: \n",
    		               1, 2, &opcion);
            switch (opcion)
            {
                case 1 :
                    flag = 0;
                    bicicleta_listarBicicletas(listaBicicletas, size2);
                    printf("\nidTrabajo  marca  rodado  servicio  precio  fecha  tipoDeFactura medioDePago\n");
                    controller_listarUnTrabajo(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i);
                    do
                    {
                        Get_Int ("ingrese un nuevo id de bicicleta valido:\n", "ERROR. ingrese un id de bicicleta valido:", &auxiliar);
                        auxiliar = bicicleta_validarId(listaBicicletas, size2, auxiliar);
                        flag++;
                    }while(auxiliar == 0 || flag > 3);
                    if (auxiliar != 0)
                    {
                        if (Validate_YesOrNo("esta seguro que desea realizar el cambio? S/N:\n", " ERROR. esta seguro que desea realizar el cambio? S/N:\n"))
                        {
                            rtn = 1;
                            listaTrabajos[i].idBicicleta = auxiliar;
                        }
                    }
                    break;

                case 2 :
                    flag = 0;
                    servicio_listarServicios(listaServicios, size3);
                    printf("\nidTrabajo  marca  rodado  servicio  precio  fecha  tipoDeFactura medioDePago\n");
                    controller_listarUnTrabajo(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i);
                    do
                    {
                        Get_Int ("ingrese un nuevo id de servicio valido:\n", "ERROR. ingrese un id de servicio valido:", &auxiliar);
                        auxiliar = servicio_validarId(listaServicios, size3, auxiliar);
                        flag++;
                    }while(auxiliar == 0 || flag > 3);
                    if (auxiliar != 0)
                    {
                        if (Validate_YesOrNo("esta seguro que desea realizar el cambio? S/N:\n", " ERROR. esta seguro que desea realizar el cambio? S/N:\n"))
                        {
                            rtn = 1;
                            listaTrabajos[i].idServicio = auxiliar;
                        }
                    }
                    break;
             }
    	}
    }
    return rtn;
}

int controller_bajaDeTrabajo(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
    int id;
    int rtn = 0;
    int index;
    int flag = 0;

    do
    {
        controller_listarTrabajos(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4);
        Get_Int("ingrese el id del producto a dar de baja: \n",
                "ID incorrecto. ingrese el id del producto a dar de baja: \n",
                 &id);
        flag++;
    }while(trabajo_validarId(listaTrabajos, size1, id) == 0 && flag > 3);

    index = trabajo_buscarIndexPorId(listaTrabajos, size1, id);

    if (id != 0)
    {
        controller_listarUnTrabajo(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, index);
        rtn = Validate_YesOrNo("esta seguro que desea dar de baja ese producto? s/n: \n",
                               "opcion invalida. esta seguro que desea dar de baja ese producto? s/n: \n");
        if (rtn == 1)
        {
        	listaTrabajos[index].isEmpty = 0;
        }
    }
    return rtn;
}

void controller_listarTrabajosPorAnioYMarca(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
	int i;
	eTrabajo auxListaTrabajos[size1];

	trabajo_clonarListaTrabajos(listaTrabajos, size1, auxListaTrabajos, size1);

	for (i=0; i<size1-1; i++)
	{
		controller_ordenamientoPorAnioYMarca(auxListaTrabajos, size1, listaBicicletas, size2, i);
	}

	controller_listarTrabajos(auxListaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4);
}

void controller_ordenamientoPorAnioYMarca(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, int i)
{
    int j;
    eTrabajo auxiliar;

    for (j=i+1; j<size1; j++)
    {
    	if (listaTrabajos[j].fecha.anio > listaTrabajos[i].fecha.anio)
    	{
            auxiliar = listaTrabajos[i];
            listaTrabajos[i] = listaTrabajos[j];
            listaTrabajos[j] = auxiliar;
    	}
        else
        {
            if (listaTrabajos[j].fecha.anio == listaTrabajos[i].fecha.anio)
            {
                controller_ordenamientoPorMarca(listaTrabajos, size1, listaBicicletas, size2, i, j);
            }
        }
    }
}

void controller_ordenamientoPorMarca(eTrabajo* listaTrabajos, int size, eBicicleta* listaBicicletas, int size2, int i, int j)
{
	eTrabajo auxiliar;
	int idBicicleta1;
	int idBicicleta2;
	int indexBicicleta1;
	int indexBicicleta2;

	idBicicleta1 = listaTrabajos[i].idBicicleta;
	indexBicicleta1 = bicicleta_searchIndexById(listaBicicletas, size2, idBicicleta1);

	idBicicleta2 = listaTrabajos[j].idBicicleta;
	indexBicicleta2 = bicicleta_searchIndexById(listaBicicletas, size2, idBicicleta2);

    if(strcmp(listaBicicletas[indexBicicleta1].marca, listaBicicletas[indexBicicleta2].marca) > 0)
    {
            auxiliar = listaTrabajos[i];
            listaTrabajos[i] = listaTrabajos[j];
            listaTrabajos[j] = auxiliar;
    }
}

void controller_acumuladorPesosPorServicios(eTrabajo* listaTrabajos, int size1, eServicio* listaServicios, int size3)
{
	int i;
	float acumuladorPesos = 0;

	for (i=0; i<size1; i++)
	{
		if (listaTrabajos[i].isEmpty)
		{
			acumuladorPesos = acumuladorPesos + controller_sumadorPesos(listaTrabajos, size1, listaServicios, size3, i);
		}
	}
	 printf("\nTotal en pesos por los servicios prestados: $%2.f\n", acumuladorPesos);
}

float controller_sumadorPesos(eTrabajo* listaTrabajos, int size1, eServicio* listaServicios, int size3, int i)
{
	int j;
	float rtn;

	for(j=0; j<size3; j++)
	{
		if (listaTrabajos[i].idServicio == listaServicios[j].id)
		{
			rtn = listaServicios[j].precio;
			break;
		}
	}
	return rtn;
}

void controller_listarTrabajosPorMarca(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
	int i;
	int j;
	eTrabajo auxListaTrabajos[size1];

	trabajo_clonarListaTrabajos(listaTrabajos, size1, auxListaTrabajos, size1);

	for (i=0; i<size1-1; i++)
	{
		for (j=i+1; j<size1; j++)
		{
			controller_ordenamientoPorMarca(auxListaTrabajos, size1, listaBicicletas, size2, i, j);
		}
	}

	controller_listarTrabajos(auxListaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4);
}

void controller_contadorDeTrabajosRealizadosPorServicio(eTrabajo* listaTrabajos, int size1, eAuxServicio* auxListaServicios, int size3)
{
	int i;

	for (i=0; i<size1; i++)
	{
		controller_contadorDeServicios(listaTrabajos, size1, auxListaServicios, size3, i);
	}

	auxServicio_mostrarMayorContadorServicios(auxListaServicios, size3);
}

void controller_contadorDeServicios(eTrabajo* listaTrabajos, int size1, eAuxServicio* auxListaServicios, int size3, int i)
{
	int j;

	for (j=0; j<size3; j++)
	{
		if (listaTrabajos[i].idServicio == auxListaServicios[j].id)
		{
			auxListaServicios[j].contadorTrabajos =  auxListaServicios[j].contadorTrabajos + 1;
		}
	}
}

int controller_listarBicicletasSegunServicios (eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3)
{
	int rtn = 1;
	int i;

	for (i=0; i<size3; i++)
	{
		printf("\n\n\nDescripcion   Precio\n");
		printf("%s   %2.f\n",listaServicios[i].descripcion, listaServicios[i].precio);
		controller_mostrarBicicletaSegunServicio(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, i);
	}
	return rtn;
}

void controller_mostrarBicicletaSegunServicio(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, int i)
{
	int j;
	int idBicicleta;
	int indexBicicleta;

	printf("marca  rodado  color\n");
	for (j=0; j<size1; j++)
	{
		if (listaServicios[i].id == listaTrabajos[j].idServicio)
		{
			idBicicleta = listaTrabajos[j].idBicicleta;
			indexBicicleta = bicicleta_searchIndexById(listaBicicletas, size2, idBicicleta);
			printf("%s   %d   %s\n", listaBicicletas[indexBicicleta].marca, listaBicicletas[indexBicicleta].rodado, listaBicicletas[indexBicicleta].color);
		}
	}
}

int controller_contadorBicicletasRojasSegunServicio(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3)
{
	int idServicio;
	int i;
	int contadorBicicletasRojas = 0;
	int indexServicio;


	servicio_listarServicios(listaServicios, size3);
	Get_Int("seleccione id de servicio a contar: \n", "ERROR. seleccione id de servicio a contar: \n", &idServicio);
	indexServicio = servicio_searchIndexById(listaServicios, size3, idServicio);

	for (i=0; i<size1; i++)
	{
		if (listaTrabajos[i].idServicio == idServicio)
		{
			contadorBicicletasRojas = contadorBicicletasRojas + controller_contarBiciRoja(listaTrabajos, size1, listaBicicletas, size2, i);
		}
	}

	printf("la cantidad de bicicletas rojas que realizaron el servicio de %s fue: %d\n", listaServicios[indexServicio].descripcion, contadorBicicletasRojas);

	return contadorBicicletasRojas;
}

int controller_contarBiciRoja(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, int i)
{
	int rtn = 0;
	int j;

	for (j=0; j<size2; j++)
	{
		if (listaTrabajos[i].idBicicleta == listaBicicletas[j].id)
		{
			if (strcmp(listaBicicletas[j].color, "rojo") == 0)
			{
				rtn = 1;
			}
			break;
		}
	}
	return rtn;
}

void controller_listarTrabajosPorRodado(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
	int i;
	eTrabajo auxListaTrabajos[size1];

	trabajo_clonarListaTrabajos(listaTrabajos, size1, auxListaTrabajos, size1);

	for (i=0; i<size1-1; i++)
	{
		controller_ordenarTrabajoPorRodado(auxListaTrabajos, size1, listaBicicletas, size2, i);
	}

	controller_listarTrabajos(auxListaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4);
}

void controller_ordenarTrabajoPorRodado(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, int i)
{
    int j;
    eTrabajo auxiliar;
	int idBicicleta1;
	int idBicicleta2;
	int indexBicicleta1;
	int indexBicicleta2;

    for (j=i+1; j<size1; j++)
    {
    	idBicicleta1 = listaTrabajos[i].idBicicleta;
    	indexBicicleta1 = bicicleta_searchIndexById(listaBicicletas, size2, idBicicleta1);
    	idBicicleta2 = listaTrabajos[j].idBicicleta;
    	indexBicicleta2 = bicicleta_searchIndexById(listaBicicletas, size2, idBicicleta2);

    	if (listaBicicletas[indexBicicleta1].rodado > listaBicicletas[indexBicicleta2].rodado)
		{
			auxiliar = listaTrabajos[j];
			listaTrabajos[j] = listaTrabajos[i];
			listaTrabajos[i] = auxiliar;
		}
    }
}

void controller_mostrarContadorParchesConTarjeta(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
	int i;
	int contador = 0;

	for(i=0; i<size1; i++)
	{
		controller_contarParches(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i, &contador);
	}

	printf("la cantidad de parches abonados con tarjeta es de: %d\n\n", contador);

}

void controller_contarParches(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4, int i, int* contador)
{
	int j;

	for (j=0; j<size3; j++)
	{
		if (listaTrabajos[i].idServicio == listaServicios[j].id)
		{
			if (strcmp(listaServicios[j].descripcion, "Parche") == 0)
			{
				controller_contarParchesConTarjeta(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i, contador);
			}
		}
	}
}

void controller_contarParchesConTarjeta(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4, int i, int* contador)
{
	int k;

	for(k=0; k<size4; k++)
	{
		if (listaTrabajos[i].idFactura == listaFacturas[k].idFactura)
		{
			if (strcmp(listaFacturas[k].medioDePago, "Tarjeta") == 0)
			{
				*contador = *contador + 1;
			}
		}
	}
}

void controller_listarTrabajosEnEfectivo(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4)
{
	int i;

	printf("\nidTrabajo  marca  rodado  servicio  precio  fecha  tipoDeFactura medioDePago\n");
	for (i=0; i<size1; i++)
	{
		controller_listarUnTrabajoEnEfectivo(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i);
	}
}

void controller_listarUnTrabajoEnEfectivo(eTrabajo* listaTrabajos, int size1, eBicicleta* listaBicicletas, int size2, eServicio* listaServicios, int size3, eFactura* listaFacturas, int size4, int i)
{
	int j;

	for (j=0; j<size4; j++)
	{
		if (listaTrabajos[i].idFactura == listaFacturas[j].idFactura)
		{
			if (strcmp(listaFacturas[j].medioDePago, "Efectivo") == 0)
			{
				controller_listarUnTrabajo(listaTrabajos, size1, listaBicicletas, size2, listaServicios, size3, listaFacturas, size4, i);
			}
		}
	}
}








