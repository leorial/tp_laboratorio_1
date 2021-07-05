//pido disculpas por la prolijidad, no llegue a hacer que encuadren las columnas de los listados al momento de printear.

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "controller.h"
#define TAM_SERV 4
#define TAM_TRAB 100
#define TAM_BIC 5
#define TAM_FACT 8

int main(void)
{
	setbuf(stdout, NULL);
    eTrabajo listaTrabajos[TAM_TRAB]; /**= {{14, 27, 20001, {30, 12, 1991}, 593, 1}, {44, 25, 20000, {2, 2, 2018}, 594, 1}, {96, 28, 20003, {20, 3, 2009}, 595, 1},
                                        {52, 26, 20001, {30, 12, 2018}, 600, 1}, {21, 29, 20000, {2, 2, 2009}, 597, 1}, {99, 27, 20003, {20, 3, 1991}, 598, 1}};**/
    eServicio listaServicios[TAM_SERV] = {{20000, "Limpieza", 250}, {20001, "Parche", 300}, {20002, "Centrado", 400}, {20003, "Cadena", 350}};
    eBicicleta listaBicicletas[TAM_BIC] = {{25, "lanus", 16, "rojo"}, {26, "avellaneda", 18, "azul"}, {27, "lomas", 20, "verde"},
    		                               {28, "escalada", 14, "amarilla"}, {29, "banfield", 22, "verde"}};
    eFactura listaFacturas[TAM_FACT] = {{593, "Factura B", "Efectivo"}, {594, "Factura C", "Tarjeta"}, {595, "Factura A", "Efectivo"}, {596, "Factura B", "Efectivo"},
    									{597, "Factura A", "Tarjeta"}, {598, "Factura C", "Efectivo"}, {599, "Factura C", "Cheque"}, {600, "Factura B", "Tarjeta"}};
    eAuxServicio auxListaServicios[TAM_SERV];
    int opcion;
    int flagMenu = 0;
    int index;
    int lastIdTrabajo = 1;

    trabajo_startArray (listaTrabajos, TAM_TRAB);
    auxServicio_inicializarEstructuraAuxiliar(listaServicios, TAM_SERV, auxListaServicios, TAM_SERV);

    do
    {
    	Show_MenuPrincipal();

        Get_IntMinMax("Seleccione una opcion: \n", "ERROR. Seleccione una opcion: \n", 0, 13, &opcion);

        switch (opcion)
        {
            case 0:
            	controller_listarTrabajos(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT);
                if (Validate_YesOrNo("Confirma que desea salir? S/N: \n", "ERROR! seleccione una opcion correcta. \nConfirma que desea salir? S/N: \n "))
                {
                    opcion = -1;
                    printf("PROGRAMA FINALIZADO.");
                }
                break;

            case 1:
            	index = trabajo_searchFree(listaTrabajos, TAM_TRAB);
                if (index == -1)
                {
                    printf("No hay mas lugar para ingresar productos.\n");
                }
                else
                {
                    if (controller_agregarUnTrabajo(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT, index, &lastIdTrabajo))
                    {
                    	flagMenu = 1;
                    }
                    else
                    {
                        printf("La carga de datos fue anulada.\n");
                    }
                }
                break;

            case 2:
                if (flagMenu == 1)
                {
                    if (controller_modificarTrabajo(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT))
                    {
                        printf("el producto se modifico correctamente. \n");
                    }
                    else
                    {
                        printf("error. no se encontro el producto a modificar. \n");
                    }
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 3:
                if (flagMenu == 1)
                {
                    if (controller_bajaDeTrabajo(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT))
                    {
                        printf("el producto se dio de baja correctamente. \n");
                    }
                    else
                    {
                        printf("error. no se encontro el producto a dar de baja. \n");
                    }
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 4:
                if (flagMenu == 1)
                {
                	controller_listarTrabajosPorAnioYMarca(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 5:
                if (flagMenu == 1)
                {
                	servicio_listarServicios(listaServicios, TAM_SERV);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 6:
                if (flagMenu == 1)
                {
                	controller_acumuladorPesosPorServicios(listaTrabajos, TAM_TRAB, listaServicios, TAM_SERV);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 7:
                if (flagMenu == 1)
                {
                	controller_listarTrabajosPorMarca(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 8:
                if (flagMenu == 1)
                {
                	controller_contadorDeTrabajosRealizadosPorServicio(listaTrabajos, TAM_TRAB, auxListaServicios, TAM_SERV);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 9:
                if (flagMenu == 1)
                {
                	controller_listarBicicletasSegunServicios(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 10:
                if (flagMenu == 1)
                {
                	controller_contadorBicicletasRojasSegunServicio(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 11:
                if (flagMenu == 1)
                {
                	controller_listarTrabajosPorRodado(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios,TAM_SERV, listaFacturas, TAM_FACT);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 12:
                if (flagMenu == 1)
                {
                	controller_mostrarContadorParchesConTarjeta(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

            case 13:
                if (flagMenu == 1)
                {
                	controller_listarTrabajosEnEfectivo(listaTrabajos, TAM_TRAB, listaBicicletas, TAM_BIC, listaServicios, TAM_SERV, listaFacturas, TAM_FACT);
                }
                else
                {
                    printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
                }
                break;

        }
    }while (opcion != -1);





}
