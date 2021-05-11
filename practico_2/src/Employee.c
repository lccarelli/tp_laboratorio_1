#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"
#include "Menu.h"

static void employee_swap(Employee* list, int i, int j);


int initEmployees(Employee* list, int len){
	int result = ERROR;
	if(list!=NULL && len>0){
		for(int i=0; i<len; i++){
			list[i].isEmpty=1;
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
			if(list[i].isEmpty == 1){
				*index=i;
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
		(list[index].isEmpty == 1) ? (*id = index+1) : (result = ERROR);
	return result;
}

int employee_setId(Employee* list, int id){
	int result = OK;
	(list!=NULL && id>0) ? (list->id = id) : (result = ERROR);
	return result;
}

int employee_setName(Employee* list, char* name){
	int result = OK;
	if(list!=NULL && name!=NULL)
		strncpy(list->name, name, sizeof(list->name));
	else result = ERROR;
	return result;
}

int employee_setLastname(Employee* list, char* lastname){
	int result = OK;
	if(list!=NULL && lastname!=NULL)
		strncpy(list->lastname, lastname, sizeof(list->lastname));
	else result = ERROR;
	return result;
}

int employee_setSalary(Employee* list, float salary){
	int result = OK;
	(list!=NULL && salary>0) ? (list->salary = salary) : (result = ERROR);
	return result;
}

int employee_setSector(Employee* list, int sector){
	int result = OK;
	(list!=NULL && sector>0) ? (list->sector = sector) : (result = ERROR);
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
	if (utn_getString(lastname, NAME_LEN, "\nApellido_Cliente?", "\nERROR-> Apellido_Cliente?", 3) == 0)
		result = OK;
	return result;
}

int employee_requestSalary(float* salary){
	int result = ERROR;
	if (utn_getNumeroFlotante(salary, "\nSalario?", "\nERROR-> Salario?", 0, 1000000000, 3) == 0)
		result = OK;
	return result;
}

int employee_requestSector(int* sector){
	int result = ERROR;
	if (utn_getNumero(sector, "\nSector?", "\nERROR-> Sector?", 0, 5, 3) == 0)
		result = OK;
	return result;
}


int employee_requestData(char* name, char* lastname, float* salary, int* sector){
	int result = ERROR;
	if(
			employee_requestName(name) == 0 &&
			employee_requestLastname(lastname) == 0 &&
			employee_requestSalary(salary) == 0 &&
			employee_requestSector(sector) == 0
		)
	{
		result = OK;
	}
	return result;
}

int addEmployee(Employee* list, int len, int index, int id, char* name, char* lastname, float salary, int sector){
	int result = ERROR;
	Employee buffer;

	if(
			employee_setId(&buffer, id) == 0 &&
			employee_setName(&buffer, name) == 0 &&
			employee_setLastname(&buffer, lastname) == 0 &&
			employee_setSalary(&buffer, salary) == 0 &&
			employee_setSector(&buffer, sector) == 0
	){
		buffer.isEmpty = 0;
		list[index] = buffer;
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
					if(employee_requestName(buffer.name) == 0)
						strncpy(list[index].name, buffer.name, NAME_LEN);
					break;
				case LAST_NAME:
					if(employee_requestLastname(buffer.lastname) == 0)
						strncpy(list[index].lastname, buffer.lastname, NAME_LEN);
					break;
				case SALARY:
					if(employee_requestSalary(&buffer.salary) == 0)
						list[index].salary = buffer.salary;
					break;
				case SECTOR:
					if(employee_requestSector(&buffer.sector) == 0)
						list[index].sector = buffer.sector;
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
			if(list[i].isEmpty == 0) employee_print(list, len, i);
		}
		result = OK;
	}
	return result;
}

int employee_print(Employee* list, int len, int index){
	int result = ERROR;
	if(list!=NULL && len>0 && index<len){
		printf("\nID-> %d -- Nombre-> %s -- Apellido-> %s -- Salario-> %.2f -- Sector-> %d",
				list[index].id,
				list[index].name,
				list[index].lastname,
				list[index].salary,
				list[index].sector
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
			utn_getNumero(&number, "\nIngrese ID Empleado-> ", "\nERROR-> ID invalido", 1, 1000, 3) == 0
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
			if(list[i].id == id){
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
		list[index].isEmpty = -1;
		result = OK;
	}
	return result;
}

int employee_functionMultiple(int(*pFunction)(Employee*,int,int), Employee* list, int len){
	int id;
	int index;
	int result = ERROR;

	if(list!=NULL && len>0){

		if(		printEmployees(list, len) == 0 &&
				employee_requestId(&id) == 0 &&
				findEmployeeById(list, len, id, &index) == 0 &&
				pFunction(list, len, index) == 0
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
				if(!(list[i].isEmpty)){
					if(
							strncmp(list[i].lastname, list[i+1].lastname, NAME_LEN) > 0 ||
							(strncmp(list[i].lastname, list[i+1].lastname, NAME_LEN) == 0 &&
									list[i].sector > list[i+1].sector)
						){
						employee_swap(list, i, i+1);
						flagSwap=1;
					}
				}
				newLen --;
			}
		} while (flagSwap);
		result = OK;
	}
	return result;
}

static void employee_swap(Employee* list, int i, int j){

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
			if(!list[i].isEmpty) cont++;
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
			if(!list[i].isEmpty) total = total + list[i].salary;
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
			if(!list[i].isEmpty && list[i].salary>promSalary) bufferQuantity++;
		}
		*quantityExceed = bufferQuantity;
		result = OK;
	}
	return result;
}

int employee_getInforms(Employee* list, int len){
	int result = ERROR;
	int select;
	float totalSalary;
	int quantity;
	float promSalary = 0;
	int quantityExceed = 0;

	if(list!=NULL && len >0){

		do{
			menu_info(&select);

			switch(select){

				case INFO_ORDER:

					if(sortEmployees(list, len)==0) printEmployees(list, len);
					break;

				case INFO_SALARY:

					if(
							employee_totalSalary(list, len, &totalSalary) == 0 &&
							employee_countEmployees(list, len, &quantity) == 0 &&
							employee_promSalary(quantity, totalSalary, &promSalary) == 0 &&
							employee_exceedPromSalary(list, len, promSalary, &quantityExceed) == 0
					)
					{
						printf("\nSalarios Total -> %.2f", totalSalary);
						printf("\nSalario Promedio -> %.2f", promSalary);
						printf("\nCantidad de empleados que superan salario promedio -> %d", quantityExceed);
					}
					break;
			}
			result = OK;

		}while(!(select==EXIT));
	}
	return result;
}



