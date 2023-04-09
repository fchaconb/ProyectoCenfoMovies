#pragma once
#include "nodoCategoria.h"

class listaCategoria
{
private:
	nodoCategoria* cCab;
	int largo;
public:
	listaCategoria();
	~listaCategoria();

	void setCCab(nodoCategoria*);
	nodoCategoria* getCCab();
	void setLargo(int);
	int getLargo();

	nodoCategoria* dirNodo(Categoria);

	bool esVacia();

	bool agregarCategoria(Categoria);
	bool eliminarCategoria(Categoria);

	void listarCategorias();
	Categoria consultarLista(string);
};


