#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Menu.h"

int main(void) {
	int select;
	int flagAdd = 0;
	Employee list[EMPLOYEE_CANT];

	initEmployees(list, EMPLOYEE_CANT);
	employee_harcodeData(list, EMPLOYEE_CANT);

	do {
		menu_main(&select);

				switch(select){

				case ADD:

					(employee_register(list, EMPLOYEE_CANT, &flagAdd) == 0) ?
							printf("\nAccion realizada con exito.") :
							printf("\nDebe ingresar un empleado. ");
					break;

				case MODIFY:

					(flagAdd && employee_functionMultiple(employee_modify, list, EMPLOYEE_CANT) == 0) ?
							printf("\nAccion realizada con exito.") :
							printf("\nDebe ingresar un empleado. ");
					break;

				case LOW:

					(flagAdd && employee_functionMultiple(removeEmployee, list, EMPLOYEE_CANT) == 0) ?
							printf("\nAccion realizada con exito.") :
							printf("\nDebe ingresar un empleado. ");
					break;

				case INFO:

					flagAdd ?
							employee_getInforms(list, EMPLOYEE_CANT) :
							printf("\nDebe ingresar un empleado.");
					break;
				}

		} while(!(select == EXIT));

	return EXIT_SUCCESS;
}
