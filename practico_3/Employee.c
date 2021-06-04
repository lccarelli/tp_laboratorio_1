#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"
#include "LinkedList.h"


Employee* employee_new(){
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* pEmployee = employee_new();
    Employee* result = NULL;

    if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
        if(
        		!employee_setIdStr(pEmployee, idStr) &&
                !employee_setNombre(pEmployee, nombreStr) &&
                !employee_setHorasTrabajadasStr(pEmployee, horasTrabajadasStr) &&
                !employee_setSueldoStr(pEmployee, sueldoStr)
		){
            result = pEmployee;
        } else {
            employee_delete(pEmployee);
        };
    };
    return result;
}

void employee_delete(Employee* this){

    if(this != NULL)
    	return free(this);
};

int employee_setId(Employee* this, int id){
    int result;
    if(this != NULL && id >= 0){
        this->id = id;
        result = OK;
    } else {result = ERROR;};
    return result;
};


int employee_getId(Employee* this, int* resultado){
    int result;
    if(this != NULL && resultado != NULL){
        *resultado = this->id;
        result = OK;
    } else {result = ERROR;};
    return result;
};

int employee_setNombre(Employee* this, char* nombre){
    int result;
    if(this != NULL && nombre != NULL){
        strcpy(this->nombre,nombre);
        result = OK;
    } else { result = ERROR;};
    return result;
};

int employee_getNombre(Employee* this, char* resultado){
    int result;
    if(this != NULL && resultado != NULL){
        strcpy(resultado,this->nombre);
        result = OK;
    } else {result = ERROR;};
    return result;
};

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int result;
    if(this != NULL && horasTrabajadas >= 0){
        this->horasTrabajadas = horasTrabajadas;
        result = OK;
    } else {result = ERROR;};
    return result;
};

int employee_getHorasTrabajadas(Employee* this,int* resultado){
    int result;
    if(this != NULL && resultado != NULL){
        *resultado = this->horasTrabajadas;
        result = OK;
    } else {result = ERROR;};
    return result;
};


int employee_setSueldo(Employee* this,int sueldo){
    int result;
    if(this != NULL && sueldo >= 0){
        this->sueldo = sueldo;
        result = OK;
    } else {result = ERROR;};
    return result;
};


int employee_getSueldo(Employee* this,int* resultado){
    int result;
    if(this != NULL && resultado != NULL){
        *resultado = this->sueldo;
        result = OK;
    } else {result = ERROR;};
    return result;
};

int employee_setIdStr(Employee* this, char* id){
    int result;
    this != NULL && id != NULL && !validarNumero(id) ?
    		(result = employee_setId(this,atoi(id))) :
			(result = ERROR);
    return result;
};

int employee_getIdStr(Employee* this, char* resultado){
    int result;
    int bufferInt;
    if(this != NULL && resultado != NULL){
        employee_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        result = OK;
    } else {result = ERROR;};
    return result;
};


int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas){
    int result;
    this != NULL && horasTrabajadas != NULL && !validarNumero(horasTrabajadas) ?
    		(result = employee_setHorasTrabajadas(this,atoi(horasTrabajadas))) :
			(result = ERROR);
    return result;
};

int employee_getHorasTrabajadasStr(Employee* this,char* resultado){
    int result;
    int bufferInt;
    if(this != NULL && resultado != NULL){
        employee_getHorasTrabajadas(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        result = OK;
    } else {result = ERROR;};
    return result;
};

int employee_setSueldoStr(Employee* this,char* sueldo){
    int result;
    this != NULL && sueldo != NULL && !validarNumero(sueldo) ?
    		(result = employee_setSueldo(this,atoi(sueldo))) :
			(result = ERROR);
    return result;
};


int employee_getSueldoStr(Employee* this,char* resultado){
    int result;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL){
        employee_getSueldo(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        result = OK;
    } else {result = ERROR;};
    return result;
};



