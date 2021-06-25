#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	menu_main(&option);
        switch(option)
        {
            case READ_TXT:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case READ_BINARY:
            	controller_loadFromBinary("data.bin", listaEmpleados);
            	break;
            case ADD_EMPLOYEE:
            	controller_addEmployee(listaEmpleados);
            	break;
            case MODIFY_EMPLOYEE:
            	controller_editEmployee(listaEmpleados);
            	break;
            case LOW_EMPLOYEE:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case LIST_EMPLOYEE:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case SORT_EMPLOYEE:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case SAVE_TXT:
            	controller_saveAsText("archivoTexto.csv", listaEmpleados);
            	break;
            case SAVE_BINARY:
            	controller_saveAsBinary("archivoBinario.bin", listaEmpleados);
            	break;
        }
    }while(option != EXIT);
    return 0;
}

