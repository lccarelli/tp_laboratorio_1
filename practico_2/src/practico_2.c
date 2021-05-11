#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Menu.h"

int main(void) {
	int select;
	int index;
	int id;
	int flagAdd = 0;

	char name[51];
	char lastname[51];
	float salary;
	int sector;

	Employee list[EMPLOYEE_CANT];

	initEmployees(list, EMPLOYEE_CANT);
	employee_harcodeData(list, EMPLOYEE_CANT);

	do {
		menu_main(&select);

				switch(select){

				case ADD:

					if(
							employee_getFreeIndex(list, EMPLOYEE_CANT, &index) == 0 &&
							employee_generateId(list, EMPLOYEE_CANT, index, &id) == 0 &&
							employee_requestData(name, lastname, &salary, &sector) == 0 &&
							addEmployee(list, EMPLOYEE_CANT, index, id, name, lastname, salary, sector) == 0
					)
					{
						printf("\nEmpleado cargado por éxito->");
						employee_print(list, EMPLOYEE_CANT, index);
						flagAdd = 1;
					}
					break;

				case MODIFY:

					(flagAdd && employee_functionMultiple(employee_modify, list, EMPLOYEE_CANT) == 0) ?
							printf("\nAccion realizada con exito.") : printf("\nDebe ingresar un empleado. ");
					break;

				case LOW:

					(flagAdd && employee_functionMultiple(removeEmployee, list, EMPLOYEE_CANT) == 0) ?
							printf("\nAccion realizada con exito.") : printf("\nDebe ingresar un empleado. ");
					break;

				case INFO:

					flagAdd ? employee_getInforms(list, EMPLOYEE_CANT) : printf("\nDebe ingresar un empleado.");
					break;
				}

		} while(!(select == EXIT));

	return EXIT_SUCCESS;
}
