#pragma once
#include "Controlador.h"
class Vista
{
public:
	Vista();
	~Vista();
	void MenuPrincipal();
	void Imprimirarboles();
	void Modificararboles();
	void Configuracion();
	Controlador Ejecutar;
};

