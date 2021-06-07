#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Menu.h"
#include "utn.h"

void menu_main(int* select){

	printf("\nMenu:"
			"\n\t1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
			"\n\t2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
			"\n\t3. Alta de empleado"
			"\n\t4. Modificar datos de empleado"
			"\n\t5. Baja de empleado"
			"\n\t6. Listar empleados"
			"\n\t7. Ordenar empleados"
			"\n\t8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
			"\n\t9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
			"\n\t0. Salir");
	utn_getNumero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 9, 3);
}

void menu_modify(int* select){

	printf("\nMenu para modificar:"
			"\n\t1). NOMBRE"
			"\n\t2). SUELDO"
			"\n\t3). HORAS TRABAJADAS"
			"\n\t0). salir\n");
	utn_getNumero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 3, 3);
}
