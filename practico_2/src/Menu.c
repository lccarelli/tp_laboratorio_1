#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Menu.h"
#include "utn.h"

void menu_main(int* select){

	printf("\nMenu:"
			"\n\t1). Altas"
			"\n\t2). Modificar"
			"\n\t3). Baja"
			"\n\t4). Informes"
			"\n\t0). salir\n");
	utn_getNumero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 4, 3);
}

void menu_modify(int* select){

	printf("\nMenu para modificar:"
			"\n\t1). Nombre"
			"\n\t2). Apellido"
			"\n\t3). Salario"
			"\n\t4). Sector"
			"\n\t0). salir\n");
	utn_getNumero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 4, 3);
}

void menu_info(int* select){

	printf("\nMenu de Informes:"
			"\n\t1). Listado de los empleados ordenados alfabéticamente por Apellido y Sector"
			"\n\t2). Total y promedio de los salarios, y cuántos empleados superan el salario promedio"
			"\n\t0). salir\n");
	utn_getNumero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 2, 3);
}
