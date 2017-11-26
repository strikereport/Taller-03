#include "Vista.h"
#include <iostream>
#include <stdlib.h>
using namespace std;



Vista::Vista()
{
}

Vista::~Vista()
{
}

void Vista::MenuPrincipal()
{
	//abrimos el archivo
	Ejecutar.TipoDeArbol();
	cout << " Este es el taller 03" << endl << endl;
	//declaramos una variable para seleccionar la opcion elegida
	int opcion = 0;
	//iniciamos el menu principal
	while (opcion != -1)
	{
		//limpiamos el valor de la opcion cada vez que se reinicie el menu
		cin.clear();
		//desplegamos el menu por pantalla
		cout << " Menu Principal" << endl << endl;
		cout << "[1] Imprimir arboles  " << endl;
		cout << "[2] Modificar arboles " << endl;
		cout << "[3] Configuracion  " << endl;
		cout << "[4] Salir " << endl;
		//validamos que la opcion sea un numero
		opcion = Ejecutar.ValidarNumeroOpcion();
		//luego de validar, nos dirigimos a la opcion seleccioanda
		switch (opcion)
		{
		case 1:
			Imprimirarboles();
			break;
		case 2:
			Modificararboles();
			break;
		case 3:
			Configuracion();
			break;
		case 4:
			//limpiamos la pantalla
			system("cls");
			//cambiamos la condicion para salir
			opcion = -1;
			//damos el mensaje de despedida
			cout << "Gracias por acceder a nuestro sistema, Hasta pronto" << endl;
			system("pause");
			break;
		default:
			//en caso que sea otra opcion no listada, dar un mensaje y se repite el proceso
			cout << "Error: Ingrese opcion valida" << endl;
			system("pause");
			break;
		}// termino del switch
		 //limpiamos la pantalla
		system("cls");
	}//termino del while
	 //para finalizar el programa
	exit(0);
}

void Vista::Imprimirarboles()
{
	// limpiamos la pantalla
		system("cls");
	//declaramos una variable para seleccionar la opcion elegida
	int opcion = 0;
	//iniciamos el menu principal
	while (opcion != -1)
	{
		//limpiamos el valor de la opcion cada vez que se reinicie el menu
		cin.clear();
		//desplegamos el menu por pantalla
		cout << " Imprimir arboles" << endl << endl;
		cout << "[1] Pre-orden  " << endl;
		cout << "[2] In-orden " << endl;
		cout << "[3] Post-orden  " << endl;
		cout << "[4] Por nivel  " << endl;
		cout << "[5] Regresar al menu principal " << endl;
		//validamos que la opcion sea un numero
		opcion = Ejecutar.ValidarNumeroOpcion();
		//luego de validar, nos dirigimos a la opcion seleccioanda
		switch (opcion)
		{
		case 1:
			Ejecutar.ImprimirPre();
			break;
		case 2:
			Ejecutar.ImprimirIno();
			break;
		case 3:
			Ejecutar.ImprimirPost();
			break;
		case 4:
			break;
		case 5:
			//limpiamos la pantalla
			system("cls");
			//cambiamos la condicion para salir
			opcion = -1;
			break;
		default:
			//en caso que sea otra opcion no listada, dar un mensaje y se repite el proceso
			cout << "Error: Ingrese opcion valida" << endl;
			system("pause");
			break;
		}// termino del switch
		 //limpiamos la pantalla
		system("cls");
	}//termino del while
}

void Vista::Modificararboles()
{
	//limpiamos la pantalla
	system("cls");
	//declaramos una variable para seleccionar la opcion elegida
	int opcion = 0;
	//iniciamos el menu principal
	while (opcion != -1)
	{
		//limpiamos el valor de la opcion cada vez que se reinicie el menu
		cin.clear();
		//desplegamos el menu por pantalla
		cout << " Modificar arboles" << endl << endl;
		cout << "[1] Agregar nodo  " << endl;
		cout << "[2] Eliminar nodo " << endl;
		cout << "[3] Vaciar arboles  " << endl;
		cout << "[4] Regresar al menu principal " << endl;
		//validamos que la opcion sea un numero
		opcion = Ejecutar.ValidarNumeroOpcion();
		//luego de validar, nos dirigimos a la opcion seleccioanda
		switch (opcion)
		{
		case 1:
			Ejecutar.Ingresar();
			break;
		case 2:
			Ejecutar.Eliminar();
			break;
		case 3:
			Ejecutar.VaciarArboles();
			break;
		case 4:
			//limpiamos la pantalla
			system("cls");
			//cambiamos la condicion para salir
			opcion = -1;
			break;
		default:
			//en caso que sea otra opcion no listada, dar un mensaje y se repite el proceso
			cout << "Error: Ingrese opcion valida" << endl;
			system("pause");
			break;
		}// termino del switch
		 //limpiamos la pantalla
		system("cls");
	}//termino del while
}

void Vista::Configuracion()
{
	//limpiamos la pantalla
	system("cls");
	//declaramos una variable para seleccionar la opcion elegida
	int opcion = 0;
	//iniciamos el menu principal
	while (opcion != -1)
	{
		//limpiamos el valor de la opcion cada vez que se reinicie el menu
		cin.clear();
		//desplegamos el menu por pantalla
		cout << " tipo de dato aceptado por los arboles" << endl << endl;
		cout << "[1] Solo int " << endl;
		cout << "[2] Solo double " << endl;
		cout << "[3] Solo string  " << endl;
		cout << "[4] Regresar al menu principal " << endl;
		//validamos que la opcion sea un numero
		opcion = Ejecutar.ValidarNumeroOpcion();
		//luego de validar, nos dirigimos a la opcion seleccioanda
		switch (opcion)
		{
		case 1:
			Ejecutar.Cambiarint();
			break;
		case 2:
			Ejecutar.CambiarDouble();
			break;
		case 3:
			Ejecutar.CambiarString();
			break;
		case 4:
			//limpiamos la pantalla
			system("cls");
			//cambiamos la condicion para salir
			opcion = -1;
			break;
		default:
			//en caso que sea otra opcion no listada, dar un mensaje y se repite el proceso
			cout << "Error: Ingrese opcion valida" << endl;
			system("pause");
			break;
		}// termino del switch
		 //limpiamos la pantalla
		system("cls");
	}//termino del while
}


