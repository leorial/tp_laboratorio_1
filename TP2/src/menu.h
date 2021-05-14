#include "biblioteca.h"

#ifndef MENU_H_
#define MENU_H_

/**
 * @fn void Show_Menu(Employee[], int)
 * @brief muestra el menu principal en bucle hasta que se desee salir.
 * @param Employee lista de empleados
 * @param int tamaño de array
 */void Show_Menu (Employee[], int);

 /**
   * @fn void Show_SubMenu(Employee[], int)
  * @brief muestra un submenu de informes
  * @param Employee lista de empleados
  * @param int tamaño de array
  */
void Show_SubMenu (Employee[], int);

#endif /* MENU_H_ */
