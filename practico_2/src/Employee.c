#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "Employee.h"
#include "Menu.h"
#include <string.h>

int employee_setId(Employee* list, int index, int id){
	int result = OK;
	(list!=NULL && id>0) ? (list[index].id = id) : (result = ERROR);
	return result;
}

int employee_setName(Employee* list, int index, char* name){
	int result = OK;
	if(list!=NULL && name!=NULL)
		strncpy(list[index].name, name, sizeof(list[index].name));
	else result = ERROR;
	return result;
}

int employee_setLastname(Employee* list, int index, char* lastname){
	int result = OK;
	if(list!=NULL && lastname!=NULL)
		strncpy(list[index].lastname, lastname, sizeof(list[index].lastname));
	else result = ERROR;
	return result;
}

int employee_setSalary(Employee* list, int index, float salary){
	int result = OK;
	(list!=NULL && salary>0) ? (list[index].salary = salary) : (result = ERROR);
	return result;
}

int employee_setSector(Employee* list, int index, int sector){
	int result = OK;
	(list!=NULL && sector>0) ? (list[index].sector = sector) : (result = ERROR);
	return result;
}

int employee_setIsEmpty(Employee* list, int index, int isEmpty){
	int result = OK;
	(list!=NULL) ? (list[index].isEmpty = isEmpty) : (result = ERROR);
	return result;
}

int employee_getId(Employee* list, int index){
	int aux = -1;
	if(list!=NULL) (aux = list[index].id);
	return aux;
}

char* employee_getName(Employee* list, int index){
	char* aux = NULL;
	if(list!=NULL) (aux = list[index].name);
	return aux;
}

char* employee_getLastname(Employee* list, int index){
	char* aux = NULL;
	if(list!=NULL) (aux = list[index].lastname);
	return aux;
}

float employee_getSalary(Employee* list, int index){
	float aux = -1;
	if(list!=NULL) (aux = list[index].salary);
	return aux;
}

int employee_getSector(Employee* list, int index){
	int aux = -1;
	if(list!=NULL) (aux = list[index].sector);
	return aux;
}

int employee_getIsEmpty(Employee* list, int index){
	int aux = 1;
	if(list!=NULL) (aux = list[index].isEmpty);
	return aux;
}

int initEmployees(Employee* list, int len){
	int result = ERROR;
	if(list!=NULL && len>0){
		for(int i=0; i<len; i++){
			employee_setIsEmpty(list, i, EMPTY_TRUE);
		}
		result = OK;
	}
	return result;
}

int employee_harcodeData(Employee* list, int len){
	int result = ERROR;
	Employee auxList[EMPLOYEE_HARDCODE] =
	{
			{1, "spike", "spiegel", 150.50, 1, 0},
			{2, "faye", "valentine", 160.10, 2, 0},
			{3, "ed", "hack", 250.00, 3, 0},
			{4, "jet", "black", 189.00, 1, 0},
			{5, "vicious", "wick", 190.90, 2, 0},
			{6, "john", "wick", 200.00, 3, 0},
	};

	if(EMPLOYEE_HARDCODE <= len){
		for(int i=0; i<EMPLOYEE_HARDCODE; i++){
			list[i] = auxList[i];
		}
		result = OK;
	}
	return result;
}

int employee_getFreeIndex(Employee* list, int len, int* index){
	int result = ERROR;

	if(list!=NULL && len>0 && index!=NULL){
		for(int i=0; i<len;i++){
			if(employee_getIsEmpty(list, i) == EMPTY_TRUE){
				*index = i;
				result = OK;
				break;
			}
		}
	}
	return result;
}

int employee_generateId(Employee* list, int len, int index, int* id){
	int result = OK;
	if(list!=NULL && len>0 && index<len && id!=NULL)
		(employee_getIsEmpty(list, index) == EMPTY_TRUE) ? (*id = index+1) : (result = ERROR);
	return result;
}

int employee_requestName(char* name){
	int result = ERROR;
	if (utn_getString(name, NAME_LEN, "\nNombre_Cliente?", "\nERROR-> Nombre_Cliente?", 3) == 0)
		result = OK;
	return result;
}

int employee_requestLastname(char* lastname){
	int result = ERROR;
	if (utn_getString(lastname, NAME_LEN, "\nApellido_Cliente?", "\nERROR-> Apellido_Cliente?", 3) == OK)
		result = OK;
	return result;
}

int employee_requestSalary(float* salary){
	int result = ERROR;
	if (utn_getNumeroFlotante(salary, "\nSalario?", "\nERROR-> Salario?", 0, 1000000000, 3) == OK)
		result = OK;
	return result;
}

int employee_requestSector(int* sector){
	int result = ERROR;
	if (utn_getNumero(sector, "\nSector?", "\nERROR-> Sector?", 0, 5, 3) == OK)
		result = OK;
	return result;
}

int employee_requestData(char* name, char* lastname, float* salary, int* sector){
	int result = ERROR;
	if(
			employee_requestName(name) == OK &&
			employee_requestLastname(lastname) == OK &&
			employee_requestSalary(salary) == OK &&
			employee_requestSector(sector) == OK
		)
	{
		result = OK;
	}
	return result;
}

int employee_register(Employee* list, int len, int* flag){
	int result = ERROR;
	int index;
	Employee buffer;

	if(
			employee_getFreeIndex(list, len, &index) == OK &&
			employee_generateId(list, len, index, &buffer.id) == OK &&
			employee_requestData(buffer.name, buffer.lastname, &buffer.salary, &buffer.sector) == OK &&
			addEmployee(list, len, index, buffer.id, buffer.name, buffer.lastname, buffer.salary, buffer.sector) == OK
	){
		printf("\nEmpleado cargado->");
		employee_print(list, len, index);
		*flag = 1;
		result = OK;
	}
	return result;
}

int addEmployee(Employee* list, int len, int index, int id, char* name, char* lastname, float salary, int sector){
	int result = ERROR;

	if(
			employee_setId(list, index, id) == OK &&
			employee_setName(list, index, name) == OK &&
			employee_setLastname(list, index, lastname) == OK &&
			employee_setSalary(list, index, salary) == OK &&
			employee_setSector(list, index, sector) == OK &&
			employee_setIsEmpty(list, index, EMPTY_FALSE) == OK
	){
		result = OK;
	}
	return result;
}

int employee_modify(Employee* list, int len, int index){
	int result = ERROR;
	int select;
	Employee buffer;
	if(list!=NULL && len>0 && index<len){
		do {
			menu_modify(&select);
			switch(select)
			{
				case NAME:
					if(employee_requestName(buffer.name) == OK)
						employee_setName(list, index, buffer.name);
					break;
				case LAST_NAME:
					if(employee_requestLastname(buffer.lastname) == OK)
						employee_setLastname(list, index, buffer.lastname);
					break;
				case SALARY:
					if(employee_requestSalary(&buffer.salary) == OK)
						employee_setSalary(list, index, buffer.salary);
					break;
				case SECTOR:
					if(employee_requestSector(&buffer.sector) == OK)
						employee_setSector(list, index, buffer.sector);
					break;
			}
			result = OK;
		}while(!(select==EXIT));
	}
	return result;
}

int printEmployees(Employee* list, int len){
	int result = ERROR;
	if(list!=NULL && len>0){
		printf("\nLista Empleados");
		for(int i=0; i<len; i++){
			if(employee_getIsEmpty(list, i) == EMPTY_FALSE) employee_print(list, len, i);
		}
		result = OK;
	}
	return result;
}

int employee_print(Employee* list, int len, int index){
	int result = ERROR;
	if(list!=NULL && len>0 && index<len){
		printf("\nID-> %d -- Nombre-> %s -- Apellido-> %s -- Salario-> %.2f -- Sector-> %d",
				employee_getId(list, index),
				employee_getName(list, index),
				employee_getLastname(list, index),
				employee_getSalary(list, index),
				employee_getSector(list, index)
				);
		result = OK;
	}
	return result;
}

int employee_requestId(int* id){
	int result = ERROR;
	int number;
	if(
			id!=NULL &&
			utn_getNumero(&number, "\nIngrese ID Empleado-> ", "\nERROR-> ID invalido", 1, 1000, 3) == OK
	){
		*id = number;
		result = OK;
	}
	return result;
}

int findEmployeeById(Employee* list, int len, int id, int* indice){
	int result = ERROR;
	if(list!=NULL && len>0 && id>0 && indice!=NULL){
		for(int i=0; i<len; i++){
			if(employee_getId(list, i) == id){
				*indice = i;
				result = OK;
				break;
			}
		}
	}
	return result;
}

int removeEmployee(Employee* list, int len, int index){
	int result = ERROR;

	if(list!=NULL && len>0 && index<len){
		employee_setIsEmpty(list, index, LOW_LOGIC);
		result = OK;
	}
	return result;
}

int employee_functionMultiple(int(*pFunction)(Employee*,int,int), Employee* list, int len){
	int id;
	int index;
	int result = ERROR;

	if(list!=NULL && len>0){

		if(		printEmployees(list, len) == OK &&
				employee_requestId(&id) == OK &&
				findEmployeeById(list, len, id, &index) == OK &&
				pFunction(list, len, index) == OK
		)
		{
			employee_print(list, len, index);
			result = OK;
		}
	}
	return result;
}

int sortEmployees(Employee* list, int len){
	int result = ERROR;
	int flagSwap;
	int newLen;

	if(list!=NULL && len >0){

		newLen = len-1;
		do {
			flagSwap=0;
			for(int i=0; i<newLen;i++){
				if(
						employee_getIsEmpty(list, i) == EMPTY_FALSE &&
						employee_normalizeNamesAndLastnames(list, len) == OK &&
						employee_comparitionLastnameAndSector(list, i) == OK
				){
					employee_swap(list, i, i+1);
					flagSwap=1;
				}
				newLen --;
			}
		} while (flagSwap);
		result = OK;
	}
	return result;
}

int employee_normalizeNamesAndLastnames(Employee* list, int len){

	int result = ERROR;

	if(list!=NULL && len >0){
		for(int i=0; i<len;i++){
				if(
						employee_getIsEmpty(list, i) == EMPTY_FALSE &&
						employee_setName(list, i, strlwr(employee_getName(list, i))) == OK &&
						employee_setLastname(list, i, strlwr(employee_getLastname(list, i))) == OK
				){
					result = OK;
				}
		}
	}
	return result;
}

int employee_comparitionLastnameAndSector(Employee* list, int index){

	int result = ERROR;

	if(
			strncmp(employee_getLastname(list, index), employee_getLastname(list, index+1), NAME_LEN) > 0 ||
			(strncmp(employee_getLastname(list, index), employee_getLastname(list, index+1), NAME_LEN) == 0 &&
			employee_getSector(list, index) > employee_getSector(list, index+1))
		){
		result = OK;
	}
	return result;
}

void employee_swap(Employee* list, int i, int j){

	Employee aux;
	aux = list[i];
	list[i] = list[j];
	list[j] = aux;
}

int employee_countEmployees(Employee* list, int len, int* quantity){
	int result = ERROR;
	int cont=0;

	if(list!=NULL && len>0){
		for(int i=0; i<len;i++){
			if(!employee_getIsEmpty(list, i)) cont++;
		}
		*quantity = cont;
		result = OK;
	}
	return result;
}

int employee_totalSalary(Employee* list, int len, float* totalSalary){

	int result = ERROR;
	float total = 0;

	if(list!=NULL && len>0){
		for(int i=0; i<len;i++){
			if(!employee_getIsEmpty(list, i)) total = total + employee_getSalary(list, i);
		}
		*totalSalary = total;
		result = OK;
	}
	return result;
}

int employee_promSalary(int quantity, float totalSalary, float* promSalary){

	int result = ERROR;

	if(quantity>0 && totalSalary>0 && promSalary!=NULL){
		*promSalary = totalSalary/quantity;
		result = OK;
	}
	return result;
}

int employee_exceedPromSalary(Employee* list, int len, float promSalary, int* quantityExceed){
	int result = ERROR;
	int bufferQuantity=0;

	if(list!=NULL && len>0 && promSalary>0 && quantityExceed!=NULL){
		for(int i=0; i<len; i++){
			if(!employee_getIsEmpty(list, i) && employee_getSalary(list, i)>promSalary) bufferQuantity++;
		}
		*quantityExceed = bufferQuantity;
		result = OK;
	}
	return result;
}

int employee_getInformSalary(Employee* list, int len){

	int result = ERROR;
	float totalSalary;
	int quantity;
	float promSalary = 0;
	int quantityExceed = 0;

	if(
			list!=NULL && len>0 &&
			employee_totalSalary(list, len, &totalSalary) == OK &&
			employee_countEmployees(list, len, &quantity) == OK &&
			employee_promSalary(quantity, totalSalary, &promSalary) == OK &&
			employee_exceedPromSalary(list, len, promSalary, &quantityExceed) == OK
	)
	{
		printf("\nSalarios Total -> %.2f", totalSalary);
		printf("\nSalario Promedio -> %.2f", promSalary);
		printf("\nCantidad de empleados que superan salario promedio -> %d", quantityExceed);
		result = OK;
	}
	return result;
}

int employee_getInforms(Employee* list, int len){
	int result = ERROR;
	int select;

	if(list!=NULL && len >0){

		do{
			menu_info(&select);

			switch(select){

				case INFO_ORDER:

					if(sortEmployees(list, len) == OK) printEmployees(list, len);
					break;

				case INFO_SALARY:

					if(employee_getInformSalary(list, len) == OK) printf("Informes exitoso");
					break;
			}
			result = OK;

		}while(!(select==EXIT));
	}
	return result;
}



