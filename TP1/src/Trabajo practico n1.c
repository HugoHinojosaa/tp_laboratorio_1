/*************************************************************************
Hugo Hinojosa
 *@brief funcion de/para....
 *@param
 *@return
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void menu();
float submenu(char opcion);
void    mostrar(float kilometro,double  latam ,double  aerolineas,double debitoLatam,double  debitoAerolineas,double creditoLatam,double creditoAerolineas,double btcLatam,double btcAerolineas,double preciounilatam,double preciouniAerolineas );
double debito(double precio);
double credito(double precio);
double bitcoin(double precio);
void mostrarDiferencia(double Latam, double Aerolineas);
double  mostrarPrecio(double precio, float kilometro);

int main()
{

    menu();

    return 0;

}
void menu()
{
    float kilometro=0;
    double latam=0;
    double aerolineas=0;
    int operacion;
    int contador=0;
    char eleccion;
    double debitoLatam;
    double creditoLatam;
    double debitoAerolineas;
    double creditoAerolineas;
    double btcLatam;
    double btcAerolineas;
    char opcionDos;
    double preciouniLatam;
    double preciouniAerolineas;



    while(contador==0)
    {
    	printf("1. Ingresar Kilometros:  (km =%.2f)\n",kilometro);
    	printf("2. Ingresar Precio de Vuelos: (Aerolineas=%.2f. Latam=%.2f)\n", aerolineas, latam);
    	printf("3. Calcular todos los costos\n");
    	printf("4.Informar resultados\n");
    	printf("5. Carga Forzada de datos\n");
    	printf("6. Salir\n");
    	scanf(" %d", &operacion);

    	switch(operacion)
    	{
    		case 1:
    			kilometro=submenu('x');
    			break;
    		case 2:
    			printf("Elija que precio quiere cargar, z para latam , y para aerolineas: ");
    			scanf(" %c", &eleccion);
    			while(eleccion != 'z' && eleccion != 'y')
    			{
    				printf("Por favor, ingrese la letra valida: ");
    				scanf(" %c", &eleccion);
    			}
    			if(eleccion =='z')
    			{
    				latam=submenu('z');
    			}
    			else
    			{
    				aerolineas=submenu('y');
    			}


    			break;
    		case 3:
    		    if(kilometro ==0)
    		    {
    		      printf("\n\nLos kilometros no fueron ingresados, porfavor ingreselos.\n\n");
    				break;
    		    }
    		    else
    		    {
    		      if(aerolineas ==0 || latam==0)
    			{
    		   		printf("\n\nLos precios de los vuelos no fueron ingresados, porfavor ingreselos.\n\n");
    				break;
    			}
    			else
    			{
    				printf("a) Tarjeta de débito (descuento 10)\n b) Tarjeta de crédito (interés 25)\n c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n d) Mostrar precio por km (precio unitario)\ne) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
    				scanf(" %c", &opcionDos);
    				while(opcionDos !='a' && opcionDos != 'b' && opcionDos != 'c' && opcionDos !='d' && opcionDos !='e')
    				{
    					//limpiar consola
    					printf("Error, Ingrese una opcion valida, \n a) Tarjeta de débito (descuento 10)\n b) Tarjeta de crédito (interés 25)\n c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n d) Mostrar precio por km (precio unitario)\ne) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
    					scanf(" %c", &opcionDos);
    				}
    				switch(opcionDos)
    				{
    				case 'a':
    					debitoLatam= debito(latam);
    					debitoAerolineas=debito(aerolineas);
    					printf("Debito calculado perfectamente.\n\n");

    					break;
    				case 'b':
    					creditoLatam= credito(latam);
    					creditoAerolineas=credito(aerolineas);
    					printf("Credito calculado perfectamente.\n\n");

    					break;
    				case 'c':
    					btcLatam=bitcoin(latam);
    					btcAerolineas=bitcoin(aerolineas);
    					printf("Descuento bitcoin calculado perfectamente.\n\n");

    					break;
    				case 'd':
    					preciouniLatam = mostrarPrecio(latam, kilometro);
    					preciouniAerolineas=mostrarPrecio(aerolineas, kilometro);
    					printf("Precio unitario calculado perfectamente.\n\n");
    					printf("precio unitario Aerolineas: $ %.2f\n", preciouniAerolineas);
    					printf("precio unitario Latam: $ %.2f\n\n", preciouniLatam);
    					break;
    				case 'e':
    					mostrarDiferencia( latam, aerolineas);
    					break;
    				}
    			}
    			break;
    		    }

    		case 4:
    		if(kilometro==0)
    		{
    		      printf("\n\nLos kilometros no fueron ingresados, porfavor ingreselos.\n\n");
    				break;
    		}
    		else
    		{
    		  	mostrar(kilometro, latam , aerolineas, debitoLatam, debitoAerolineas, creditoLatam,creditoAerolineas,btcLatam,btcAerolineas,preciouniLatam,preciouniAerolineas);

    		}

    			break;
    		case 5:
    			kilometro= 7090;
    			latam= 159339;
    			aerolineas= 162965;
    			debitoLatam= debito(latam);
    			debitoAerolineas=debito(aerolineas);
    			creditoLatam= credito(latam);
    			creditoAerolineas=credito(aerolineas);
    			btcLatam=bitcoin(latam);
    			btcAerolineas=bitcoin(aerolineas);
    			preciouniLatam = mostrarPrecio(latam, kilometro);
    			preciouniAerolineas=mostrarPrecio(aerolineas, kilometro);
    			mostrar(kilometro, latam , aerolineas, debitoLatam, debitoAerolineas, creditoLatam,creditoAerolineas,btcLatam,btcAerolineas,preciouniLatam,preciouniAerolineas);

    			break;
    		case 6:
    			contador=1;
    			break;
    		default:
    			printf("Error, seleccione una opcion del 1 al 6\n\n");

    			break;
    	}
    }






}
float submenu(char opcion)
{
	float dato;
	switch(opcion)
	{
	case 'x':
		printf("Ingrese kilometros: ");
		scanf("%f", &dato);
		while( dato <0 )
	    {
		 printf ("Error, Ingrese un numero de kilometros de vuelo valido: ");
		 scanf("%f", &dato);
		}
		return dato;
		break;
	case 'y':
		printf("Ingrese precio del vuelo en Aerolineas: ");
		scanf("%f", &dato);
		while( dato <0 )
		{
		 printf ("Error, Ingrese un precio de vuelo valido: ");
		 scanf("%f", &dato);
		}
		return dato;
		break;
	case 'z':
		printf("Ingrese precio del vuelo en Latam: ");
		scanf("%f", &dato);
		while(dato <0 )
	    {
		  printf ("Error, Ingrese un precio de vuelo valido: ");
	   	  scanf("%f", &dato);
		}
		return dato;
		break;
	}
}
double debito(double precio)
{
	double debito;
	debito=precio - precio*10/100;
	return debito;
}
double credito(double precio)
{
	double credito;
	credito= precio-precio*25/100;
	return credito;
}
double bitcoin(double precio)
{

    double bitcoin=4606954.55;
	double descuentoBTC;
	descuentoBTC= precio*1/bitcoin;
	return descuentoBTC;
}
double mostrarPrecio(double precio, float kilometro)
{
	double mostrarPrecio;
	mostrarPrecio= precio/kilometro;
	return mostrarPrecio;
}
void mostrarDiferencia(double Latam, double Aerolineas)
{
	double diferencia;
	if (Latam >Aerolineas)
	{
		diferencia = Latam - Aerolineas;
		printf("La diferencia es de %.2f\n\n", diferencia);
	}
	else
	{
		diferencia= Aerolineas - Latam;
		printf("La diferencia es: $ %.2f\n\n", diferencia);
	}
}
void    mostrar(float kilometro,double latam ,double aerolineas,double debitoLatam,double  debitoAerolineas,double creditoLatam,double creditoAerolineas,double btcLatam,double btcAerolineas,double preciouniLatam,double preciouniAerolineas )
{
    printf("------------------------------------------\n\n");
	printf("KMS Ingresados: %.0f km \n\n", kilometro);
	printf("Precio Aerolineas: $ %.2f \n", aerolineas);
	printf("a) Precio con tarjeta de debito: $ %.2f \n", debitoAerolineas);
	printf("b) Precio con tarjeta de credito: $ %.2f \n", creditoAerolineas);
	printf("c) Precio pagando con bitcoin: %.2f BTC \n", btcAerolineas);
	printf("d) Mostrar precio unitario: $ %.2f\n\n", preciouniAerolineas);
	printf("Precio Latam: $ %.2f \n", latam);
	printf("a) Precio con tarjeta de debito: $ %.2f \n", debitoLatam);
	printf("b) Precio con tarjeta de credito: $ %.2f \n", creditoLatam);
	printf("c) Precio pagando con bitcoin: %.2f BTC\n", btcLatam);
	printf("d) Mostrar precio unitario: $ %.2f\n\n\n", preciouniLatam);
	mostrarDiferencia(latam, aerolineas);
	printf("\n\n\n------------------------------------------\n\n");
}
