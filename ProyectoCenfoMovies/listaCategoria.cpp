#include "listaCategoria.h"

listaCategoria::listaCategoria()
{
	this->cCab = NULL;
	this->largo = 0;
}

listaCategoria::~listaCategoria()
{
}

void listaCategoria::setCCab(nodoCategoria* ptr)
{
	this->cCab = ptr;
}

nodoCategoria* listaCategoria::getCCab()
{
	return this->cCab;
}

void listaCategoria::setLargo(int pLargo)
{
	this->largo = pLargo;
}

int listaCategoria::getLargo()
{
	return this->largo;
}

nodoCategoria* listaCategoria::dirNodo(Categoria c) {
	nodoCategoria* aux = NULL;

	if (!esVacia()) {
		aux = getCCab();
		while (aux != NULL && !aux->getCategoria().esIgual(c.getNombre())) {
			aux = aux->getCSgte();
		}
	}


	return aux;
}

nodoCategoria* listaCategoria::dirAnterior(Categoria c)
{
	nodoCategoria* aux = NULL;

	if (getLargo() > 1) {
		aux = getCCab();
		while (aux->getCSgte() != NULL)
		{
			if (aux->getCSgte()->getCategoria().esIgual(c.getNombre())) {
				return aux;
			}
		}
	}
}


bool listaCategoria::esVacia()
{
	return cCab == NULL;
}

bool listaCategoria::agregarCategoria(Categoria)
{
	return false;
}

bool listaCategoria::eliminarCategoria(Categoria _categoria) {
	bool eliminado = false;
	if (!esVacia()) {} {
		nodoCategoria* aux = NULL;
		if (!getCCab()->getCategoria().esIgual(_categoria.getNombre())) {
			aux = getCCab();

			setCCab(aux->getCSgte());
			setLargo(getLargo() - 1);

			delete aux;
			eliminado = true;
		}else {
			nodoCategoria* ant = dirAnterior(_categoria);
			if (ant != NULL){
				aux = ant->getCSgte();
				ant->setCSgte(aux->getCSgte());
				setLargo(getLargo() - 1);
				delete aux;
				eliminado = true;
			}
		}
	}
	return eliminado;
}

void listaCategoria::listarCategorias() {
	if (esVacia()) {
		std::cout << "La lista está vacía, por favor agregue categorías";
	}
	else {
		nodoCategoria* aux = getCCab();
		while (aux != NULL) {
			std::cout << aux->getCategoria().getNombre() << "-";
			aux = aux->getCSgte();
		}
		std::cout << "Final \n";
	}
}

Categoria listaCategoria::consultarLista(string pNombre) {
	if (esVacia()) {
		std::cout << "La lista está vacía, por favor agregue categorías";
	}
	else {
		bool encontrado = false;
		nodoCategoria* aux = getCCab();
		while (aux != NULL) {
			if (aux->getCategoria().esIgual(pNombre)) {
				return aux->getCategoria();
			}
			aux = aux->getCSgte();
		}
	}
}
