#ifndef MENU_H_
#define MENU_H_

#define ADD 1
#define MODIFY 2
#define LOW 3
#define INFO 4
#define NAME 1
#define LAST_NAME 2
#define SALARY 3
#define SECTOR 4
#define EXIT 0
#define LIST_EMPLOYEE 1
#define TOTAL_PROM_SALARY 2


/**
 * \brief 	-> menu_principal
 * \param 	-> int* select	  	-> puntero donde se guarda seleccion
 * \return 	-> void 		  	-> no retorna
 **/
void menu_main(int* select);
/**
 * \brief 	-> menu_modificarCliente
 * \param 	-> int* select	  	-> puntero donde se guarda seleccion
 * \return 	-> void 		  	-> no retorna
 **/
void menu_modify(int* select);
/**
 * \brief 	-> menu_informes
 * \param 	-> int* select	  	-> puntero donde se guarda seleccion
 * \return 	-> void 		  	-> no retorna
 **/
void menu_info(int* select);

#endif /* MENU_H_ */
