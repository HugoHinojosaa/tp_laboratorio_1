/*
 * Hugo Hinojosa
 * Biblioteca.h
 *se agrega la cabecera de las funciones/ los prototipos
 *
 *
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void menu();
double submenu(char opcion);
/*
**brief funcion que nos permite hacer un submenu del menu, dentro de ella, guardamos y validamos los datos que ingrese el usuario. .
**param char opcion, guarda la opcion que ingresa el usuario.
**return el dato que se ingresa en cada opcion.
*/
void    mostrar(float kilometro,double  latam ,double  aerolineas,double debitoLatam,double  debitoAerolineas,double creditoLatam,double creditoAerolineas,double btcLatam,double btcAerolineas,double preciounilatam,double preciouniAerolineas );
/*
 * brief funcion que permite mostrar todos los datos que se fueron ingresando.
 * param float km...guarda los kilometros y los precios que ingreso el usuario, ya sea latam o aerolineas.
 */
double debito(float precio);
/*
 * brief funcion que permite guardar  el precio con descuento con debito, dentro de ella, le aplicamos la cuenta correspondiente para hacer el descuento.
 * param float precio guarda el precio ingresado.
 * return el precio con 10% de  descuento.
 */
double credito(double precio);
/*
 * brief funcion que permite guardar el precio con descuento con debito, dentro de ella, le aplico la cuenta  correspondiente al descuento.
 * param float precio guarda el precio ingresado.
 * return el precio con 25% de  descuento.
 */
double bitcoin(double precio);
/*
 * brief funcion que permite guardar el precio del bitcoin, dentro de ella, hacemos la cuenta correspondiente para saber el descuento.
 * param float precio guarda el precio ingresado.
 * return precio en bitcoin con descuento.
 */
void mostrarDiferencia(double Latam, double Aerolineas);
/*
 * brief funcion que permite mostrar la diferencia de precio entre latam y aerolineas y/o viceversa.
 * param float latam, aerolineas, nos permite guardar el precio correspondiente a cada opcion, para despues hacer la diferencia.
 */

double  mostrarPrecio(double precio, float kilometro);
/*
 * brief funcion que permite mostrar el precio, dentro de ella hacemos la cuenta que corresponde.
 * param float precio, kilometro nos permite guardar los kilometros y precios.
 * return el precio con la cuenta correspondiente.
 */


#endif /* BIBLIOTECA_H_ */
