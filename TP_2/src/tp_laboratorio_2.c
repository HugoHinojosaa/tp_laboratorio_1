/******************************************************************************

TP2
Hugo Hinojosa
1B Turno Manana.

*******************************************************************************/
#include "ArrayPassenger.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int main()
{
	setbuf(stdout, NULL);
    int opcion=0;
    int id=1;
    int validacion;
    int order;
    int opcion3;
    int index;
    int len=2000;
    Passenger list[len];
    int contadorId=1;
    int r;
     char name[50];char lastName[50];float price;int typePassenger; char flycode[50];int statusFlight;
     r=initPassengers( list, len);
	do
	{
		printf("Seleccione que opcion desea continuar:\n1)Altas. \n2)Modificar. \n3)Baja. \n4)Informar. \n5)Salir.\n\n");
        scanf("%d", &opcion);
		switch(opcion)
		{
			case 1://alta
			do
			{
			  printf("Ingrese su nombre: \n");
                scanf("%s", &name);
                validacion=validarNombre(name);
			}while(validacion==0);

			do
			{
			    printf("Ingrese su apellido: \n");
                scanf("%s", &lastName);
                validacion = validarApellido(lastName);
			}while(validacion==0);

             printf("Ingrese el precio del vuelo: \n");
                scanf("%f", &price);

                printf("Ingrese el codigo de vuelo: \n");
                scanf("%s", &flycode);
                printf("Ingrese el tipo de pasajero: \n");
                scanf("%d", &typePassenger);
                while(typePassenger<0)
                {
                    printf("Error, Reingrese tipo de pasajero: \n");
                    scanf("%d", &typePassenger);
                }
                printf("Ingrese el estado del vuelo: \n");
                scanf("%d", &statusFlight);
                while(statusFlight<0)
                {
                    printf("Error, Reingrese estado del vuelo: \n");
                    scanf("%d", &statusFlight);
                }
                r = addPassenger(list, len, id, name, lastName, price, typePassenger, flycode, statusFlight);
                if(r !=-1)
                {
                    contadorId++;
                }
                else
                {
                    printf("\n\n****Error la lista de pasajeros esta llena***\n\n");
                }
			break;
			case 2://modificar
				printf("Ingrese su id: \n");
                scanf("%d", &id);
                index = findPassengerById(list,len, id);
                if(index !=-1)
                {
                    Modificar(list[index]);
                }
                else
                {
                    printf("\nError, este id no existe\n");
                }
			break;
			case 3://baja
				printf("Ingrese su id: \n");
                scanf("%d", &id);
                if(removePassenger(list, len, id) !=0)
                {
                    printf("\nError, este id no existe\n");
                }
                else
                {
                    printf("\n**Su id fue dado de baja**\n\n");
                }
			break;
			case 4://informar
				r = printPassenger(list, len);
				printf("Ingrese que quiere mostrar: \n1)Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero. \n2)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. \n3)Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n");
				scanf("%d", &opcion3);
				switch(opcion3)
				{
				    case 1:
				        printf("Como quiere que los muestre, \n0)Descendente \n1)Ascendente");
				        scanf("%d", &order);
				        r= sortPassengers(list,len,order);
				    break;
				    case 2:
				        calcularTotal(list,len);
				    break;
				    case 3:
				        printf("Como quiere que los muestre, \n0)Descendente \n1)Ascendente");
				        scanf("%d", &order);
				        r= sortPassengersByCode(list,len,order);
				    break;
				    default:
				    printf("\n\n***Seleccione una de las 3 opciones.***\n\n");
				    break;

				}
		    break;
            case 5:
                printf("\n\n***Programa Finalizado**** \n\n");
            break;
			default:
				printf("\n\n **Ingrese una de las opciones** \n\n");
			break;
		}
	}while(opcion!=5);

	return 0;
}
