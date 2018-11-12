
#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/**
    menu: Muestra un menu de opciones 
    @param numero1: El primer numero ingresado
    @param numero2: El segundo numero  ingresado
    @return : retorna la opcion seleccionada
*/
int menu(float numero1,float numero2);

/**
    getFloat: pide un numero con coma
    @param pNum: puntero a numero
    @param reint: cantidad de reintentos
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @return return 0 OK, -1 error.
*/
int getFloat(float* pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
/**
    getEntero: pide un numero entero
    @param pNum: puntero a numero
    @param reint: cantidad de reintentos
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @param maximo: el numero maximo
    @param minimo: el numero minimo
    @return return 0 OK, -1 error.
*/
int getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);

/**
    suma: realiza una suma entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la suma del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int suma(float *pResultado,float numero1, float numero2);
/**
    resta: realiza una resta entre 2 numeros flotantes
    @param numero1: guarda el numero 1 ingresado
    @param numero2: guarda el numero 2 ingresado
    @param *pResultado: guarda la resta del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int resta(float *pResultado,float numero1, float numero2);
/**
    multiplicacion: realiza una multiplicacion entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la multiplicacion del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int multiplicacion(float *pResultado,float numero1, float numero2);
/**
    utn_division: realiza una division entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la division del numero 1 y 2
    @return return 0 OK, -1 error.
*/

int division(float *pResultado,float numero1, float numero2);
/**
    factoreo: realiza el factoreo de un numero utilizando un for para ir multiplicandolo
    @param numero: guarda el numero recibido
    @return return devuelve la respuesta del numero factoreado
*/
int factoreo(float  numero);
/**
    texto: recibe una variable para mostrar y un mensaje
    @param resultado: numero con coma
    @param mensaje: que se debe mostrar con printf
*/
void texto(float resultado, char* msg);
/**
    getNombre:recibe una cadera de caracteres con un mensaje y un mensaje de error para pedirle al usuario que ingrese un nombre
    @param *pNombre: guarda el Array o cadena de caracteres recibida
    @param msg: mensaje a mostrar antes de ingresar el nombre
    @param msgError: mensaje a mostrar si se ingresa un dato no deseado
*/
int getNombre(char* pNombre,char* msg,char* msgError);

/**
	getEntero: pide un numero entero y utiliza getInt para validarlo pero sin maximo y minimo
    @param pNum: puntero a numero
    @param reint: cantidad de reintentos
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @param maximo: el numero maximo
    @param minimo: el numero minimo
    @return return 0 OK, -1 error.
*/

int getEnteroSinLimites(int* pNum,int reint,char* msg,char* msgError);
/**
    getCuit:recibe una cadena de caracteres con un mensaje y un mensaje de error para pedirle al usuario que ingrese un cuit
    @param *pNombre: guarda el Array o cadena de caracteres recibida
    @param msg: mensaje a mostrar antes de ingresar el cuit
    @param msgError: mensaje a mostrar si se ingresa un dato no deseado
*/

int getCUIT(char* pCuit,char* msg,char* msgError);


#endif // VALIDACIONES_H_INCLUDED
