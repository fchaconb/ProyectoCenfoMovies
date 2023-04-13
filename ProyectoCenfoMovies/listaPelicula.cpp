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

nodoPelicula* listaPelicula::dirNodo(string _pNombre, int _pAnnoEstreno)
{
	bool encontrada = false;
	nodoPelicula* actual = getPCab();
	if (!esVacia()) {
		actual = getPCab();
		do {
			if (actual->getPelicula().getPNombre() == _pNombre && actual->getPelicula().getPAnnoEstreno() == _pAnnoEstreno) {
				encontrada = true;
			}
			actual = actual->getPSgte();
		} while (actual != getPCab() && !encontrada);
	}
	if (encontrada) return actual;
	else return NULL;
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

bool listaPelicula::eliminarPelicula(string _pNombre, int _pAnnoEstreno)
{
	bool eliminada = false;
	if (esVacia()) {
		cout << "La lista esta vacia. \n";
		return eliminada;
	}
	else {
		nodoPelicula* actual = getPCab();
		do {
			if (actual->getPelicula().getPNombre() == _pNombre && actual->getPelicula().getPAnnoEstreno() == _pAnnoEstreno) {
				if (getLargo() == 1) {
					setPCab(NULL);
				}
				if (actual == getPCab()) {
					setPCab(getPCab()->getPSgte());
				}
				actual->getPAnte()->setPSgte(actual->getPSgte());
				actual->getPSgte()->setPAnte(actual->getPAnte());
				delete actual;
				setLargo(getLargo() - 1);
				cout << "Pelicula eliminada!";
				eliminada = true;
				return eliminada;

			}
			actual = actual->getPSgte();
		} while (actual != getPCab());
	} return eliminada;
}

bool listaPelicula::consultarPelicula(string _pNombre, int _pAnnoEstreno)
{
	bool encontrada = false;
	nodoPelicula* actual = dirNodo(_pNombre, _pAnnoEstreno);
	if (actual != NULL) {
		encontrada = true;
		std::cout << "Codigo - Nombre - Director - Calificacion - Cant. Solicitudes - Anno Estreno - Sinopsis \n";
		std::cout << actual->getPelicula().getPCodigo() << " - " << actual->getPelicula().getPNombre() << " - " << actual->getPelicula().getPDirector()
			<< " - " << actual->getPelicula().getPCalificacion() << " - " << actual->getPelicula().getPSolicitudes()
			<< " - " << actual->getPelicula().getPAnnoEstreno() << " - " << actual->getPelicula().getPSinopsis();
	}
	else
	{
		cout << "No se encontro la pelicula.";
	}
	return encontrada;
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
	cout << "Fin de la lista \n";
	}

}

void listaPelicula::listarPeliculasNombreDesc()
{
	if (esVacia())
		std::cout << "La lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab()->getPAnte();
		std::cout << "Codigo - Nombre - Director - Calificacion - Cant. Solicitudes - Anno Estreno - Sinopsis \n";
		do {
			std::cout << aux->getPelicula().getPCodigo() << " - " << aux->getPelicula().getPNombre() << " - " << aux->getPelicula().getPDirector()
				<< " - " << aux->getPelicula().getPCalificacion() << " - " << aux->getPelicula().getPSolicitudes()
				<< " - " << aux->getPelicula().getPAnnoEstreno() << " - " << aux->getPelicula().getPSinopsis() << "\n";
			aux = aux->getPAnte();
		} while (aux != getPCab()->getPAnte());
	cout << "Fin de la lista \n";
	}
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
	cout << "Fin de la lista \n";
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
	cout << "Fin de la lista \n";
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
	cout << "Fin de la lista \n";
	}
}

void listaPelicula::eliminarPeliculasSolicitudInferior(int nSol){
	nodoPelicula* aux = getPCab();

	if (aux != NULL) {
		do{
			if (aux->getPelicula().getPSolicitudes() < nSol) {
				if (getLargo() == 1) {
					setPCab(NULL);
				}
				if (aux == getPCab()) {
					setPCab(getPCab()->getPSgte());
				}
				aux->getPAnte()->setPSgte(aux->getPSgte());
				aux->getPSgte()->setPAnte(aux->getPAnte());
				delete aux;
				setLargo(getLargo() - 1);
				cout << "Pelicula eliminada!";
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	}
}
