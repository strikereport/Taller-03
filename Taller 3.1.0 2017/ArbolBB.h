#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>  
using namespace std;
//creamos el template
template <typename T>
class ABB  {
private:
	//creamos un struck de un nodo
	struct NodoAbb
	{
		T valor;
		NodoAbb* izquierda;
		NodoAbb* derecha;
		int FactorBalance;

	};
	//definimos el nodo abb
	NodoAbb* raiz;
	//donde iran los metodos
public:
	ABB();
	~ABB();
	void Insertar(T valor);
	void ImprimirInorden();
	void Inorden(NodoAbb*);
	void ImprimirPreorden();
	void Preorden(NodoAbb*);
	void ImprimirPostorden();
	void Postorden(NodoAbb*);
	void VaciarArbol();
	void Vacio(NodoAbb*);
	void Eliminar(T valor);
	bool Buscar(T valor);
};

template<typename T>
inline ABB<T>::ABB()
{
	raiz = NULL;
}

template<typename T>
inline ABB<T>::~ABB()
{
}

template<typename T>
inline void ABB<T>::Insertar(T valor)
{
	NodoAbb* nuevoNodo = new NodoAbb;
	NodoAbb* padre;
	//declaramos los valores del nuevo nodo
	nuevoNodo->valor = valor;
	nuevoNodo->izquierda = NULL;
	nuevoNodo->derecha = NULL;
	nuevoNodo->FactorBalance = 0;
	padre = NULL;
	//verificamos que si esta vacio el arbol
	if (raiz == NULL) {
		//asignamos el nuevo nodo a la raiz
		raiz = nuevoNodo;
	}
	else {
		//creamos varaible auxiliar para el recorrido de hoja
		NodoAbb* ahora;
		ahora = raiz;
		//buscamos el nodo padre
		while (ahora) {
			padre = ahora;
			if (nuevoNodo->valor > ahora->valor) {
				ahora = ahora->derecha;
			}
			else {
				ahora = ahora->izquierda;
			}
		}//fin del while
		if (nuevoNodo->valor < padre->valor) {
			padre->izquierda = nuevoNodo;
		}
		else {
			padre->derecha = nuevoNodo;
		}
	}
}

template<typename T>
inline void ABB<T>::ImprimirInorden()
{
	Inorden(raiz);
}

template<typename T>
inline void ABB<T>::Inorden(NodoAbb* P) {

	if (P != NULL) {
		Inorden(P->izquierda);
		cout << " " << P->valor << " ";
		Inorden(P->derecha);
	}
}

template<typename T>
inline void ABB<T>::ImprimirPreorden()
{
	Preorden(raiz);
}

template<typename T>
inline void ABB<T>::Preorden(NodoAbb *P)
{
	if (P != NULL) {
		cout << " " << P->valor << " ";
		Preorden(P->izquierda);
		Preorden(P->derecha);
	}
}

template<typename T>
inline void ABB<T>::ImprimirPostorden()
{
	Postorden(raiz);
}

template<typename T>
inline void ABB<T>::Postorden(NodoAbb *P)
{
	if (P != NULL) {
		Postorden(P->izquierda);
		Postorden(P->derecha);
		cout << " " << P->valor << " ";
	}
}

template<typename T>
inline void ABB<T>::VaciarArbol()
{
	Vacio(raiz);
	raiz = NULL;
}

template<typename T>
inline void ABB<T>::Vacio(NodoAbb *nodo)
{
	if (nodo == NULL) {
		return;
	}
	if (!nodo->izquierda) {
		Vacio(nodo->izquierda);
	}
	if (!nodo->derecha) {
		Vacio(nodo->derecha);
	}
	delete nodo;
}

template<typename T>
inline void ABB<T>::Eliminar(T valor)
{
	bool encontrado = false;
	//verificar que el arbol este vacio
	if (raiz == NULL) {
		cout << "El arbol se encuentra vacio" << endl;
		return;
	}
	//declaramos los nodos auxiliares
	NodoAbb* ahora;
	NodoAbb* padre;
	ahora = raiz;
	padre = NULL;
	//recorremos hasta encontrar nuestro valor
	while (ahora != NULL) {
		//si lo encontramos paramos 
		if (ahora->valor == valor) {
			encontrado = true;
			break;
		}
		else {
			padre = ahora;
			//verificamos en que direccion nos movemos
			if (valor > ahora->valor) {
				ahora = ahora->derecha;
			}
			else {
				ahora = ahora->izquierda;
			}
		}
	}
		//verificar si encontramos el dato que queremos eliminar
		if (!encontrado) {
			cout << "valor no encontrado" << endl;
			return;
		}
		//ahora verificamos si el nodo a eliminar es hijo unico
		if (ahora->izquierda == NULL && ahora->derecha != NULL || ahora->izquierda != NULL && ahora->derecha == NULL) {
			//verificamos en que lado se encuentra nuestro valor
			if (ahora->izquierda == NULL && ahora->derecha != NULL) {
				if (padre->izquierda == ahora) {
					padre->izquierda = ahora->izquierda;
					delete ahora;
				}
				else {
					padre->derecha = ahora->derecha;
					delete ahora;
				}
			}
			//si el nodo existe en el lado izquierdo , pero no en el derecho
			else {
				if (padre->izquierda == ahora) {
					padre->izquierda = ahora->izquierda;
					delete ahora;
				}
				else {
					padre->derecha = ahora->derecha;
					delete ahora;
				}
			}
			return;
		}// fin de busqueda en un solo hijo

		//buscamos si el nodo no tiene hijos
		if (ahora->izquierda == NULL && ahora->derecha == NULL) {
			//si el padre es nulo se elimina el actual
			if (padre == NULL){
				delete ahora;
			}
			else {
				if (padre->izquierda == ahora) {
					padre->izquierda = NULL;
				}
				else {
					padre->derecha = NULL;
				}
			}
			delete ahora;
			return;
		}// fin de la busqueda en caso que no tenga hijos

		//buscamos ahora en caso que tenga los 2 hijos
		if (ahora->izquierda != NULL && ahora->derecha != NULL) {
			NodoAbb* aux;
			aux = ahora->derecha;
			if ((aux->izquierda == NULL) && (aux->derecha == NULL)) {
				ahora = aux;
				delete aux;
				ahora->derecha = NULL;
			}
			else {
				//si el nodo derecho tiene un hijo
				if ((ahora->derecha)->izquierda != NULL) {
					NodoAbb* izahora;
					NodoAbb* deahora;
					deahora = ahora->derecha;
					izahora = (ahora->derecha)->izquierda;
					//ver en que lado se encuentra el dato
					while (izahora->izquierda != NULL) {
						deahora = izahora;
						izahora = izahora->izquierda;
					}
					ahora->valor = izahora->valor;
					delete izahora;
					deahora->izquierda = NULL;
				}
				else {
					NodoAbb* temporal;
					temporal = ahora->derecha;
					ahora->valor = temporal->valor;
					ahora->derecha = temporal->derecha;
					delete temporal;
				}
			}
			return;
		}//fin de la busqueda de 2 hijos

}

template<typename T>
inline bool ABB<T>::Buscar(T valor)
{
	//localizamos el elemento
	bool encontrado = false;
	if (raiz == NULL) {
		cout << " el arbol esta vacio" << endl;
		return false;
	}

	//creamos nodos auxiliar para la busqueda
	NodoAbb* ahora;
	NodoAbb* padre;
	ahora = raiz;
	padre = NULL;
	//buscamos mientras que ahora no sea null
	while (ahora != NULL) {
		if (ahora->valor == valor) {
			encontrado = true;
			break;
		}
		else {
			padre = ahora;
			if (valor > ahora->valor ) {
				ahora = ahora->derecha;
			}
			else {
				ahora = ahora->izquierda;
			}
		}
	}
	if (!encontrado) {
		cout << "valor no encontrado" << endl;
	}
	return encontrado;
}
//fin del metodo

		