#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validaciones.h"

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;
    pEmployee = employee_new();

    if(pEmployee!=NULL)
    {
        if( employee_setNombre(pEmployee,nombreStr)==-1 ||
            employee_setId(pEmployee,idStr)==-1 ||
            employee_setHorasTrabajadas(pEmployee,horasTrabajadasStr) == -1 ||
            employee_setSueldo(pEmployee,sueldoStr) == -1)
        {
            employee_delete(pEmployee);
            pEmployee=NULL;
        }
    }
    return pEmployee;
}

int employee_delete(Employee* emp)
{
    int retorno = -1;

    if(emp != NULL)
    {
        free(emp);
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this,char* id)
{
    int retorno=-1;

    static int proximoId=-1;
    int idAuxiliar;

    if(this != NULL && validarId(id)==0)
    {
        idAuxiliar = atoi(id);

        if(idAuxiliar == 0)
        {
            proximoId++;
            this->id=proximoId;
            retorno=0;
        }
        else
        {
           if(idAuxiliar>proximoId)
            {
                proximoId = idAuxiliar;
                this->id = proximoId;
                retorno =0;
            }
        }
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
     if(this != NULL && id!= NULL)
     {
        *id=this->id;
        retorno=0;
     }
    return retorno;
}

int validarId(char* id)
{
    int i=0;
    int retorno=0;

    while(id[i] != '\0')
    {
        if(id[i] < '0' || id[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this != NULL && validarNombre(nombre)==0)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

int validarNombre(char* nombre)
{
    int i=0;
    int retorno=0;

    while(nombre[i] != '\0')
    {
         if ((nombre[i] < 'A' || nombre[i] > 'Z') && (nombre[i] < 'a' || nombre[i] > 'z'))
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
    int retorno=-1;

    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas)==0)
    {
        this->horasTrabajadas=atoi(horasTrabajadas);
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;

     if(this != NULL && horasTrabajadas!= NULL)
     {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
     }
    return retorno;
}


int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int i=0;
    int retorno=0;
    while(horasTrabajadas[i] != '\0')
    {
        if(horasTrabajadas[i] < '0' || horasTrabajadas[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,char* sueldo)
{
    int retorno=-1;

    if(this != NULL && isValidSueldo(sueldo)==0)
    {
        this->sueldo=atoi(sueldo);
        retorno=0;
    }
    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;

     if(this != NULL && sueldo!= NULL)
     {
        *sueldo=this->sueldo;
        retorno=0;
     }
    return retorno;
}


int isValidSueldo(char* sueldo)
{
    int i=0;
    int retorno=0;
    while(sueldo[i] != '\0')
    {
        if(sueldo[i] < '0' || sueldo[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_alta(LinkedList* arrayEmployee)
{
    int retorno = -1;
    char bufferNombre[1024];
    char bufferId[1024] = "0";
    int auxHorasTrabajadas;
    int auxSueldo;
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee* auxEmployee;

    if( getNombre(bufferNombre,"Ingrese el nombre del empleado: ","Ese no es un nombre")==0 &&
        getEnteroSinLimites(&auxHorasTrabajadas,10,"Ingrese las horas trabajadas del empleado: ","Ese no es un numero")==0 &&
        getEnteroSinLimites(&auxSueldo,10,"Ingrese el sueldo del empleado: ","Ese no es un numero")==0)
    {
        itoa(auxHorasTrabajadas,bufferHorasTrabajadas,10);
        itoa(auxSueldo,bufferSueldo,10);

        auxEmployee = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

        if(auxEmployee != NULL)
        {
            ll_add(arrayEmployee,auxEmployee);
            retorno=0;
        }
        else
        {
            printf("Este es NULL");
        }
    }


    return retorno;
}

int employee_modificar(LinkedList* arrayEmployee)
{
    int retorno=-1;
    int employeeId;
    int indice;
    char bufferNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployee;

    if(arrayEmployee != NULL && getEnteroSinLimites(&employeeId,10,"Ingrese el ID del empleado a modificar: ","Ese id no es valido")==0)
    {
        indice=employee_buscarPorId(arrayEmployee,employeeId);
        if(indice >=0)
        {
            auxEmployee=ll_get(arrayEmployee,indice);
            if( getNombre(bufferNombre,"Ingrese el nuevo nombre del empleado: ","Ese no es un nombre\n")==0 &&
                getEnteroSinLimites(&auxHorasTrabajadas,10,"Ingrese la nueva cantidad de horas trabajadas: ","Esas no es una hora valida")==0 &&
                getEnteroSinLimites(&auxSueldo,10,"Ingrese el nuevo sueldo: ","Ese no es un sueldo valido\n")==0)
            {
                auxEmployee->horasTrabajadas=auxHorasTrabajadas;
                auxEmployee->sueldo=auxSueldo;
                strcpy(auxEmployee->nombre,bufferNombre);
                retorno=0;
            }
        }else
        {
            printf("El Id no existe\n");
        }
    }
    return retorno;
}

int employee_borrar(LinkedList* arrayEmployee)
{
    int retorno=-1;
    int employeeId;
    int indice;
    Employee* auxEmployee;

    if(arrayEmployee != NULL && getEnteroSinLimites(&employeeId,10,"Ingrese el ID del empleado a borrar: ","Ese id no es valido")==0)
    {
        indice = employee_buscarPorId(arrayEmployee,employeeId);

        if(indice >=0)
        {
            auxEmployee=ll_get(arrayEmployee,indice);
            if(employee_delete(auxEmployee)==0)
            {
                retorno=0;
                ll_remove(arrayEmployee,indice);
            }
        }else
        {
            printf("El Id no existe\n");
        }
    }
    return retorno;
}

int employee_buscarPorId(LinkedList* pArrayEmployee, int employeeId)
{
    int retorno=-1;
    int i;
    int limite=ll_len(pArrayEmployee);
    Employee* auxEmployee;

    if(pArrayEmployee!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayEmployee,i);
            if(auxEmployee!=NULL && auxEmployee->id == employeeId)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

void employee_mostrar(LinkedList* arrayLinkedList)
{
    int i;
    int auxId;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    int limite;
    limite=ll_len(arrayLinkedList);
    Employee* auxEmployee;
    for(i=0;i<limite;i++)
    {
        auxEmployee=ll_get(arrayLinkedList,i);

        if( employee_getId(auxEmployee,&auxId)==0 &&
            employee_getNombre(auxEmployee,auxNombre)==0 &&
            employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas)==0 &&
            employee_getSueldo(auxEmployee,&auxSueldo)==0)
        {
            printf("ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d \n", auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        }

    }
}

int employee_criterioNombre(void* thisA,void* thisB)
{
    int retorno;
    char nombreA[1024];
    char nombreB[1024];
    employee_getNombre(thisA,nombreA);
    employee_getNombre(thisB,nombreB);
    if(strcmp(nombreA,nombreB)>0)
    {
        retorno=1;
    }else if(strcmp(nombreA,nombreB)<0)
    {
        retorno=-1;
    }
    return retorno;
}

int employee_guardarTexto(LinkedList* pArrayEmployee, char* path)
{
    int retorno=-1;
    int i;
    int limite;
    FILE* pFile;
    pFile=fopen(path,"w");
    limite=ll_len(pArrayEmployee);
    Employee* auxEmployee;
    if(pFile !=NULL)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            auxEmployee=ll_get(pArrayEmployee,i);
            fprintf(pFile,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        }
    }
    fclose(pFile);
    return retorno;
}

int employee_guardarBinario(LinkedList* pArrayEmployee, char* path)
{
    int retorno=-1;
    int i;
    int limite;
    FILE* pFile;
    pFile=fopen(path,"wb");
    limite=ll_len(pArrayEmployee);
    Employee* auxEmployee;
    if(pFile !=NULL)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            auxEmployee=ll_get(pArrayEmployee,i);
            fprintf(pFile,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        }
    }
    fclose(pFile);
    return retorno;
}
