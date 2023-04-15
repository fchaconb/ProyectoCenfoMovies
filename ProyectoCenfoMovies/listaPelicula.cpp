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
	nodoPelicula* aux = getPCab();
	if (!esVacia()) {
		aux = getPCab();
		do {
			if (aux->getPelicula().getPNombre() == _pNombre && aux->getPelicula().getPAnnoEstreno() == _pAnnoEstreno) {
				encontrada = true;
			}
			else {
				aux = aux->getPSgte();
			}
		} while (aux != getPCab() && !encontrada);
	}
	if (encontrada) return aux;
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
			cout << "La pelicula ya se encuentra en la lista.";
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
	
	nodoPelicula* aux = getPCab()->getPSgte();
	while (aux != getPCab() && (aux->getPelicula().getPNombre() < newPeli->getPelicula().getPNombre() ||
		(aux->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() &&
			aux->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()))) {

		aux = aux->getPSgte();
	}

	if (aux->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() &&
		aux->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()) {

		return agregado;
	}

	newPeli->setPAnte(aux->getPAnte());
	newPeli->setPSgte(aux);
	aux->getPAnte()->setPSgte(newPeli);
	aux->setPAnte(newPeli);
	setLargo(getLargo() + 1);
	
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
		nodoPelicula* aux = getPCab();
		do {
			if (aux->getPelicula().getPNombre() == _pNombre && aux->getPelicula().getPAnnoEstreno() == _pAnnoEstreno) {
				if (getLargo() == 1) {
					setPCab(NULL);
				} 
				else {
					if (aux == getPCab()) {
						setPCab(getPCab()->getPSgte());
						aux->getPAnte()->setPSgte(aux->getPSgte());
						aux->getPSgte()->setPAnte(aux->getPAnte());
					}
				} 
				delete aux;
				setLargo(getLargo() - 1);
				cout << "Pelicula eliminada!";
				eliminada = true;
				return eliminada;

			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	} return eliminada;
}

bool listaPelicula::consultarPelicula(string _pNombre, int _pAnnoEstreno)
{
	bool encontrada = false;
	nodoPelicula* aux = dirNodo(_pNombre, _pAnnoEstreno);
	if (aux != NULL) {
		encontrada = true;
		std::cout << "Codigo - Nombre - Director - Calificacion - Cant. Solicitudes - Anno Estreno - Sinopsis \n";
		std::cout << aux->getPelicula().getPCodigo() << " - " << aux->getPelicula().getPNombre() << " - " << aux->getPelicula().getPDirector()
			<< " - " << aux->getPelicula().getPCalificacion() << " - " << aux->getPelicula().getPSolicitudes()
			<< " - " << aux->getPelicula().getPAnnoEstreno() << " - " << aux->getPelicula().getPSinopsis();
	}
	else
	{
		cout << "No se encontro la pelicula.";
	}
	return encontrada;
}

bool listaPelicula::modificarNombre(string _pNombre, int _pAnnoEstreno, string _pNewNombre)
{
	bool nombreModificado = false;
	nodoPelicula* aux = dirNodo(_pNombre, _pAnnoEstreno);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPNombre(_pNewNombre);
		aux->setPelicula(refPelicula);
		nombreModificado = true;
		cout << "Nombre modificado!";
	}
	else { 
		cout << "No se encontro la pelicula especificada.";
	}
	return nombreModificado;
}

bool listaPelicula::modificarDirector(string _pNombre, int _pAnnoEstreno, string _pNewDirector)
{
	bool directorModificado = false;
	nodoPelicula* aux = dirNodo(_pNombre, _pAnnoEstreno);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPDirector(_pNewDirector);
		aux->setPelicula(refPelicula);
		directorModificado = true;
		cout << "Director modificado!";
	}
	else {
		cout << "No se encontro la pelicula especificada.";
	}
	return directorModificado;
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
