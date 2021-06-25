#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Menu.h"

static int controller_compararPorNombre(void* this1, void* this2);
static int controller_lastId(LinkedList* pArrayListEmployee);
static int controller_findById(LinkedList* pArrayListEmployee, int *posicionId, int id);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    int result = ERROR;
    FILE* file = NULL;

    if(path != NULL && pArrayListEmployee != NULL){

        file = fopen(path, "r");

        if(file !=NULL) {
            if(!parser_EmployeeFromText(file, pArrayListEmployee))
            {
                printf("\nCarga exitosa.");
                result = OK;
            }
        }
    }
    return result;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int result = ERROR;
    FILE* file = NULL;

    if(path != NULL && pArrayListEmployee != NULL){

        file = fopen(path, "rb");

        if(file!=NULL){

            if(!parser_EmployeeFromBinary(file, pArrayListEmployee))
            {
                printf("\nCarga exitosa.");
                result = OK;
            }
        }
    }
    return result;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;
    int result = ERROR;
    char nombre[NAME_LEN];

    if(aux != NULL && pArrayListEmployee != NULL){
        if(
        		employee_requestNombre(nombre) == 0 &&
				employee_requestSueldo(&sueldo) == 0 &&
				employee_requestHorasTrabajadas(&horasTrabajadas) == 0
		)
        {
            employee_setNombre(aux, nombre);
            employee_setHorasTrabajadas(aux, horasTrabajadas);
            employee_setSueldo(aux, sueldo);
            id = controller_lastId(pArrayListEmployee);
            employee_setId(aux, id);

            ll_add(pArrayListEmployee, aux);
            result = OK;
            printf("\tEmpleado cargado correctamente!\n");
        } else {
        	employee_delete(aux);
        };
    }
    return result;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmployee = NULL;
    int id, posId, horas, sueldo, select;
    char nombre[NAME_LEN];
    int result = ERROR;


    if(pArrayListEmployee != NULL){

        if(
        		employee_requestId(&id) == OK &&
        		controller_findById(pArrayListEmployee, &posId, id) == OK
			){
                pAuxEmployee = ll_get(pArrayListEmployee, posId);

                if(pAuxEmployee!= NULL){

            		do {
            			menu_modify(&select);
            			switch(select)
            			{
            			case NOMBRE:
            				if (
            						employee_requestNombre(nombre) == OK &&
									employee_setNombre(pAuxEmployee,nombre) == OK
								){
            						printf("\nModificacion exitosa.");
            						result = OK;
								 }
            				break;

						case SUELDO:
							if (
									employee_requestSueldo(&sueldo)== OK &&
									employee_setSueldo(pAuxEmployee,sueldo) == OK
							){
									printf("\nModificacion exitosa");
									result = OK;
								}
							break;

						case HORAS_TRABAJADAS:
							if (
									employee_requestHorasTrabajadas(&horas) == OK &&
									employee_setHorasTrabajadas(pAuxEmployee,horas) == OK
							){
									printf("\nModificacion exitosa");
									result = OK;
								}
							break;
            			}
            			result = OK;
            		}while(!(select==EXIT));
                };
            };
    };
    return result;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result, id, posId;
    Employee* aux = NULL;

    if(pArrayListEmployee!= NULL){
        if(utn_getNumero(&id,"Ingrese un ID a borrar: ", "Error al ingresar ID. Reintente", 0, ll_len(pArrayListEmployee),2) == OK){
            if(controller_findById(pArrayListEmployee, &posId, id) == OK){
                aux = ll_pop(pArrayListEmployee, posId);
                if(aux!= NULL){
                	employee_delete(aux);
                    printf("\nEMPLEADO DADO DE BAJA.\n\n");
                    result = OK;
                };
            };
        };
    } else {result = ERROR;};
    return result;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    Employee* aux = NULL;
    char id[1000];
    char nombre[1000];
    char horas[1000];
    char sueldo[100000];

    for(int i=0; i<ll_len(pArrayListEmployee); i++){
        aux = ll_get(pArrayListEmployee, i);
        if(aux != NULL){
            if(
            		!employee_getIdStr(aux, id) &&
                    !employee_getNombre(aux, nombre) &&
                    !employee_getHorasTrabajadasStr(aux, horas)&&
                    !employee_getSueldoStr(aux, sueldo)
			){
                printf("NOMBRE : %s ID: %s HORAS: %s SUELDO: %s\n", nombre, id, horas, sueldo);
                result = OK;
            } else {result = ERROR;};
        } else {result = ERROR;};
    };
    return result;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int result;

    if(pArrayListEmployee != NULL){
        ll_sort(pArrayListEmployee, controller_compararPorNombre, 1);
        result = OK;
    } else {result = ERROR;};
    return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int result = ERROR;
    FILE* file = NULL;
    Employee * aux = NULL;
    char id[1000];
    char nombre[1000];
    char horas[1000];
    char sueldo[100000];

    if(path != NULL && pArrayListEmployee != NULL){
        file = fopen(path, "w");
        if(file != NULL){
            for(int i =0; i<ll_len(pArrayListEmployee); i++){

                aux = ll_get(pArrayListEmployee, i);
                if(
                		employee_getIdStr(aux, id) == OK &&
                        employee_getNombre(aux,nombre) == OK &&
                        employee_getHorasTrabajadasStr(aux, horas) == OK &&
                        employee_getSueldoStr(aux, sueldo) == OK
				){
                    fprintf(file, "%s, %s, %s, %s\n", id,nombre,horas,sueldo);
                    result = OK;
                } else {
                	employee_delete(aux);
                }
            }
        }
        fclose(file);
    }
    return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int result;
    FILE* file = NULL;
    Employee * pEmployee = NULL;

    if(path != NULL && pArrayListEmployee != NULL){
        file = fopen(path, "wb");
        if(file != NULL){
            for(int i =0 ; i<ll_len(pArrayListEmployee) ; i++){
                pEmployee = ll_get(pArrayListEmployee, i);
                if(pEmployee != NULL) fwrite(pEmployee, sizeof(Employee), 1, file);
            };
            result = OK;
            fclose(file);
        } else {result = ERROR;};
    } else {result = ERROR;}
    return result;
}

static int controller_lastId(LinkedList* pArrayListEmployee){
    int max = -1, len = 0, count = 0;
    Employee* aux;

    if(pArrayListEmployee != NULL){

        len = ll_len(pArrayListEmployee);

        if(len > 0){
            for(int i = 0; i < len; i++){
                aux = (Employee*)ll_get(pArrayListEmployee, i);
                if(aux != NULL){
                    if(count == 0) max = aux->id;
                    else if(aux->id > max && aux->id < EMPLOYEE_MAX) max = aux->id;
                    count++;
                };
            };
        };
        count > 0 ? max++ : (max = 1);
    };
    return max;
};

// este puede directamente devolver el puntero al employee encontrado

static int controller_findById(LinkedList* pArrayListEmployee, int *posicionId, int id){
    int result = ERROR;
	int aux;
    Employee *pEmployee = NULL;

    if(pArrayListEmployee != NULL && posicionId >= 0 && id >= 0){

        for(int i = 0; i < ll_len(pArrayListEmployee); i++){

            pEmployee = ll_get(pArrayListEmployee, i);

            if(pEmployee != NULL){
                employee_getId(pEmployee, &aux);

                if(id == aux){
                    *posicionId = i;
                    result = OK;
                }
            }
        }
    }
    return result;
};


static int controller_compararPorNombre(void* this1, void* this2){

    char auxNombreA[4096];
    char auxNombreB[4096];

    employee_getNombre((Employee*)this1, auxNombreA);
    employee_getNombre((Employee*)this2, auxNombreB);

    if(strcmp(auxNombreA, auxNombreB) > 0){
    	return 1;
    };
    if(strcmp(auxNombreA, auxNombreB) < 0){
    	return -1;
    };

    return 0;
};


