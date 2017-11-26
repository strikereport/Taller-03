#include "Controlador.h"
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <ctime> 
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


Controlador::Controlador()
{
	
}

Controlador::~Controlador()
{
}

int Controlador::ValidarNumeroOpcion()
{
	//creamos variables locales
	int dato = 0;
	bool continuar;
	int cont = 0;
	do {
		continuar = false;
		cin.clear();
		if (cont > 0)cin.ignore(1024, '\n');
		{
			cout << "Ingrese un opcion" << endl;
			cin >> dato;
			cont++;
		}
		if (cin.fail() && cin.rdstate()) {
			//limpiamos la pantalla
			system("cls");
			//mandamos un mensaje de error
			cout << "Ingreso un caracter no valido, Ingrese Nuevamente un numero" << endl << endl;
			//continuamos hasta obtener un numero
			continuar = true;
		}
	} while (continuar == true);
	//si es un numero se retorna
	return dato;
}

void Controlador::Ingresar()
{
	if (solostring) {
		unsigned t0, t1;
		unsigned t2, t3;
		//limpiamos la pantalla
		system("cls");
		//tomamos el tiempo
		string valor;
		do {
			cin.clear();
			cout << " ingrese un valor" << endl;
			cin >> valor;
			if (isNumero(valor)) {
				cout << "no es un caracter valido ingrese nuevamente" << endl;
			}
			else {
				if (isDecimal(valor)) {
					cout << "no es un caracter valido ingrese nuevamente" << endl;
				}
			}

		} while (isNumero(valor)|| isDecimal(valor));
		//buscamos si se encuentra en el arbol
		t0 = clock();
		if (arbolstring.Buscar(valor)) {
			//si se encuentra mandar un mensaje
			cout << "Dato duplicado en el ABB\n"; 
		}
		else {
			//si no se encuentra se ingresa al arbol
			arbolstring.Insertar(valor);
		}
		t1 = clock();
		cout << endl;
		double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << " el tiempo de ingreso en ABB es " << tiempo << " segundos" << endl;
		cout << endl;
		t2 = clock();
		if (!ABHstring.Buscar(valor)) {
			//si no se encuentra se ingresa al arbol
			ABHstring.Insertar(valor);
		}
		t3 = clock();
		cout << endl;
		double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
		cout << " el tiempo de ingreso en TBT " << tiempoTBT << " segundos" << endl;
		system("pause");
	}
	else {
		if (soloint) {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			string valor;
			do {
				cin.clear();
				cout << " ingrese un valor" << endl;
				cin >> valor;
				if (!isNumero(valor)) {
					cout << "no es un caracter valido ingrese nuevamente" << endl;
				}
				else {
					if (isDecimal(valor)) {
						cout << "no es un caracter valido ingrese nuevamente" << endl;
					}
				}

			} while (!isNumero(valor) || isDecimal(valor));
			//buscamos si se encuentra en el arbol
			int numero = atoi(valor.c_str());
			t0 = clock();
			if (arbolint.Buscar(numero)) {
				//si se encuentra mandar un mensaje
				cout << "Dato duplicado en el ABB\n";
			}
			else {
				//si no se encuentra se ingresa al arbol
				arbolint.Insertar(numero);
			}
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo de ingreso en ABB es " << tiempo << " segundos" << endl;
			t2 = clock();
			if (!ABHint.Buscar(numero)) {
				//si no se encuentra se ingresa al arbol
				ABHint.Insertar(numero);
			}
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo de ingreso en TBT " << tiempoTBT << " segundos" << endl;
			system("pause");

		}
		else {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			string valor;
			do {
				cin.clear();
				cout << " ingrese un valor" << endl;
				cin >> valor;
				if (isNumero(valor)) {
					cout << "no es un caracter valido ingrese nuevamente" << endl;
				}
				else {
					if (!isDecimal(valor)) {
						cout << "no es un caracter valido ingrese nuevamente" << endl;
					}
				}

			} while (isNumero(valor) || !isDecimal(valor));
			//buscamos si se encuentra en el arbol
			double decimal = atof(valor.c_str());
			t0 = clock();
			if (arboldouble.Buscar(decimal)) {
				//si se encuentra mandar un mensaje
				cout << "Dato duplicado en el ABB\n";
			}
			else {
				//si no se encuentra se ingresa al arbol
				arboldouble.Insertar(decimal);
			}
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo de ingreso en ABB es " << tiempo << " segundos" << endl;
			t2 = clock();
			if (!ABHdouble.Buscar(decimal)) {
				//si no se encuentra se ingresa al arbol
				ABHdouble.Insertar(decimal);
			}
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo de ingreso en TBT " << tiempoTBT << " segundos" << endl;
			system("pause");
		}
	}
}

void Controlador::ImprimirIno()
{
	if (solostring) {
		unsigned t0, t1;
		unsigned t2, t3;
		//limpiamos la pantalla
		system("cls");
		//tomamos el tiempo
		t0 = clock();
		cout << "Arbol impreso en Inorden en abb" << endl;
		arbolstring.ImprimirInorden();
		t1 = clock();
		cout << endl;
		double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << " el tiempo fue en inorden en ABB " << tiempo << " segundos" << endl;
		t2 = clock();
		cout << "Arbol impreso en Inorden en TBT" << endl;
		ABHstring.ImprimirInorden();
		t3 = clock();
		cout << endl;
		double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
		cout << " el tiempo fue en inorden en TBT " << tiempoTBT << " segundos" << endl;
		system("pause");
	}
	else {
		if (soloint) {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			cout << "Arbol impreso en Inorden" << endl;
			arbolint.ImprimirInorden();
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en inorden en ABB  " << tiempo << " segundos" << endl;
			t2 = clock();
			cout << "Arbol impreso en Inorden en TBT" << endl;
			
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en inorden en TBT " << tiempoTBT << " segundos" << endl;
			system("pause");

		}
		else {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			cout << "Arbol impreso en Inorden" << endl;
			arboldouble.ImprimirInorden();
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en inorden en ABB  " << tiempo << " segundos" << endl;
			t2 = clock();
			cout << "Arbol impreso en Inorden en TBT" << endl;
			
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en inorden en TBT " << tiempoTBT << " segundos" << endl;
			system("pause");
		}
	}
}

void Controlador::ImprimirPre()
{
	if (solostring) {
		unsigned t0, t1;
		unsigned t2, t3;
		//limpiamos la pantalla
		system("cls");
		//tomamos el tiempo
		t0 = clock();
		cout << "Arbol impreso en pre orden" << endl;
		arbolstring.ImprimirPreorden();
		t1 = clock();
		cout << endl;
		double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << " el tiempo fue en pre orden  en ABB  " << tiempo << " segundos" << endl;
		t2 = clock();
		cout << "Arbol impreso en pre orden" << endl;
		
		t3 = clock();
		cout << endl;
		double tiempoTBT = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << " el tiempo fue en pre orden  en TBT  " << tiempoTBT << " segundos" << endl;

		system("pause");
	}
	else {
		if (soloint) {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			cout << "Arbol impreso en pre orden" << endl;
			arbolint.ImprimirPreorden();
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en pre orden en ABB  " << tiempo << " segundos" << endl;
			t2 = clock();
			cout << "Arbol impreso en pre orden en TBT" << endl;
			
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en pre orden en TBT " << tiempo << " segundos" << endl;
			system("pause");
			system("pause");

		}
		else {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			cout << "Arbol impreso en pre orden" << endl;
			arboldouble.ImprimirPreorden();
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en Pre Orden en ABB  " << tiempo << " segundos" << endl;
			t2 = clock();
			cout << "Arbol impreso en pre orden en TBT" << endl;
			
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en pre orden en TBT " << tiempo << " segundos" << endl;
			system("pause");
			system("pause");
		}
	}
}

void Controlador::ImprimirPost()
{
	if (solostring) {
		unsigned t0, t1;
		//limpiamos la pantalla
		system("cls");
		//tomamos el tiempo
		t0 = clock();
		cout << "Arbol impreso en post orden" << endl;
		arbolstring.ImprimirPostorden();
		t1 = clock();
		cout << endl;
		double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << " el tiempo fue en post orden en ABB  " << tiempo << " segundos" << endl;
		system("pause");
	}
	else {
		if (soloint) {
			unsigned t0, t1;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			cout << "Arbol impreso en post orden " << endl;
			arbolint.ImprimirPostorden();
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en post orden en ABB  " << tiempo << " segundos" << endl;
			system("pause");

		}
		else {
			unsigned t0, t1;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			cout << "Arbol impreso en post orden" << endl;
			arboldouble.ImprimirPostorden();
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo fue en post orden  en ABB  " << tiempo << " segundos" << endl;
			system("pause");
		}
	}
}

void Controlador::Eliminar()
{
	if (solostring) {
		unsigned t0, t1;
		unsigned t2, t3;
		//limpiamos la pantalla
		system("cls");
		//tomamos el tiempo
		string valor;
		do {
			cin.clear();
			cout << " ingrese un valor" << endl;
			cin >> valor;
			if (isNumero(valor)) {
				cout << "no es un caracter valido ingrese nuevamente" << endl;
			}
			else {
				if (isDecimal(valor)) {
					cout << "no es un caracter valido ingrese nuevamente" << endl;
				}
			}

		} while (isNumero(valor) || isDecimal(valor));
		//buscamos si se encuentra en el arbol
		if (arbolstring.Buscar(valor)) {
			t0 = clock();
			//si se encuentra mandar un mensaje
			arbolstring.Eliminar(valor);
		}
		else {
			//si no se encuentra se ingresa al arbol
			cout << "el valor no se encuentra en el arbol" << endl;
		}
		t1 = clock();
		cout << endl;
		double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << " el tiempo de eliminacion en ABB es  " << tiempo << " segundos" << endl;
		t2 = clock();
		
		t3 = clock();
		cout << endl;
		double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
		cout << " el tiempo de eliminar en TBT " << tiempoTBT << " segundos" << endl;
		system("pause");
	}
	else {
		if (soloint) {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			string valor;
			do {
				cin.clear();
				cout << " ingrese un valor" << endl;
				cin >> valor;
				if (!isNumero(valor)) {
					cout << "no es un caracter valido ingrese nuevamente" << endl;
				}
				else {
					if (isDecimal(valor)) {
						cout << "no es un caracter valido ingrese nuevamente" << endl;
					}
				}

			} while (!isNumero(valor) || isDecimal(valor));
			//buscamos si se encuentra en el arbol
			if (arbolint.Buscar(atoi(valor.c_str()))) {
				//si se encuentra mandar un mensaje
				t0 = clock();
				arbolint.Eliminar(atoi(valor.c_str()));
			}
			else {
				//si no se encuentra se ingresa al arbol
				cout << "el valor no se encuentra en el arbol" << endl;
			}
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo de eliminacion en ABB es   " << tiempo << " segundos" << endl;
			system("pause");
			t2 = clock();
			
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo de eliminar en TBT " << tiempoTBT << " segundos" << endl;

		}
		else {
			unsigned t0, t1;
			unsigned t2, t3;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			string valor;
			do {
				cin.clear();
				cout << " ingrese un valor" << endl;
				cin >> valor;
				if (isNumero(valor)) {
					cout << "no es un caracter valido ingrese nuevamente" << endl;
				}
				else {
					if (!isDecimal(valor)) {
						cout << "no es un caracter valido ingrese nuevamente" << endl;
					}
				}

			} while (isNumero(valor) || !isDecimal(valor));
			//buscamos si se encuentra en el arbol
			if (arboldouble.Buscar(atof(valor.c_str()))) {
				//si se encuentra mandar un mensaje
				t0 = clock();
				arboldouble.Eliminar(atof(valor.c_str()));
			}
			else {
				//si no se encuentra se ingresa al arbol
				cout << "el valor no se encuentra en el arbol" << endl;
			}
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo de eliminacion en ABB es    " << tiempo << " segundos" << endl;
			t2 = clock();
			
			t3 = clock();
			cout << endl;
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo de eliminar en TBT " << tiempoTBT << " segundos" << endl;
			system("pause");
		}
	}
}

void Controlador::TipoDeArbol()
{
	//abrimos el archivo
	ifstream TipoArchivo("datos.txt");
	//validamos que el archivo no se encuentra vacio
	if (!TipoArchivo) {
		// si no existe, lanza un mensaje de error y se termina la ejecucion
		cout << " El archivo  no existe" << endl;
		// se realiza una pausa para que lea el mensaje
		system("pause");
		// se termina la ejecucion del programa
		exit(0);
	}
	//verificamos el peso del archivo
	TipoArchivo.seekg(0, ios::end);
	//determinamos que el archivo se encuentra vacio
	if (TipoArchivo.tellg() < 1) {
		// si no existe, lanza un mensaje de error y se termina la ejecucion
		cout << " El archivo se encuentra vacio" << endl;
		// se realiza una pausa para que lea el mensaje
		system(" pause");
		// se termina la ejecucion del programa
		exit(0);
	}
	//regresamos el apuntador al inicio
	TipoArchivo.seekg(0, ios::beg);
	//ahora recorramos el archivo
	string variable;
	while(!TipoArchivo.eof()) {
		//obtenemos la primera variable;
		getline(TipoArchivo, variable, '\n');
		//salimos del archivo
		break;
	}
	TipoArchivo.close();
	if (isNumero(variable)) {
		//si es un entero nos vamos a ingresar solo enteros
		IngresoIntABB();
		soloint = true;
	}
	else {
		if (isDecimal(variable)) {
			//si es un decimal nos vamos a ingresar solo souble
			IngresoDoubleABB();
			solodouble = true;
		}
		else {
			//si es una palabra nos vamos a ingresar solo string
			IngresoStringABB();
			solostring = true;
		}
	}	
	//limpiamos la pantalla
	system("cls");
}

void Controlador::IngresoIntABB()
{
	//abrimos el archivo
	ifstream TipoArchivo("datos.txt");
	string variable;
	//validamos que solo int dentro del archivo
	while (!TipoArchivo.eof()) {
		//obtenemos la  variable;
		getline(TipoArchivo, variable, '\n');
		//verificamos que sea int, si no lo es se termina el programa
			if(!isNumero(variable) && variable != "") {
				cout << " Esta variable no es un entero. Se termina el programa" << endl;
				TipoArchivo.close();
				system("pause");
				exit(0);
			}
	}
	TipoArchivo.close();
	//despues de verificar que todo el archivo tiene los datos correcto se prodece a agregar al arbol
	TipoArchivo.open("datos.txt");
	int Numero;
	while (!TipoArchivo.eof()) {
		//obtenemos la variable
		TipoArchivo >> Numero;
		//buscamos en el arbol si el valor no esta en el arbol
		if (!arbolint.Buscar(Numero)) {
			//si no esta se agrega
			arbolint.Insertar(Numero);
		}
		ABHint.Insertar(Numero);
	}
	//una vez termina se cierra el archivo
	TipoArchivo.close();
}

void Controlador::IngresoDoubleABB()
{
	//abrimos el archivo
	ifstream TipoArchivo("datos.txt");
	string variable;
	//validamos que solo int dentro del archivo
	while (!TipoArchivo.eof()) {
		//obtenemos la  variable;
		getline(TipoArchivo, variable, '\n');
		//verificamos que sea int, si no lo es se termina el programa
		if (!isDecimal(variable) && variable != "") {
			cout << " Esta variable no es un decimal. Se termina el programa" << endl;
			TipoArchivo.close();
			system("pause");
			exit(0);
		}
	}
	TipoArchivo.close();
	//despues de verificar que todo el archivo tiene los datos correcto se prodece a agregar al arbol
	TipoArchivo.open("datos.txt");
	double Decimal;
	while (!TipoArchivo.eof()) {
		//obtenemos la variable
		TipoArchivo >> Decimal;
		//buscamos en el arbol si el valor no esta en el arbol
		if (!arboldouble.Buscar(Decimal)) {
			//si no esta se agrega
			arboldouble.Insertar(Decimal);
		}
		ABHdouble.Insertar(Decimal);
	}
	//una vez termina se cierra el archivo
	TipoArchivo.close();
}

void Controlador::IngresoStringABB()
{
	//abrimos el archivo
	ifstream TipoArchivo("datos.txt");
	string variable;
	//validamos que solo int dentro del archivo
	while (!TipoArchivo.eof()) {
		//obtenemos la  variable;
		getline(TipoArchivo, variable, '\n');
		//verificamos que sea int, si no lo es se termina el programa
		if (isNumero(variable) && variable != "") {
			cout << " Esta variable no es un palabra. Se termina el programa" << endl;
			TipoArchivo.close();
			system("pause");
			exit(0);
		}
	}
	TipoArchivo.close();
	//despues de verificar que todo el archivo tiene los datos correcto se prodece a agregar al arbol
	TipoArchivo.open("datos.txt");
	string Palabra;
	while (!TipoArchivo.eof()) {
		//obtenemos la variable
		TipoArchivo >> Palabra;
		//buscamos en el arbol si el valor no esta en el arbol
		if (!arbolstring.Buscar(Palabra)) {
			//si no esta se agrega
			arbolstring.Insertar(Palabra);
		}
		ABHstring.Insertar(Palabra);
	}
	//una vez termina se cierra el archivo
	TipoArchivo.close();
}

void Controlador::Cambiarint()
{
	//eliminamos los arboles
	arbolint.VaciarArbol();
	arboldouble.VaciarArbol();
	arbolstring.VaciarArbol();
	//validamos que solo se ingrese ese arbol
	solodouble = false;
	solostring = false;
	soloint = true;
	ABHstring.makeEmpty();
	ABHint.makeEmpty();
	ABHdouble.makeEmpty();
	//mandamos un mensaje 
	cout << " cambio realizado el arbol solo acepta int" << endl;
	system("pause");
}

void Controlador::CambiarString()
{
	//eliminamos los arboles
	arbolint.VaciarArbol();
	arboldouble.VaciarArbol();
	arbolstring.VaciarArbol();
	ABHstring.makeEmpty();
	ABHint.makeEmpty();
	ABHdouble.makeEmpty();
	//validamos que solo se ingrese ese arbol
	solodouble = false;
	solostring = true;
	soloint = false;
	//mandamos un mensaje 
	cout << " cambio realizado el arbol solo acepta string" << endl;
	system("pause");
}

void Controlador::CambiarDouble()
{
	//eliminamos los arboles
	arbolint.VaciarArbol();
	arboldouble.VaciarArbol();
	arbolstring.VaciarArbol();
	ABHstring.makeEmpty();
	ABHint.makeEmpty();
	ABHdouble.makeEmpty();
	//validamos que solo se ingrese ese arbol
	solodouble = true;
	solostring = false;
	soloint = false;
	//mandamos un mensaje 
	cout << " cambio realizado el arbol solo acepta double" << endl;
	system("pause");
}

void Controlador::VaciarArboles()
{
	if (solostring) {
		unsigned t0, t1;
		//limpiamos la pantalla
		system("cls");
		//tomamos el tiempo
		t0 = clock();
		arbolstring.VaciarArbol();
		cout << " ABB Borrado" << endl;
		t1 = clock();
		cout << endl;
		double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << " el tiempo de vaciado en ABB es   " << tiempo << " segundos" << endl;
		cout << endl;
		//parte del arbol binario henebrado
		unsigned t2, t3;
		t2 = clock();
		ABHstring.makeEmpty();
		cout << " TBT Borrado" << endl;
		t3 = clock();
		double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
		cout << " el tiempo de vaciado en TBT es   " << tiempo << " segundos" << endl;
		system("pause");
	}
	else {
		if (soloint) {
			unsigned t0, t1;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			arbolint.VaciarArbol();
			cout << " ABB Borrado" << endl;
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo de vaciado en ABB es   " << tiempo << " segundos" << endl;
			//parte del arbol binario henebrado
			cout << endl;
			unsigned t2, t3;
			t2 = clock();
			ABHint.makeEmpty();
			cout << " TBT Borrado" << endl;
			t3 = clock();
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo de vaciado en TBT es   " << tiempo << " segundos" << endl;
			system("pause");
		}
		else {
			unsigned t0, t1;
			//limpiamos la pantalla
			system("cls");
			//tomamos el tiempo
			t0 = clock();
			arboldouble.VaciarArbol();
			cout << " ABB Borrado" << endl;
			t1 = clock();
			cout << endl;
			double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << " el tiempo de vaciado en ABB es   " << tiempo << " segundos" << endl;
			cout << endl;
			//parte del arbol binario henebrado
			unsigned t2, t3;
			t2 = clock();
			ABHstring.makeEmpty();
			cout << " TBT Borrado" << endl;
			t3 = clock();
			double tiempoTBT = (double(t3 - t2) / CLOCKS_PER_SEC);
			cout << " el tiempo de vaciado en TBT es   " << tiempo << " segundos" << endl;
			system("pause");
		}
	}
}

bool Controlador::isNumero(string linea)
{
	int longitud = linea.size();
	if (longitud == 0) {
		return false;
	}
	else if (longitud == 1 && !isdigit(linea[0])) {
		return false;
	}
	else {
		int i;
		if (linea[0] == '+' || linea[0] == '-') i = 1;
		else i = 0;
		while (i < longitud) {
			if (!isdigit(linea[i])) {
				return false;
			}
			i++;
		}
	}
	return true;
}

bool Controlador::isDecimal(string linea)
{
	//declaramos las variables
	float x;
	int y;
	x = strtof((linea).c_str(), 0);
	y =(int) x;
	x = x - y;
	if (x > 0) {
		return true;
	}
	return false;
}

