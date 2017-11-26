#pragma once
#include "nodoEnhebrado.h"
#include <iostream>

template <typename T>
class ArbolEnhebrado {
private:
	NodoEnhebrado<T> *head;
public:
	NodoEnhebrado<T> *root;
	ArbolEnhebrado() {
		head = new NodoEnhebrado<T>();
		head->isHead = true;
		root = NULL;
	}
	bool insertar(T n) {
		// Searching for a NodoEnhebrado<T> with given value
		NodoEnhebrado<T> *aux = root;
		NodoEnhebrado<T> *padre = NULL; // Parent of key to be inserted
		while (aux != NULL)
		{
			// If key already exists, return
			if (n == (aux->dato))
			{
				std::cout << "Dato duplicado\n";
				return false;
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
		NodoEnhebrado<T> *tmp = new NodoEnhebrado<T>(n);
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

		return true;
	}
	NodoEnhebrado<T> *nodoMasIzquierdo(NodoEnhebrado<T> *nodo) {
		if (nodo == NULL)
			return NULL;

		while (nodo->left != NULL && !nodo->lthread)
			nodo = nodo->left;

		return nodo;
	}
	void inorden() {
		NodoEnhebrado<T> *aux = root;
		if (root == NULL)
			std::cout << "Arbol vacio\n";
		aux = nodoMasIzquierdo(aux);
		std::string h;
		while (aux != NULL) {
			std::cout << aux->dato << std::endl;

			if (aux->rthread)
				aux = aux->right;
			else {
				aux = nodoMasIzquierdo(aux->right);
			}
		}
	}
	void preorden() {
		if (root = NULL)
			std::cout << "Arbol vacio" << std::endl;
		NodoEnhebrado<T> *aux = root;
		while (true) {
			std::cout << aux->dato << std::endl;
			while (!aux->lthread) {
				aux = aux->left;
				std::cout << aux->dato << std::endl;
			}
			if (!aux->rthread) {
				aux = aux->right;
			}
			else {
				while (aux->rthread && aux->right != root) {
					aux = aux->right;
				}
				if (aux->right == root) {
					break;
				}
				else {
					aux = aux->right;
				}
			}
		}
	}
	NodoEnhebrado<T> *inSucc(NodoEnhebrado<T> *ptr) {
		if (ptr->rthread == true)
			return ptr->right;

		ptr = ptr->right;
		while (ptr->right);
			ptr = ptr->left;

		return ptr;
	}
	NodoEnhebrado<T> *inPred(NodoEnhebrado<T> *ptr) {
		if (ptr->lthread == true)
			return ptr->right;

		ptr = ptr->left;
		while (ptr->rthread);
		ptr = ptr->right;
		return ptr;
	}
	NodoEnhebrado<T> *casoHoja(NodoEnhebrado<T> *par, NodoEnhebrado<T> *ptr) {
		//si el nodo a eliminar es la raiz
		if (par == NULL)
			root = NULL;


		else if (ptr == par->left)
		{
			par->lthread = true;
			par->left = ptr->left;
		}
		else
		{
			par->rthread = true;
			par->right = ptr->right;
		}
		delete ptr;
		return root;
	}
	NodoEnhebrado<T> *casoUnicoHijo(NodoEnhebrado<T> *par, NodoEnhebrado<T> *ptr) {
		NodoEnhebrado<T> *child;

		// Initialize child NodoEnhebrado<T> to be deleted has
		// left child.
		if (ptr->lthread == false)
			child = ptr->left;

		// NodoEnhebrado<T> to be deleted has right child.
		else
			child = ptr->right;

		// NodoEnhebrado<T> to be deleted is root Node.
		if (par == NULL)
			root = child;

		// NodoEnhebrado<T> is left child of its parent.
		else if (ptr == par->left)
			par->left = child;
		else
			par->right = child;

		// Find successor and predecessor
		NodoEnhebrado<T> *s = inSucc(ptr);
		NodoEnhebrado<T> *p = inPred(ptr);

		// If ptr has left subtree.
		if (ptr->lthread == false)
			p->right = s;

		// If ptr has right subtree.
		else
		{
			if (ptr->rthread == false)
				s->left = p;
		}

		delete ptr;
		return root;
	}
	NodoEnhebrado<T> *casoDosHijos(NodoEnhebrado<T> *par, NodoEnhebrado<T> *ptr) {
		// Find inorder successor and its parent.
		NodoEnhebrado<T> *parsucc = ptr;
		NodoEnhebrado<T> *succ = ptr->right;

		// Find leftmost child of successor
		while (succ->left != NULL)
		{
			parsucc = succ;
			succ = succ->left;
		}

		ptr->dato = succ->dato;

		if (succ->lthread == true && succ->rthread == true)
			root = casoHoja(parsucc, succ);
		else
			root = casoUnicoHijo(parsucc, succ);

		return root;
	}
	bool eliminar(T n) {
		// Initialize padreent as NULL and auxent
		// NodoEnhebrado<T> as root.
		NodoEnhebrado<T> *padre = NULL, *aux = root;

		// Set true if key is found
		int found = 0;

		// Search key in BST : find NodoEnhebrado<T> and its
		// padreent.
		while (aux != NULL)
		{
			if (n == aux->dato)
			{
				found = 1;
				break;
			}
			padre = aux;
			if (n < aux->dato)
			{
				if (aux->lthread == false)
					aux = aux->left;
				else
					break;
			}
			else
			{
				if (aux->rthread == false)
					aux = aux->right;
				else
					break;
			}
		}

		if (found == 0)
			std::cout << "Nodo no existe\n";

		// Two Children
		else if (aux->lthread == false && aux->rthread == false)
			root = casoDosHijos(padre, aux);

		// Only Left Child
		else if (aux->lthread == false)
			root = casoUnicoHijo(padre, aux);

		// Only Right Child
		else if (aux->rthread == false)
			root = casoUnicoHijo(padre, aux);

		// No child
		else
			root = casoHoja(padre, aux);

		return true;
	}
	void vaciar_r(NodoEnhebrado<T> *nodo) {
		if (nodo == NULL) {
			return;
		}
		if (!nodo->lthread)
			vaciar_r(nodo->left);
		if (!nodo->rthread)
			vaciar_r(nodo->right);
		delete nodo;
	}
	void vaciar() {
		vaciar_r(root);
		root = NULL;
	}

};

