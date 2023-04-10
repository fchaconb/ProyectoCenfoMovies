#include "listaPelicula.h"

listaPelicula::listaPelicula()
{
	this->pCab = NULL;
	this->largo = 0;
}

listaPelicula::~listaPelicula()
{
}

nodoPelicula* listaPelicula::getPCab()
{
	return this->pCab;
}

void listaPelicula::setPCab(nodoPelicula* ptr)
{
	this->pCab = ptr;
}

int listaPelicula::getLargo()
{
	return this->largo;
}

void listaPelicula::setLargo(int _largo)
{
	this->largo = _largo;
}

bool listaPelicula::esVacia()
{
	return pCab	== NULL;
}

bool listaPelicula::agregarPelicula(Pelicula _pelicula)
{
	bool agregado = false;
	nodoPelicula* newPeli = new nodoPelicula(_pelicula);
	if (esVacia()) {
		setPCab(newPeli);
		getPCab()->setPSgte(getPCab());
		getPCab()->setPAnte(getPCab());
		setLargo(getLargo() + 1);
		agregado = true;
		return agregado;
	}

	if (getPCab()->getPelicula().getPNombre() > newPeli->getPelicula().getPNombre() ||
		(getPCab()->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() &&
			getPCab()->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno())) {

		if (getPCab()->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() && getPCab()->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()) {
			return agregado;
		}
		newPeli->setPAnte(getPCab()->getPAnte());
		newPeli->setPSgte(getPCab());

		getPCab()->getPAnte()->setPSgte(newPeli);
		getPCab()->setPAnte(newPeli);
		setPCab(newPeli);
		setLargo(getLargo() + 1);
		agregado = true;
		return agregado;

	}
	
	nodoPelicula* actual = getPCab()->getPSgte();
	while (actual != getPCab() && (actual->getPelicula().getPNombre() < newPeli->getPelicula().getPNombre() ||
		(actual->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() && 
			actual->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()))) {

		actual = actual->getPSgte();
	}

	if (actual->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() &&
		actual->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()) {

		return agregado;
	}

	newPeli->setPAnte(actual->getPAnte());
	newPeli->setPSgte(actual);
	actual->getPAnte()->setPSgte(newPeli);
	actual->setPAnte(newPeli);
	
	return agregado;
}

void listaPelicula::listarPeliculasNombreAsc()
{
	if (esVacia())
		std::cout << "La lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "Codigo - Nombre - Director - Calificacion - Cant. Solicitudes - Anno Estreno - Sinopsis \n";
		do {
			std::cout << aux->getPelicula().getPCodigo() << " - " << aux->getPelicula().getPNombre() << " - " << aux->getPelicula().getPDirector()
				<< " - " << aux->getPelicula().getPCalificacion() << " - " << aux->getPelicula().getPSolicitudes() 
				<< " - " << aux->getPelicula().getPAnnoEstreno() << " - " << aux->getPelicula().getPSinopsis() << "\n";
			aux = aux->getPSgte();
		} while (aux != getPCab());
	std:cout << "Fin de la lista \n";
	}

}

void listaPelicula::listarPeliculasNombreDesc(){
	
}

void listaPelicula::listarPeliculasHilera(string h){
	if (esVacia())
		std::cout << "La lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "Codigo - Nombre - Director - Calificacion - Cant. Solicitudes - Anno Estreno - Sinopsis \n";
		do {
			if (aux->getPelicula().getPNombre().find(h) != std::string::npos){
				std::cout << aux->getPelicula().getPCodigo() << " - " << aux->getPelicula().getPNombre() << " - " << aux->getPelicula().getPDirector()
				<< " - " << aux->getPelicula().getPCalificacion() << " - " << aux->getPelicula().getPSolicitudes()
				<< " - " << aux->getPelicula().getPAnnoEstreno() << " - " << aux->getPelicula().getPSinopsis() << "\n";
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	std:cout << "Fin de la lista \n";
	}
}

void listaPelicula::listarPeliculasRango(int r1, int r2)
{
	if (esVacia())
		std::cout << "La lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "Codigo - Nombre - Director - Calificacion - Cant. Solicitudes - Anno Estreno - Sinopsis \n";
		do {
			if (r1 <= aux->getPelicula().getPAnnoEstreno() && aux->getPelicula().getPAnnoEstreno() <= r2) {
				std::cout << aux->getPelicula().getPCodigo() << " - " << aux->getPelicula().getPNombre() << " - " << aux->getPelicula().getPDirector()
					<< " - " << aux->getPelicula().getPCalificacion() << " - " << aux->getPelicula().getPSolicitudes()
					<< " - " << aux->getPelicula().getPAnnoEstreno() << " - " << aux->getPelicula().getPSinopsis() << "\n";
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	std:cout << "Fin de la lista \n";
	}
}

void listaPelicula::listarPeliculasSolicitudInferior(int nSol)
{
	if (esVacia())
		std::cout << "La lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "Codigo - Nombre - Director - Calificacion - Cant. Solicitudes - Anno Estreno - Sinopsis \n";
		do {
			if (aux->getPelicula().getPSolicitudes() < nSol) {
				std::cout << aux->getPelicula().getPCodigo() << " - " << aux->getPelicula().getPNombre() << " - " << aux->getPelicula().getPDirector()
					<< " - " << aux->getPelicula().getPCalificacion() << " - " << aux->getPelicula().getPSolicitudes()
					<< " - " << aux->getPelicula().getPAnnoEstreno() << " - " << aux->getPelicula().getPSinopsis() << "\n";
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	std:cout << "Fin de la lista \n";
	}
}

void listaPelicula::eliminarPeliculasSolicitudInferior(int){

}
