#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#define SECTOR_LEN 12
#define SECTOR_CANT 4
#define ORDER_DESC 1
#define ORDER_ASC 2
#define EMPLOYEE_HARDCODE 6
#define EMPLOYEE_CANT 1000
#define NAME_LEN 51
#define ERROR -1
#define OK 0
#define VERDADERO 1
#define EXIT 0
#define INFO_ORDER 1
#define INFO_SALARY 2

struct{
	int id;
	char name[NAME_LEN];
	char lastname[NAME_LEN];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

//funciones propuestas en el TP

/**
 * \brief 	-> initEmployees 	-> inicia array
 * \param 	-> Employee* list	-> puntero a estructura
 * \param 	-> int len	  		-> limite estructura
 * \return 	-> int 		  		-> retorna OK (0) - ERROR(-1)
 **/
int initEmployees(Employee* list, int len);
/**
 * \brief 	-> addEmployee 		-> agrega empleado
 * \param 	-> Employee* list	-> puntero a estructura
 * \param 	-> int len	  		-> limite estructura
 * \param 	-> int id 			-> id
 * \param 	-> name[] char		-> nombre
 * \param 	-> lastName[] char	-> apellido
 * \param 	-> salary float		-> salario
 * \param 	-> sector int		-> sector
 * \return 	-> int 		  		-> retorna OK (0) - ERROR(-1)
 **/
int addEmployee(Employee* list, int len, int index, int id, char* name, char* lastname, float salary, int sector);
/**
 * \brief 	-> findEmployeeById -> busca posicion por id
 * \param 	-> Employee* list	-> puntero a estructura
 * \param 	-> int len	  		-> limite estructura
 * \param 	-> int id 			-> id
 * \param 	-> int* index		-> puntero donde se guarda la posicion
 * \return 	-> int 		  		-> retorna OK (0) - ERROR(-1)
 **/
int findEmployeeById(Employee* list, int len, int id, int* indice);
/**
 * \brief 	-> removeEmployee	-> baja lógica de un empleado
 * \param 	-> Employee* list	-> puntero a estructura
 * \param 	-> int len	  		-> limite estructura
 * \param 	-> int index 		-> index
 * \return 	-> int 		  		-> retorna OK (0) - ERROR(-1)
 **/
int removeEmployee(Employee* list, int len, int index);
/**
 * \brief 	-> sortEmployees	-> ordena por apellido y sector
 * \param 	-> Employee* list	-> puntero a estructura
 * \param 	-> int len	  		-> limite estructura
 * \return 	-> int 		  		-> retorna OK (0) - ERROR(-1)
 **/
int sortEmployees(Employee* list, int len);
/**
 * \brief 	-> printEmployees	-> muestra lista de empleados
 * \param 	-> Employee* list	-> puntero a estructura
 * \param 	-> int len	  		-> limite estructura
 * \return 	-> int 		  		-> retorna OK (0) - ERROR(-1)
 **/
int printEmployees(Employee* list, int len);

//****************************************************************//
//Funciones - Pedido de datos
int employee_requestId(int* id);
int employee_requestName(char* name);
int employee_requestLastname(char* lastname);
int employee_requestSalary(float* salary);
int employee_requestSector(int* sector);
int employee_requestData(char* name, char* lastname, float* salary, int* sector);
//****************************************************************//
//Funciones - Guardado de datos
int employee_setId(Employee* list, int id);
int employee_setName(Employee* list, char* name);
int employee_setLastname(Employee* list, char* lastname);
int employee_setSalary(Employee* list, float salary);
int employee_setSector(Employee* list, int sector);

//****************************************************************//
//Funciones - Articulacion
int employee_harcodeData(Employee* list, int len);
int employee_getFreeIndex(Employee* list, int len, int* index);
int employee_generateId(Employee* list, int len, int index, int* id);
int employee_print(Employee* list, int len, int index);
int employee_modify(Employee* list, int len, int index);
int employee_functionMultiple(int(*pFunction)(Employee*,int,int), Employee* list, int len);

//Funciones - Generacion de informes
int employee_countEmployees(Employee* list, int len, int* quantity);
int employee_totalSalary(Employee* list, int len, float* totalSalary);
int employee_promSalary(int quantity, float totalSalary, float* promSalary);
int employee_exceedPromSalary(Employee* list, int len, float promSalary, int* quantityExceed);
int employee_getInforms(Employee* list, int len);
#endif /* EMPLOYEE_H_ */
