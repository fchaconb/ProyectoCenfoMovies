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
	nodoCategoria* dirAnterior(Categoria);

	bool esVacia();

	bool agregarCategoria(Categoria);
	bool eliminarCategoria(string);

	void listarCategorias();
	void consultarLista(string);
};


