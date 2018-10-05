#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    char seguir='s';
    int opcion=0,aux,id, flag = 0;
    Employee personas[TAM];
    float promedio;

   initEmployees(personas,TAM);


    while(seguir=='s')
    {
        system("cls");

        opcion = menu();
        switch(opcion)
        {
            case 1:
                system("cls");

                aux = obtenerEspacioLibre(personas,TAM);
                if (aux== -1)
                {
                    printf("No hay espacio disponible");
                }
                else
                {
                    alta(personas,aux);
                }
                flag = 1;

                system("pause");
                break;
            case 2:
                if (flag == 0)
                {
                    printf("No se ingresaron empleados\n");
                }
                else
                {
                    printEmployees(personas,TAM);

                    printf("\nIngrese el ID: ");
                    scanf("%d",&id);

                    modificar (personas, TAM,id);

                }
                 system("pause");

                break;
            case 3:
                system("cls");
                if (flag == 0)
                {
                    printf("No se ingresaron empleados\n");
                }
                else
                {
                    printEmployees(personas,TAM);

                    printf("\nIngrese el ID: ");
                    scanf("%d",&id);

                    removeEmployee(personas,TAM,id);
                }

                system("pause");

                break;
            case 4:
                system("cls");
                if (flag == 0)
                {
                    printf("No se ingresaron empleados\n");
                }
                else
                {
                    printf("Ingrese el orden deseado: \n0- Descendente \n1- Ascendente\n\n");
                    scanf("%d",&aux);

                    sortEmployees(personas,TAM,aux);
                    printEmployees(personas,TAM);

                    promedio = promedioSalario(personas,TAM);
                    printf("\n\n El promedio de los salarios es: %.2f\n",promedio);

                    aux = employeeOverProm (personas,TAM,promedio);
                    printf("La cantidad de empleados que superan el promedio es: %d\n",aux);
                }
                system("pause");
                break;
            case 5:
                flag = 1;
                hardcodeo (personas);
                system("Pause");
                break;
            case 6:
                seguir = 'n';
                break;
            case 7:
                system("cls");
                printEmployees(personas,TAM);
                system("pause");
                break;
            default:
                printf("Ingrese una opcion valida <1-5>\n");
                system("Pause");
        }
    }

    return 0;
}
