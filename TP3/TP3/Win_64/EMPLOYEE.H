#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete(Employee*);

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_criterioNombre(void* thisA,void* thisB);
int employee_guardarTexto(LinkedList* pArrayEmployee, char* path);
int employee_guardarBinario(LinkedList* pArrayEmployee, char* path);

int validarId(char* id);
int validarNombre(char* nombre);
int isValidHorasTrabajadas(char* horasTrabajadas);
int isValidSueldo(char* sueldo);
int employee_buscarPorId(LinkedList* pArrayEmployee, int employeeId);
int employee_alta(LinkedList* arrayEmployee);

int employee_borrar(LinkedList* arrayEmployee);
int employee_modificar(LinkedList* arrayEmployee);

void employee_mostrar(LinkedList* arrayLinkedList);

#endif // employee_H_INCLUDED
