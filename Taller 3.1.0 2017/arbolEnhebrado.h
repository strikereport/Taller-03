#pragma once
#include <iostream>


template <typename T>
class ArbolEnhebrado {
private:
	//creamos un struc del nodo
	class NodoTBT
	{
	public:
		T dato;
		bool lthread;
		bool rthread;
		bool isHead;
		NodoTBT *left;
		NodoTBT *right;
	};
	//definimos el nodo
	NodoTBT *root;
	NodoTBT *head;
public:
	ArbolEnhebrado();
	void makeEmpty();
	void Vaciar(NodoTBT *nodo);
	void Insertar(T n);
	void Inorden(NodoTBT *);
	void ImprimirInorden();
	bool Buscar(T n);
	void Borrar(T n);
};

template<typename T>
inline ArbolEnhebrado<T>::ArbolEnhebrado()
{
	head = new NodoTBT();
	head->isHead = true;
	root = NULL;
}

template<typename T>
inline void ArbolEnhebrado<T>::makeEmpty()
{
	Vaciar(root);
	root = NULL;
}

template<typename T>
inline void ArbolEnhebrado<T>::Vaciar(NodoTBT * nodo)
{
	if (nodo == NULL) {
		return;
	}
	if (!nodo->lthread) {
		Vaciar(nodo->left);
	}
	if (!nodo->rthread) {
		Vaciar(nodo->right);
	}
	delete nodo;
}

template<typename T>
inline void ArbolEnhebrado<T>::Insertar(T n)
{
	// Searching for a NodoEnhebrado<T> with given value
	NodoTBT *aux = root;
	NodoTBT *padre = NULL; // Parent of key to be inserted
	while (aux != NULL)
	{
		// If key already exists, return
		if (n == (aux->dato))
		{
			cout << "Dato duplicado\n";
			return;
		}

		padre = aux; // Update padreent pointer

					 // Moving on left subtree.
		if (n < aux->dato)
		{
			if (aux->lthread == false)
				aux = aux->left;
			else
				break;
		}

		// Moving on right subtree.
		else
		{
			if (aux->rthread == false)
				aux = aux->right;
			else
				break;
		}
	}
	// Create a new node
	NodoTBT *tmp = new NodoTBT();
	tmp->dato = n;
	tmp->lthread = true;
	tmp->rthread = true;

	if (padre == NULL)
	{
		root = tmp;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	else if (n < (padre->dato))
	{
		tmp->left = padre->left;
		tmp->right = padre;
		padre->lthread = false;
		padre->left = tmp;
	}
	else
	{
		tmp->left = padre;
		tmp->right = padre->right;
		padre->rthread = false;
		padre->right = tmp;
	}
}

template<typename T>
inline void ArbolEnhebrado<T>::Inorden(NodoTBT * T)
{
}

template<typename T>
inline void ArbolEnhebrado<T>::ImprimirInorden()
{
	Inorden(root);
}


template<typename T>
inline bool ArbolEnhebrado<T>::Buscar(T n)
{
	NodoTBT *aux = root;
	NodoTBT *padre = NULL; // Parent of key to be inserted
	while (aux != NULL)
	{
		// If key already exists, return
		if (n == (aux->dato))
		{
			std::cout << "Dato duplicado en el TBT\n";
			return true;
		}

		padre = aux; // Update padreent pointer

					 // Moving on left subtree.
		if (n < aux->dato)
		{
			if (aux->lthread == false)
				aux = aux->left;
			else
				break;
		}

		// Moving on right subtree.
		else
		{
			if (aux->rthread == false)
				aux = aux->right;
			else
				break;
		}
	}
	return false;
}

template<typename T>
inline void ArbolEnhebrado<T>::Borrar(T n)
{

}


