#pragma once
#include "Categoria.h"

class nodoCategoria
{
private:
	Categoria categoria;
	nodoCategoria* cSgte;
public:
	nodoCategoria();
	nodoCategoria(Categoria);

	void setCategoria(Categoria);
	Categoria getCategoria();
	void setCSgte(nodoCategoria*);
	nodoCategoria* getCSgte();
};

