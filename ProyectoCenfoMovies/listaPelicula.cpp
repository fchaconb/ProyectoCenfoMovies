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

nodoPelicula* listaPelicula::dirNodo(int _pCodigo)
{
	bool encontrada = false;
	nodoPelicula* aux = getPCab();
	if (!esVacia()) {
		aux = getPCab();
		do {
			if (aux->getPelicula().getPCodigo() == _pCodigo) {
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
		cout << "\nPelicula agregada!!\n";
		return agregado;
	}

	if (getPCab()->getPelicula().getPCodigo() == newPeli->getPelicula().getPCodigo() ||
		getPCab()->getPelicula().getPNombre() > newPeli->getPelicula().getPNombre() ||
		(getPCab()->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() &&
			getPCab()->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno())) {

		if (getPCab()->getPelicula().getPCodigo() == newPeli->getPelicula().getPCodigo()) {
			cout << "\nEl codigo de pelicula ya esta asignado a otra pelicula.";
			return agregado;
		}

		if (getPCab()->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() && getPCab()->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()) {
			cout << "\nLa pelicula ya se encuentra en la lista.";
			return agregado;
		}
		newPeli->setPAnte(getPCab()->getPAnte());
		newPeli->setPSgte(getPCab());

		getPCab()->getPAnte()->setPSgte(newPeli);
		getPCab()->setPAnte(newPeli);
		setPCab(newPeli);
		setLargo(getLargo() + 1);
		cout << "\nPelicula agregada!!\n";
		agregado = true;
		return agregado;

	}
	
	nodoPelicula* aux = getPCab()->getPSgte();
	while (aux != getPCab() && (aux->getPelicula().getPNombre() < newPeli->getPelicula().getPNombre() ||
		(aux->getPelicula().getPCodigo() == newPeli->getPelicula().getPCodigo() ||
			aux->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() &&
			aux->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()))) {

		if (aux->getPelicula().getPCodigo() == newPeli->getPelicula().getPCodigo()) {
			cout << "\nEl codigo de pelicula ya esta asignado a otra pelicula.";
			return agregado;
		}

		if (aux->getPelicula().getPNombre() == newPeli->getPelicula().getPNombre() &&
			aux->getPelicula().getPAnnoEstreno() == newPeli->getPelicula().getPAnnoEstreno()) {
			cout << "\nLa pelicula ya se encuentra en la lista.";
			return agregado;
		}
		aux = aux->getPSgte();
	}

	newPeli->setPAnte(aux->getPAnte());
	newPeli->setPSgte(aux);
	aux->getPAnte()->setPSgte(newPeli);
	aux->setPAnte(newPeli);
	setLargo(getLargo() + 1);
	cout << "\nPelicula agregada!!\n";
	agregado = true;
	return agregado;
}

bool listaPelicula::eliminarPelicula(int _pCodigo)
{
	bool eliminada = false;
	if (esVacia()) {
		cout << "La lista esta vacia. \n";
		return eliminada;
	}
	else {
		nodoPelicula* aux = getPCab();
		do {
			if (aux->getPelicula().getPCodigo() == _pCodigo) {
				if (getLargo() == 1) {
					setPCab(NULL);
				} 
				else {
					if (aux == getPCab()) {
						setPCab(getPCab()->getPSgte());
					}
					aux->getPAnte()->setPSgte(aux->getPSgte());
					aux->getPSgte()->setPAnte(aux->getPAnte());
				} 
				delete aux;
				setLargo(getLargo() - 1);
				cout << "\nPelicula eliminada!";
				eliminada = true;
				return eliminada;

			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	} return eliminada;
}

bool listaPelicula::consultarPelicula(int _pCodigo)
{
	bool encontrada = false;
	nodoPelicula* aux = dirNodo(_pCodigo);
	if (aux != NULL) {
		encontrada = true;
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		std::cout << aux->getPelicula().getPCodigo() << " \t " << aux->getPelicula().getPNombre() << " \t " << aux->getPelicula().getPDirector()
			<< " \t " << aux->getPelicula().getPCalificacion() << " \t\t " << aux->getPelicula().getPSolicitudes()
			<< " \t\t\t " << aux->getPelicula().getPAnnoEstreno() << " \t\t " << aux->getPelicula().getPSinopsis() << "\n";
	}
	else
	{
		cout << "\nNo se encontro la pelicula.";
	}
	return encontrada;
}

bool listaPelicula::modificarNombre(int _pCodigo, string _pNewNombre)
{
	bool nombreModificado = false;
	nodoPelicula* aux = dirNodo(_pCodigo);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPNombre(_pNewNombre);
		aux->setPelicula(refPelicula);
		nombreModificado = true;
		cout << "\nNombre modificado!";
	}
	else { 
		cout << "\nNo se encontro la pelicula especificada.";
	}
	return nombreModificado;
}

bool listaPelicula::modificarDirector(int _pCodigo, string _pNewDirector)
{
	bool directorModificado = false;
	nodoPelicula* aux = dirNodo(_pCodigo);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPDirector(_pNewDirector);
		aux->setPelicula(refPelicula);
		directorModificado = true;
		cout << "\nDirector modificado!";
	}
	else {
		cout << "\nNo se encontro la pelicula especificada.";
	}
	return directorModificado;
}

bool listaPelicula::modificarCalificacion(int _pCodigo, float _pNewCalificacion)
{
	bool calificacionModificada = false;
	nodoPelicula* aux = dirNodo(_pCodigo);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPCalificacion(_pNewCalificacion);
		aux->setPelicula(refPelicula);
		calificacionModificada = true;
		cout << "\nCalificacion modificada!";
	}
	else {
		cout << "\nNo se encontro la pelicula especificada.";
	}
	return calificacionModificada;
}

bool listaPelicula::modificarSolicitudes(int _pCodigo, int _pNewSolicitudes)
{
	bool solicitudesModificada = false;
	nodoPelicula* aux = dirNodo(_pCodigo);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPSolicitudes(_pNewSolicitudes);
		aux->setPelicula(refPelicula);
		solicitudesModificada = true;
		cout << "\nCantidad de solicitudes modificada!";
	}
	else {
		cout << "\nNo se encontro la pelicula especificada.";
	}
	return solicitudesModificada;
}

bool listaPelicula::modificarAnnoEstreno(int _pCodigo, int _pNewAnnoEstreno)
{
	bool estrenoModificado = false;
	nodoPelicula* aux = dirNodo(_pCodigo);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPAnnoEstreno(_pNewAnnoEstreno);
		aux->setPelicula(refPelicula);
		estrenoModificado = true;
		cout << "\nAnno de estreno modificado!";
	}
	else {
		cout << "\nNo se encontro la pelicula especificada.";
	}
	return estrenoModificado;
}

bool listaPelicula::modificarSinopsis(int _pCodigo, string _pNewSinopsis)
{
	bool sinopsisModificada = false;
	nodoPelicula* aux = dirNodo(_pCodigo);
	if (aux != NULL) {
		Pelicula peliculaModificada = aux->getPelicula();
		Pelicula& refPelicula = peliculaModificada;
		refPelicula.setPSinopsis(_pNewSinopsis);
		aux->setPelicula(refPelicula);
		sinopsisModificada = true;
		cout << "\nSinopsis modificada!";
	}
	else {
		cout << "\nNo se encontro la pelicula especificada.";
	}
	return sinopsisModificada;
}

void listaPelicula::listarPeliculasCodigoAsc()
{
	if (esVacia()) {
		cout << "\nLa lista esta vacia. \n";
		return;
	}
	else {
		listaPelicula listaOrdenada;
		nodoPelicula* aux = getPCab();
		do {
			nodoPelicula* temp = listaOrdenada.getPCab();
			nodoPelicula* prev = NULL;
			while (temp && temp->getPelicula().getPCodigo() <= aux->getPelicula().getPCodigo()) {
				prev = temp;
				temp = temp->getPSgte();
			}
			nodoPelicula* newNode = new nodoPelicula(aux->getPelicula());
			if (prev) {
				prev->setPSgte(newNode);
				newNode->setPAnte(prev);
			}
			else {
				listaOrdenada.setPCab(newNode);
			}
			if (temp) {
				temp->setPAnte(newNode);
				newNode->setPSgte(temp);
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());

		// Print the sorted list
		nodoPelicula* aux2 = listaOrdenada.getPCab();
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		while (aux2 != NULL) {
			cout << aux2->getPelicula().getPCodigo() << " \t " << aux2->getPelicula().getPNombre() << " \t " << aux2->getPelicula().getPDirector()
				<< " \t " << aux2->getPelicula().getPCalificacion() << " \t\t " << aux2->getPelicula().getPSolicitudes()
				<< " \t\t\t " << aux2->getPelicula().getPAnnoEstreno() << " \t\t " << aux2->getPelicula().getPSinopsis() << "\n";
			aux2 = aux2->getPSgte();
		}
		cout << "\nFin de la lista \n";
	}
}

void listaPelicula::listarPeliculasCodigoDesc()
{
	if (esVacia()) {
		cout << "\nLa lista esta vacia. \n";
		return;
	}
	else {
		listaPelicula listaOrdenada;
		nodoPelicula* aux = getPCab();
		do {
			nodoPelicula* temp = listaOrdenada.getPCab();
			nodoPelicula* prev = NULL;
			while (temp && temp->getPelicula().getPCodigo() >= aux->getPelicula().getPCodigo()) {
				prev = temp;
				temp = temp->getPSgte();
			}
			nodoPelicula* newNode = new nodoPelicula(aux->getPelicula());
			if (prev) {
				prev->setPSgte(newNode);
				newNode->setPAnte(prev);
			}
			else {
				listaOrdenada.setPCab(newNode);
			}
			if (temp) {
				temp->setPAnte(newNode);
				newNode->setPSgte(temp);
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());

		// Print the sorted list
		nodoPelicula* aux2 = listaOrdenada.getPCab();
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		while (aux2 != NULL) {
			cout << aux2->getPelicula().getPCodigo() << " \t " << aux2->getPelicula().getPNombre() << " \t " << aux2->getPelicula().getPDirector()
				<< " \t " << aux2->getPelicula().getPCalificacion() << " \t\t " << aux2->getPelicula().getPSolicitudes()
				<< " \t\t\t " << aux2->getPelicula().getPAnnoEstreno() << " \t\t " << aux2->getPelicula().getPSinopsis() << "\n";
			aux2 = aux2->getPSgte();
		}
		cout << "\nFin de la lista \n";
	}
}

void listaPelicula::listarPeliculasNombreAsc()
{
	if (esVacia())
		std::cout << "\nLa lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		do {
			std::cout << aux->getPelicula().getPCodigo() << " \t " << aux->getPelicula().getPNombre() << " \t " << aux->getPelicula().getPDirector()
				<< " \t " << aux->getPelicula().getPCalificacion() << " \t\t " << aux->getPelicula().getPSolicitudes() 
				<< " \t\t\t " << aux->getPelicula().getPAnnoEstreno() << " \t\t " << aux->getPelicula().getPSinopsis() << "\n";
			aux = aux->getPSgte();
		} while (aux != getPCab());
	cout << "\nFin de la lista \n";
	}

}

void listaPelicula::listarPeliculasNombreDesc()
{
	if (esVacia())
		std::cout << "\nLa lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab()->getPAnte();
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		do {
			std::cout << aux->getPelicula().getPCodigo() << " \t " << aux->getPelicula().getPNombre() << " \t " << aux->getPelicula().getPDirector()
				<< " \t " << aux->getPelicula().getPCalificacion() << " \t\t " << aux->getPelicula().getPSolicitudes()
				<< " \t\t\t " << aux->getPelicula().getPAnnoEstreno() << " \t\t " << aux->getPelicula().getPSinopsis() << "\n";
			aux = aux->getPAnte();
		} while (aux != getPCab()->getPAnte());
	cout << "\nFin de la lista \n";
	}
}

void listaPelicula::listarPeliculasAnnoAsc()
{
	if (esVacia()) {
		cout << "\nLa lista esta vacia. \n";
		return;
	}
	else {
		listaPelicula listaOrdenada;
		nodoPelicula* aux = getPCab();
		do {
			nodoPelicula* temp = listaOrdenada.getPCab();
			nodoPelicula* prev = NULL;
			while (temp && temp->getPelicula().getPAnnoEstreno() <= aux->getPelicula().getPAnnoEstreno()) {
				prev = temp;
				temp = temp->getPSgte();
			}
			nodoPelicula* newNode = new nodoPelicula(aux->getPelicula());
			if (prev) {
				prev->setPSgte(newNode);
				newNode->setPAnte(prev);
			}
			else {
				listaOrdenada.setPCab(newNode);
			}
			if (temp) {
				temp->setPAnte(newNode);
				newNode->setPSgte(temp);
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());

		// Print the sorted list
		nodoPelicula* aux2 = listaOrdenada.getPCab();
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		while (aux2 != NULL) {
			cout << aux2->getPelicula().getPCodigo() << " \t " << aux2->getPelicula().getPNombre() << " \t " << aux2->getPelicula().getPDirector()
				<< " \t " << aux2->getPelicula().getPCalificacion() << " \t\t " << aux2->getPelicula().getPSolicitudes()
				<< " \t\t\t " << aux2->getPelicula().getPAnnoEstreno() << " \t\t " << aux2->getPelicula().getPSinopsis() << "\n";
			aux2 = aux2->getPSgte();
		}
		cout << "\nFin de la lista \n";
	}
}


void listaPelicula::listarPeliculasAnnoDesc()
{
	if (esVacia()) {
		cout << "\nLa lista esta vacia. \n";
		return;
	}
	else {
		listaPelicula listaOrdenada;
		nodoPelicula* aux = getPCab();
		do {
			nodoPelicula* temp = listaOrdenada.getPCab();
			nodoPelicula* prev = NULL;
			while (temp && temp->getPelicula().getPAnnoEstreno() >= aux->getPelicula().getPAnnoEstreno()) {
				prev = temp;
				temp = temp->getPSgte();
			}
			nodoPelicula* newNode = new nodoPelicula(aux->getPelicula());
			if (prev) {
				prev->setPSgte(newNode);
				newNode->setPAnte(prev);
			}
			else {
				listaOrdenada.setPCab(newNode);
			}
			if (temp) {
				temp->setPAnte(newNode);
				newNode->setPSgte(temp);
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());

		// Print the sorted list
		nodoPelicula* aux2 = listaOrdenada.getPCab();
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		while (aux2 != NULL) {
			cout << aux2->getPelicula().getPCodigo() << " \t " << aux2->getPelicula().getPNombre() << " \t " << aux2->getPelicula().getPDirector()
				<< " \t " << aux2->getPelicula().getPCalificacion() << " \t\t " << aux2->getPelicula().getPSolicitudes()
				<< " \t\t\t " << aux2->getPelicula().getPAnnoEstreno() << " \t\t " << aux2->getPelicula().getPSinopsis() << "\n";
			aux2 = aux2->getPSgte();
		}
		cout << "\nFin de la lista \n";
	}
}

void listaPelicula::listarPeliculasHilera(string h){
	if (esVacia())
		std::cout << "\nLa lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "\nCodigo \t Nombre \t Anno Estreno\n";
		std::cout << "-----------------------------------------\n";
		do {
			if (aux->getPelicula().getPNombre().find(h) != std::string::npos){
				std::cout << aux->getPelicula().getPCodigo() << " \t " << aux->getPelicula().getPNombre() << " \t " << aux->getPelicula().getPAnnoEstreno() << "\n";
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	cout << "\nFin de la lista \n";
	}
}

void listaPelicula::listarPeliculasRango(int r1, int r2)
{
	if (esVacia())
		std::cout << "\nLa lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "\nCodigo \t Nombre \t Director \t Calificacion \t Cant. Solicitudes \t Anno Estreno \t Sinopsis\n";
		std::cout << "---------------------------------------------------------------------------------------------------------\n";
		do {
			if (r1 <= aux->getPelicula().getPAnnoEstreno() && aux->getPelicula().getPAnnoEstreno() <= r2) {
				std::cout << aux->getPelicula().getPCodigo() << " \t " << aux->getPelicula().getPNombre() << " \t " << aux->getPelicula().getPDirector()
					<< " \t " << aux->getPelicula().getPCalificacion() << " \t\t " << aux->getPelicula().getPSolicitudes()
					<< " \t\t\t " << aux->getPelicula().getPAnnoEstreno() << " \t\t " << aux->getPelicula().getPSinopsis() << "\n";
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	cout << "\nFin de la lista \n";
	}
}

void listaPelicula::listarPeliculasSolicitudInferior(int nSol)
{
	if (esVacia())
		std::cout << "\nLa lista esta vacia.";
	else {
		nodoPelicula* aux = getPCab();
		std::cout << "\nCodigo \t Nombre \t Anno Estreno\n";
		std::cout << "-----------------------------------------\n";
		do {
			if (aux->getPelicula().getPSolicitudes() < nSol) {
				std::cout << aux->getPelicula().getPCodigo() << " \t " << aux->getPelicula().getPNombre() << " \t " << aux->getPelicula().getPAnnoEstreno() << "\n";
			}
			aux = aux->getPSgte();
		} while (aux != getPCab());
	cout << "\nFin de la lista \n";
	}
}

bool listaPelicula::eliminarPeliculasSolicitudInferior(int nSol) {
	bool eliminada = false;
	bool peliEliminada = false;
	if (esVacia()) {
		cout << "La lista esta vacia. \n";
		return eliminada;
	}
	else {
		nodoPelicula* aux = getPCab();
		bool sigaEliminando = true;
		while (sigaEliminando) {
			if (aux->getPelicula().getPSolicitudes() >= nSol) {
				aux = aux->getPSgte();
				if (aux == getPCab()) {
					sigaEliminando = false;
				}
				continue;
			}
			else {
				while (aux->getPelicula().getPSolicitudes() < nSol) {
					peliEliminada = true;
					if (getLargo() == 1) {
						delete getPCab();
						setPCab(NULL);
						setLargo(0);
						cout << "\nPelicula eliminada!";
						eliminada = true;
						return eliminada;
					}
					else {
						if (aux == getPCab()) {
							setPCab(getPCab()->getPSgte());
						}
						aux->getPAnte()->setPSgte(aux->getPSgte());
						aux->getPSgte()->setPAnte(aux->getPAnte());
						nodoPelicula* temp = aux;
						aux = aux->getPSgte();
						delete temp;
						cout << "\nPelicula eliminada!";
						setLargo(getLargo() - 1);
						eliminada = true;
					}
				}
			}
			if (!peliEliminada) {
				sigaEliminando = false;
			}
			else {
				sigaEliminando = true;
			}
			if (aux == getPCab()) {
				sigaEliminando = false;
			}
		}
	} return eliminada;
}








