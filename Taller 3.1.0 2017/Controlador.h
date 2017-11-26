#pragma once
#include "ArbolBB.h"
#include "arbolEnhebrado.h"
class Controlador
{
public:
	Controlador();
	~Controlador();
	int ValidarNumeroOpcion();
	void Ingresar();
	void ImprimirIno();
	void ImprimirPre();
	void ImprimirPost();
	void Eliminar();
	void TipoDeArbol();
	void IngresoIntABB();
	void IngresoDoubleABB();
	void IngresoStringABB();
	void Cambiarint();
	void CambiarString();
	void CambiarDouble();
	void VaciarArboles();
	bool isNumero(string linea);
	bool isDecimal(string linea);
	ABB<int> arbolint;
	ABB<double> arboldouble;
	ABB<string> arbolstring;
	ArbolEnhebrado<string> ABHstring;
	ArbolEnhebrado<double> ABHdouble;
	ArbolEnhebrado<int> ABHint;
	bool soloint = false;
	bool solodouble = false;
	bool solostring = false;
	
};

