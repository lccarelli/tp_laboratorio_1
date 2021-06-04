#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#define EMPLOYEE_MAX 1100
#define OK 0
#define ERROR -1
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char*sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setIdStr(Employee* this, char* id);
int employee_getIdStr(Employee* this, char* resultado);

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadasStr(Employee* this,char* resultado);

int employee_setSueldoStr(Employee* this,char* sueldo);
int employee_getSueldoStr(Employee* this,char* resultado);

#endif // employee_H_INCLUDED
