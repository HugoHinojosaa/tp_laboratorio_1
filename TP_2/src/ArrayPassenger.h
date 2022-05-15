
#define BIBLIOTECA_H_
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct
{
    int id;
    char name[50];
    char lastname[50];
    float price;
    char flyCode[50];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}Passenger;
/*
Estructura llamada Passenger donde

*/
int validarApellido(char lastName[]);
/* brief funcion para poder ver si la cadena esta vacia o es un numero.
 * param char lastname[] el for recorre todo el tamano del apellido y si no hay ninguna letra, ya sea minuscula o mayuscula, en numero ascii, vuelve a pedir el apellido
 * retorna 0
 */
int validarNombre(char name[]);
/* brief funcion que se encarga de validar nombre, se escarga de saber si la cadena recibida esta vacia o es un numero.
 * param char name[] el for recorre el tamano del nombre, si la cadena enviada esta vacia y no contiene letras, minusculas y mayusculas, en numero ascii, vuelve a pedir nombre.
 * retorna 0;
 */
int initPassengers(Passenger list[], int len);
/*brief funcion para indicar si todas las posiciones del array estan vacias, pone isEmpty en True=1;
 * param passenger list[], int len, el for recorre todos los pasajeros y se encarga de saber si hay un espacio vacio u ocupado.
 * retorna 0
 */
int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight);//POR VALOR
/*brief funcion para agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer posición libre.
 * param passenger list[]/int len/int id/char name[],char name[]/float price,int typePassenger/char flycode[],int statusFlight.
 * el for recorre toda la lista para saber si esta vacia, se llenan con todos los datos pedidos y la posicion del array se torna a Ocupado=0.
 * retorna -1
 */
void Modificar(Passenger list);//POR REFERENCIA
/*brief funcion que permite la entrada a la opcion de modificar(2) dentro de la funcion, se hace un switch para que el usuario elija lo que desee modificar.
 * param passenger list, manda toda la lista de lo que el usuario fue ingresando.
 * no retorna nada porque es una funcion void.
 */
int findPassengerById(Passenger list[], int len,int id);
/*brief funcion que permite la busqueda de un pasajero recibiendo como parámetro de búsqueda su Id.
 * param list[]/int len/id. recibe los datos de la lista, el tamano y el id.
 * el for recorre toda la lista y busca el pasajero por el id.
 * retorna -1
 */
int removePassenger(Passenger list[], int len, int id);
/*brief funcion que se encarga de eliminar  un pasajero recibiendo como parámetro su Id.
 * param list[]/int len/int, el for se encarga de recorrer toda la lista de pasajeros, el if se encarga de buscar el id y luego indicar que el lugar del array este libre/vacio=1
 * retorna -1
 */
int sortPassengers(Passenger list[], int len, int order);
/*brief funcion que ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
 * param list[],int len,int order. Recibe toda la lista llena y el tamano, la opcion order es para que el usuario elija si quiere mostrar la lista de manera ascendente o descendente.
 * retorna 0
 */
int printPassenger(Passenger list[], int len);
/*brief funcion que muestra el array de pasajeros de forma encolumnada.
 * param list[], int len. Se encarga de printear toda la lista llena con los datos.
 * return 0
 */
int sortPassengersByCode(Passenger list[], int len, int order);
/*brief funcion para poder ordenar el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o
descendente.
 * param list[],int len,int order. Recibe la lista y el tamano del array de los pasajeros, el parametro order indica la opcion que el usuario elige, ascendente o descendente.
 */
