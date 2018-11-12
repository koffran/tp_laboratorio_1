#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n
     3. Alta de empleado\n
     4. Modificar datos de empleado\n
     5. Baja de empleado\n
     6. Listar empleados\n
     7. Ordenar empleados\n
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n
    10. Salir\n
*****************************************************/


int main()
{
    int option = 0;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();

    while(seguir == 's')
    {
        system("cls");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n 6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                system("cls");
                controller_loadFromText("data.csv",listaEmpleados);
                system("pause");
                break;
			case 2:
			    system("cls");
				controller_loadFromBinary("data.csv",listaEmpleados);
				system("pause");
				break;
			case 3:
			    system("cls");
				if (controller_addEmployee(listaEmpleados) == 0)
                {
                     printf("\nEmpleado cargado\n");
                }
                else
                {
                    printf("\n No se pudo cargar el empleado\n");
                }
				system("pause");
				break;
			case 4:
			    system("cls");
			    controller_editEmployee(listaEmpleados);
				system("pause");
				break;
			case 5:
			    system("cls");
			    controller_removeEmployee(listaEmpleados);
				system("pause");
				break;
			case 6:
			    system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
				break;
            case 7:
                system("cls");
                controller_sortEmployee( listaEmpleados);
                system("pause");
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv", listaEmpleados);

                system("pause");
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.csv", listaEmpleados);
                system("pause");
                break;
            case 10:
                seguir = 'n';
        }
    }
    return 0;
}
