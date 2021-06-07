#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

static int parser_add(FILE* pFile, LinkedList* pArrayListEmployee, int method);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int result = ERROR;

	if(pFile!=NULL && pArrayListEmployee!=NULL){

		do {
			if(parser_add(pFile, pArrayListEmployee, ADD_CHAR) == 0){
				result = OK;
			}


		} while(!feof(pFile));
	}
    return result;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int result = ERROR;

	if(pFile!=NULL && pArrayListEmployee!=NULL){

		do {
			if(parser_add(pFile, pArrayListEmployee, ADD_BINARY) == 0){
				result = OK;
			}

		} while(!feof(pFile));
	}
    return result;
}


static int parser_add(FILE* pFile, LinkedList* pArrayListEmployee, int method){

	int result = ERROR;
	Employee* empleado;
    char id[51];
    char nombre[51];
    char horas[51];
    char sueldo[51];

	if(method == ADD_BINARY){

		empleado = employee_new();
		if(fread(empleado, sizeof(Employee), 1, pFile) == 1){
			ll_add(pArrayListEmployee, empleado);
			printf("\nentre a binary");
			result = OK;
		}
	}

	if(method == ADD_CHAR){

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
        empleado = employee_newParametros(id,nombre,horas,sueldo);
        ll_add(pArrayListEmployee,empleado);
        result = OK;
	}

	return result;
}
