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

bool listaCategoria::agregarCategoria(Categoria c)
{
	nodoCategoria* nuevaCat = new nodoCategoria(c);

	if (esVacia()){
		setCCab(nuevaCat);
		setLargo(getLargo() + 1);
		return true;
	}else {
			if (c.getNombre() < getCCab()->getCategoria().getNombre()){
				nuevaCat->setCSgte(getCCab());
				setCCab(nuevaCat);
				setLargo(getLargo() + 1);
				return true;
			}else {
				nodoCategoria* aux = getCCab();
				while (aux->getCSgte() !=NULL && c.getNombre() > aux->getCSgte()->getCategoria().getNombre()){
					aux = aux->getCSgte();
				}
				nuevaCat->setCSgte(aux->getCSgte());
				aux->setCSgte(nuevaCat);
				setLargo(getLargo() + 1);
				return true;
			}
	}
	return false;
}

bool listaCategoria::eliminarCategoria(string nCategoria) {
	bool eliminado = false;
	if (!esVacia()) {} {
		nodoCategoria* aux = NULL;
		if (getCCab()->getCategoria().getNombre() == nCategoria) {
			aux = getCCab();

			setCCab(aux->getCSgte());
			setLargo(getLargo() - 1);

			delete aux;
			eliminado = true;
		}else {
			nodoCategoria* ant = dirAnterior(nCategoria);
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
		std::cout << "La lista est� vac�a, por favor agregue categor�as";
	}
	else {
		nodoCategoria* aux = getCCab();
		while (aux != NULL) {
			std::cout << aux->getCategoria().getNombre() << "-";
			aux = aux->getCSgte();
		}
		std::cout << "Final de la lista \n";
	}
}

void listaCategoria::consultarLista(string pNombre) {
	if (esVacia()) {
		std::cout << "La lista est� vac�a, por favor agregue categor�as";
	}else {
		nodoCategoria* aux = getCCab();
		while (aux != NULL) {
			if (aux->getCategoria().esIgual(pNombre)) {
				std::cout << "El nombre es: " << aux->getCategoria().getNombre();
				std::cout << "El n�mero de peliculas es: " << aux->getCategoria().getCantPeliculas();
			}
			aux = aux->getCSgte();
		}
	}
}
