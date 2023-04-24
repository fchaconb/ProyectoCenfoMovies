#pragma once
#include <stdlib.h>
#include <iostream>
#include "nodoPelicula.h"

class listaPelicula
{
private:
	nodoPelicula* pCab;
	int largo;

public:
	listaPelicula();
	~listaPelicula();

	nodoPelicula* getPCab();
	void setPCab(nodoPelicula*);

	int getLargo();
	void setLargo(int);

	bool esVacia();
	nodoPelicula* dirNodo(int);

	bool agregarPelicula(Pelicula);
	bool eliminarPelicula(int);
	bool consultarPelicula(int);

	bool modificarNombre(int, string);
	bool modificarDirector(int, string);
	bool modificarCalificacion(int, float);
	bool modificarSolicitudes(int, int);
	bool modificarAnnoEstreno(int, int);
	bool modificarSinopsis(int, string);

	void listarPeliculasCodigoAsc();
	void listarPeliculasCodigoDesc();

	void listarPeliculasNombreAsc();
	void listarPeliculasNombreDesc();

	void listarPeliculasAnnoAsc();
	void listarPeliculasAnnoDesc();

	void listarPeliculasHilera(string);
	void listarPeliculasRango(int, int);
	void listarPeliculasSolicitudInferior(int);

	bool eliminarPeliculasSolicitudInferior(int);
};

