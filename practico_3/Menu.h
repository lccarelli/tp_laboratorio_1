#ifndef MENU_H_
#define MENU_H_

#define READ_TXT 1
#define READ_BINARY 2
#define ADD_EMPLOYEE 3
#define MODIFY_EMPLOYEE 4
#define LOW_EMPLOYEE 5
#define LIST_EMPLOYEE 6
#define SORT_EMPLOYEE 7
#define SAVE_TXT 8
#define SAVE_BINARY 9
#define EXIT 0
#define NOMBRE 1
#define SUELDO 2
#define HORAS_TRABAJADAS 3
/**
 * \brief 	-> menu_principal
 * \param 	-> int* select	  	-> puntero donde se guarda seleccion
 * \return 	-> void 		  	-> no retorna
 **/
void menu_main(int* select);
void menu_modify(int* select);

#endif /* MENU_H_ */
