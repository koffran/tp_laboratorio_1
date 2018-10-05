#include "ArrayEmployees.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int menu()
{
    int opcion;
    printf("1- Agregar empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Borrar empleado\n");
    printf("4- Mostrar empleados\n\n");
    printf("5- Hardcodeo\n");
    printf("6- Salir\n");

    scanf("%d",&opcion);
    return opcion;
}

int initEmployees (Employee* personas, int tam)
{
    int i,retorno = -1;

    if (personas !=NULL)
    {
        for (i=0; i<tam; i++)
        {
            personas[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int obtenerEspacioLibre(Employee lista[],int tam)
{
    int indice = -1,i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].isEmpty ==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(Employee* lista, int id,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id == lista[i].id && lista[i].isEmpty == 1)
        {
            indice = i;
        }
    }
    return indice;
}

void alta (Employee* lista, int i)
{
    char name [51],lastName[51];
    float salary;
    int sector, id;

    printf("ingrese el name: \n");
    fflush(stdin);
    gets(name);

    printf("ingrese el apellido: \n");
    fflush(stdin);
    gets(lastName);

    printf("Ingrese el salario: ");
    scanf("%f",&salary);

    printf("Ingrese el sector: \n1- Sector 1\n2- Sector 2\n3- Sector 3\n");
    scanf("%d",&sector);

    id = i+1;

   if (addEmployees(lista, i, id, name ,lastName , salary, sector)==0)
   {
       printf("Empleado cargado\n");
   }

}

int addEmployees(Employee* list, int indice, int id, char name[],char lastName[],float salary,int sector)
{
     int returnAux = -1;

    if(list != NULL)
    {
        list[indice].id = id;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].salary = salary;
        list[indice].sector = sector;
        list[indice].isEmpty = 1;
        returnAux = 0;
    }

    return returnAux;
}

void removeEmployee (Employee* lista, int len,int id)
{
    char rta;
    int indice;

    indice = findEmployeeById(lista,id,len);

    if (indice == -1)
    {
         printf("No se encontro el ID ingresado\n");
    }
    else
    {
        if (lista[indice].isEmpty == 1)
            {
                printf("Nombre\t Salario\t id\n %s\t %.2f\t %d\n",lista[indice].name,lista[indice].salary,lista[indice].id);
                printf("Desea eliminarlo? <S/N>\n");
                fflush(stdin);
                rta = getche();
                rta = tolower(rta);

                if ( rta == 's')
                {
                    lista[indice].isEmpty = 0;
                    printf("\nEmpleado elilminada\n\n");
                }
            }
    }
}

void printEmployee(Employee* list, int i)
{
  if (list[i].isEmpty == 1)
        {
            printf("%10s\t%10s\t%10.2f\t%10d\t\t%7d\n",list[i].lastName,list[i].name,list[i].salary,list[i].id,list[i].sector);
        }
}

void printEmployees(Employee* list, int length)
{
    int i;
    printf("Apellido\t\tNombre\t\tSalario\t\tid\t\tSector\n");
    for (i=0; i<length; i++)
    {
        printEmployee(list,i);
    }
}


int sortEmployees (Employee* lista, int tam, int order)
{
    int i,j,retorno =-1;
    Employee aux;

    for (i=0; i<tam-1; i++)
    {
        if(lista[i].isEmpty ==1)
        {
            for (j=i+1; j<tam; j++)
            {
                if(lista[j].isEmpty ==1 && order == 1)
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 && lista[i].sector > lista[j].sector)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    }
                }
                else
                {
                    if(lista[j].isEmpty ==1 && order == 0)
                {
                    if(strcmp(lista[i].lastName, lista[j].lastName)<0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    else
                    {
                        if(strcmp(lista[i].lastName, lista[j].lastName)==0 &&lista[i].sector < lista[j].sector)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                    }
                }
                }

            }
            retorno =0;
        }
    }
    return retorno;
}

float promedioSalario(Employee* list, int lenght)
{
    int i,cant = 0;
    float total = 0,retorno;
    for (i=0;i<lenght;i++)
    {
        if (list[i].isEmpty == 1)
        {
            total += list[i].salary;
            cant +=1;
        }
    }
    printf("\n\nEl total de los salarios es: $ %.2f",total);
    retorno = total / cant;
    return retorno;
}

int employeeOverProm (Employee* list, int lenght, int promedio)
{
    int i,contador=0;
    for (i=0;i<lenght;i++)
    {
        if (list[i].isEmpty == 1 && list[i].salary > promedio)
        {
            contador += 1;
        }
    }
    return contador;
}

void modificar (Employee* lista, int tam, int id)
{
    int rta;
    int indice;
    char seguir = 's';

    indice = findEmployeeById(lista,id,tam);

    if (indice == -1)
    {
         printf("No se encontro el ID ingresado\n");
    }
    else
    {
        if (lista[indice].isEmpty == 1)
            {
                while (seguir == 's')
                {
                    system("cls");
                    printEmployee(lista,indice);
                    printf("Que dato desea modificar? <\n1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n5- Salir\n");
                    scanf("%d",&rta);
                    switch (rta)
                    {
                    case 1:
                        system("cls");
                        printf("Que nombre desea asignarle?\n");
                        fflush(stdin);
                        gets(lista[indice].name);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        printf("Que apellido desea asignarle?\n");
                        fflush(stdin);
                        gets(lista[indice].lastName);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        printf("Que salario desea ingresar?\n");
                        scanf("%f", &lista[indice].salary);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        printf("Ingrese el sector: \n1- Sector 1\n2- Sector 2\n3- Sector 3\n");
                        scanf("%d", &lista[indice].sector);
                        system("pause");
                        break;
                    case 5:
                        seguir = 'n';
                        break;
                    default:
                        printf("Ingrese una opcion valida <1-5>");
                        system("pause");
                    }
                }
            }
    }
}



void hardcodeo (Employee personas[])
{
   strcpy(personas[0].name,"Juan");
   strcpy(personas[0].lastName,"Sanchez");
   personas[0].salary = 21 ;
   personas[0].isEmpty = 1;
   personas[0].id =  1;
   personas[0].sector =  1;

   strcpy(personas[1].name,"Paula");
   strcpy(personas[1].lastName,"Perez");
   personas[1].salary = 13;
   personas[1].isEmpty = 1;
   personas[1].id = 2;
   personas[1].sector =  2;

   strcpy(personas[2].name,"Pablo");
   strcpy(personas[2].lastName,"Gomez");
   personas[2].salary = 56;
   personas[2].isEmpty = 1;
   personas[2].id = 3;
   personas[2].sector =  3;

   strcpy(personas[3].name,"Micaela");
   strcpy(personas[3].lastName,"Gimenez");
   personas[3].salary = 27;
   personas[3].isEmpty = 1;
   personas[3].id =4;
   personas[3].sector =  1;

   strcpy(personas[4].name,"German");
   strcpy(personas[4].lastName,"Robled");
   personas[4].salary = 17;
   personas[4].isEmpty = 1;
   personas[4].id = 5;
   personas[4].sector =  1;

   strcpy(personas[5].name,"Esteban");
   strcpy(personas[5].lastName,"Rodriguez");
   personas[5].salary = 58;
   personas[5].isEmpty = 1;
   personas[5].id = 6;
   personas[5].sector =  2;

   strcpy(personas[6].name,"Cecilia");
   strcpy(personas[6].lastName,"Gonzalez");
   personas[6].salary = 34;
   personas[6].isEmpty = 1;
   personas[6].id = 7;
   personas[6].sector =  3;

}
