#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    FILE* pFile;
    pFile=fopen(path,"r");

    if(pFile != NULL && parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
    {
       printf("DATOS CARGADOS\n");
       retorno=0;
    }

    fclose(pFile);
    return retorno;
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
	int retorno=-1;

    FILE* pFile;
    pFile=fopen(path,"rb");

    if(pFile != NULL && parser_EmployeeFromBinary(pFile,pArrayListEmployee)==0)
    {
       printf("DATOS CARGADOS\n");
       retorno=0;
    }

    fclose(pFile);
    return retorno;
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
    int retorno=-1;
    if(employee_alta(pArrayListEmployee)==0)
    {
        retorno=0;
    }
    return retorno;
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
    employee_mostrar( pArrayListEmployee);
    employee_modificar( pArrayListEmployee);
    return 1;
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
    employee_mostrar( pArrayListEmployee);
    employee_borrar(pArrayListEmployee);
    return 1;
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
    employee_mostrar( pArrayListEmployee);
    return 1;
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
    LinkedList* clon = ll_clone(pArrayListEmployee);

    ll_sort(pArrayListEmployee,employee_criterioNombre,1);

    /*if(clon !=NULL)
    {
        pArrayListEmployee = clon;
    }*/
    return 1;
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
    int retorno=-1;
    if(employee_guardarTexto(pArrayListEmployee,path)==0)
    {
        printf("||Los datos se guardaron en el archivo de texto||\n");
        retorno=0;
    }
    return retorno;
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
    int retorno=-1;
    if(employee_guardarBinario(pArrayListEmployee,path)==0)
    {
        printf("||Los datos se guardaron en el archivo de texto||\n");
        retorno=0;
    }
    return retorno;
}

