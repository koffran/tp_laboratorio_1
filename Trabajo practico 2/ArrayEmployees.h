#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
    int id;

}Employee;


/** \brief Inicializa el estado del array para futuras validaciones
 *
 * \param El array a inicializar
 * \param El tamaño del array
 * \return
 *
 */
int initEmployees (Employee*,int);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployees(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief
 *
 * \param El array en el que se carga la nueva persona
 * \param El indice
 * \return
 *
 */
void alta (Employee *, int );

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
void removeEmployee (Employee*,int, int );

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees (Employee* , int , int );

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void printEmployees (Employee *,int );



/** \brief Carga automaticamente datos en el arrayy
 *
 * \param El array
 * \param
 * \return
 *
 */
void hardcodeo (Employee []);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(Employee lista[],int);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* lista, int dni,int tam);

/** \brief Calcula el promedio
 *
 * \param list Employee*
 * \param lenght int el tamaño del array
 * \return float el promedio
 *
 */
float promedioSalario(Employee* list, int lenght);

/** \brief Muestra por pantalla un empleado de la lista
 *
 * \param list Employee*
 * \param i int el indice del empleado
 * \return void
 *
 */
void printEmployee(Employee* list, int i);

/** \brief Permite modificar datos de un empleado
 *
 * \param El array
 * \param El tamaño del array
 * \param El ID del empleado a modificar
 * \return
 *
 */
void modificar (Employee* lista, int tam, int id);

/** \brief Calcula cuantos empleados estan sobre el salario promedio
 *
 * \param La lista de empleados
 * \param El tamaño del array
 * \param el promedio
 * \return
 *
 */
int employeeOverProm (Employee* list, int lenght, int promedio);

/** \brief Imprime un menu en la pantalla
 *
 * \return int la opcion seleccionada
 *
 */
int menu();
#endif // FUNCIONES_H_INCLUDED


