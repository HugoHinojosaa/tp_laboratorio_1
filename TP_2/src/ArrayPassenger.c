#include "ArrayPassenger.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int initPassengers(Passenger list[], int len)
{
    for(int i=0;i<len;i++)
    {
            list[i].isEmpty=1;
    }
    return 0;
}
int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            strcpy(list[i].name, name);
            strcpy(list[i].lastname, lastName);
            list[i].price=price;
            strcpy(list[i].flyCode,flycode);
            list[i].typePassenger=typePassenger;
            list[i].statusFlight=statusFlight;
            list[i].isEmpty=0;
            list[i].id=id;
            return 0;
        }
    }
    return -1;


return -1;
}

void Modificar(Passenger auxiliarPasajero)
{
    int validacion;
    int opcion2;
    printf("Seleccione que desea modificar: \n1)Nombre. \n2)Apellido. \n3)Precio. \n4)Tipo de pasajero. \n5)Codigo de vuelo. \n6)Salir.");
    scanf("%d", &opcion2);
        do
        {
            switch(opcion2)
            {
                case 1:

			    printf("Ingrese su nombre: \n");
			    fflush(stdin);
                scanf("%s", &auxiliarPasajero.name);

                break;

                case 2:
                    printf("Ingrese el apellido: \n");
                    fflush(stdin);
	                gets(auxiliarPasajero.lastname);
                break;

                case 3:
                    printf("Ingrese el precio del vuelo: \n");
                    scanf("%f", &auxiliarPasajero.price);
                break;

                case 4:
                    printf("Ingrese el tipo de pasajero: \n");
                    scanf("%d", &auxiliarPasajero.typePassenger);
                break;

                case 5:
                    printf("Ingrese el codigo de vuelo: \n");
                    scanf("%s", &auxiliarPasajero.flyCode);
                break;

                default:
                    printf("\n\n**Eligio la opcion salir.**\n\n");
                break;
            }

        }while(opcion2 !=6);
}
int findPassengerById(Passenger list[], int len,int id)
{
    for(int i=0; i<len;i++)
        {
            if(list[i].id==id)
            {
             return i;
            }
        }
return -1;
}

int removePassenger(Passenger list[], int len, int id)
{
  for(int i=0; i<len;i++)
        {
            if(list[i].id==id)
            {
             list[i].isEmpty=1;
             return 0;
            }
        }
return -1;
}

int sortPassengers(Passenger list[], int len, int order)
{
    Passenger auxiliar;
	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j<len; j++)
		{
            if(list[i].isEmpty==0 && list[j].isEmpty==0){
                if(strcmp(list[i].lastname,list[j].lastname)>0)
                {
                    auxiliar = list[i];
                    list[i] = list[j];
                    list[j] = auxiliar;
                }
                else
                {
                    if(list[i].lastname == list[j].lastname)
                    {
                    if(order==0)
                        {
                            if(list[i].typePassenger < list[j].typePassenger)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                        else
                        {
                            if(list[i].typePassenger > list[j].typePassenger)
                            {
                                auxiliar = list[j];
                                list[j] = list[i];
                                list[i] = auxiliar;
                            }
                        }
                    }
                }
            }

		}
	}
return 0;
}

int printPassenger(Passenger list[], int len)
{
    printf("   ID        Nombre      Apellido    Precio    Codigo de vuelo   Tipo de vuelo    Estado\n\n");
    for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty == 0){
            printf("|%4d|   |%10s| |%10s| |%4.2f|   |%10s|        |%5d|        |%5d| \n", list[i].id,list[i].name, list[i].lastname, list[i].price, list[i].flyCode, list[i].typePassenger, list[i].statusFlight);
        }
	}
return 0;
}

int sortPassengersByCode(Passenger list[], int len, int order)
{
 Passenger auxiliar;
	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j<len; j++)
		{
            if(list[i].isEmpty==0 && list[j].isEmpty==0){
                if(strcmp(list[i].flyCode,list[j].flyCode)>0)
                {
                    auxiliar = list[i];
                    list[i] = list[j];
                    list[j] = auxiliar;
                }
                else
                {
                    if(list[i].flyCode == list[j].flyCode)
                    {
                    if(order==0)
                        {
                            if(list[i].statusFlight < list[j].statusFlight){
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                        else{
                            if(list[i].statusFlight > list[j].statusFlight){
                                auxiliar = list[j];
                                list[j] = list[i];
                                list[i] = auxiliar;
                            }
                        }
                    }
                }
            }

		}
	}
return 0;
}

void calcularTotal(Passenger list[], int len)
{//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
    float promedio=0;
    float total=0;
    float suma=0;
    int superaPromedio=0;
    int contador=0;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty == 0)
        {
          contador++;
          suma= suma+list[i].price;
        }
    }
    promedio=suma/contador;
    total=suma;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty == 0)
        {
          if(list[i].price>promedio)
          {
              superaPromedio++;
          }
        }
    }
    printf("El total de los pasajes es de %4.2f. \n El promedio de los pasajes es de %4.2f. \n La cantidad de pasajeros que superan el precio promedio es de %d\n", total, promedio, superaPromedio);
}

int validarNombre(char name[])
{
    for(int i=0;i<strlen(name);i++)
    {
        if(!(name[i]>=65 && name[i]<=90 || name[i]>=97 && name[i]<=122))
        {
            printf("Error ");
            return 0;
        }
    }
    return 1;
}
int validarApellido(char lastName[])
{
    for(int i=0;i<strlen(lastName);i++)
    {
        if(!(lastName[i]>=65 && lastName[i]<=90 || lastName[i]>=97 && lastName[i]<=122))
        {
            printf("Error ");
            return 0;
        }
    }
    return 1;
}





