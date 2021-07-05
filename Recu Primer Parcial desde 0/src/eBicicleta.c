#include "eBicicleta.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int bicicleta_searchIndexById(eBicicleta* unaBicicleta, int size, int id)
{
	int rtn = -1;
	int i;

	for (i=0; i<size; i++)
	{
		if (unaBicicleta[i].id == id)
		{
			rtn = i;
		}
	}
	return rtn;
}

void bicicleta_listarBicicletas(eBicicleta* listaBicicletas, int size)
{
	int i;

	printf ("idBicicleta  Marca  Rodado  Color \n");
	for (i=0; i<size; i++)
	{
		bicicleta_mostrarUnaBicicleta(listaBicicletas, i);
	}
}

void bicicleta_mostrarUnaBicicleta (eBicicleta* unaBicicleta, int index)
{
	printf ("%d  %s  %d  %s\n", unaBicicleta[index].id, unaBicicleta[index].marca, unaBicicleta[index].rodado, unaBicicleta[index].color);
}

int bicicleta_getIdBicicleta(eBicicleta* listaBicicletas, int size2)
{
	int rtn = -1;
	int idBicicleta;
	int flagError = 0;
	int i;

	while (flagError <= 3)
	{
		Get_Int("ingrese un id de bicicleta de la lista:\n", "ERROR. el id debe ser numerico. ingrese un id de bicicleta de la lista:\n", &idBicicleta);
		for(i=0; i<size2; i++)
		{
			if (idBicicleta == listaBicicletas[i].id)
			{
				rtn = idBicicleta;
				flagError = 3;
				break;
			}
		}
		flagError++;
	}
	return rtn;
}

int bicicleta_validarId(eBicicleta* unaBicicleta, int size, int auxId)
{
    int rtn = 0;
    int i;

    for (i=0; i<size; i++)
    {
        if (unaBicicleta[i].id == auxId)
        {
            rtn = auxId;
            break;
        }
    }
    return rtn;
}


