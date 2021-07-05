
#ifndef EBICICLETA_H_
#define EBICICLETA_H_

typedef struct
{
    int id;
    char marca[25];
    int rodado;
    char color[10];
}eBicicleta;

int bicicleta_searchIndexById(eBicicleta* unaBicicleta, int size, int id);
void bicicleta_listarBicicletas(eBicicleta* listaBicicletas, int size);
void bicicleta_mostrarUnaBicicleta (eBicicleta* unaBicicleta, int index);
int bicicleta_getIdBicicleta(eBicicleta* listaBicicletas, int size2);
int bicicleta_validarId(eBicicleta* unaBicicleta, int size, int auxId);


















#endif /* EBICICLETA_H_ */
