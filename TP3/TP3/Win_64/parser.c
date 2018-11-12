#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee* auxEmployee;
    int flag=0;

    while(!feof(pFile))
    {
        if(flag)
        {
            fscanf(pFile,"%s",bufferId);
            flag=0;
        }
        else
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo)==4)
            {
                auxEmployee = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                if(auxEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,auxEmployee);
                    retorno=0;
                }
            }
            else
            {
                break;
            }
        }

    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno = -1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee* auxEmployee;
    int flag=0;

    while(!feof(pFile))
    {
        if(flag)
        {
            fscanf(pFile,"%s",bufferId);
            flag=0;
        }
        else
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo)==4)
            {
                auxEmployee = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                if(auxEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,auxEmployee);
                    retorno=0;
                }
            }
            else
            {
                break;
            }
        }

    }
    return retorno;

    return 1;
}
