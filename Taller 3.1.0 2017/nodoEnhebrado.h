#pragma once
#include <string>

template <typename T>
class NodoEnhebrado {
public:
	T dato;
	bool lthread;
	bool rthread;
	bool isHead;
	NodoEnhebrado *left;
	NodoEnhebrado *right;
	NodoEnhebrado() {
		isHead = false;
		rthread = true;
		lthread = false;
	}
	NodoEnhebrado(T n) {
		isHead = false;
		dato = n;
		rthread = true;
		lthread = false;
	}
};


