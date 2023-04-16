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
	nodoPelicula* dirNodo(string, int);

	bool agregarPelicula(Pelicula);
	bool eliminarPelicula(string, int);
	bool consultarPelicula(string, int);

	bool modificarNombre(string, int, string);
	bool modificarDirector(string, int, string);
	bool modificarCalificacion(string, int, float);
	bool modificarSolicitudes(string, int, int);
	bool modificarAnnoEstreno(string, int, int);
	bool modificarSinopsis(string, int, string);

	void listarPeliculasNombreAsc();
	void listarPeliculasNombreDesc();

	void listarPeliculasAnnoAsc();
	void ordenarPeliculasAnnoAsc();
	void listarPeliculas();
	void listarPeliculasAnnoDesc();

	void listarPeliculasHilera(string);
	void listarPeliculasRango(int, int);
	void listarPeliculasSolicitudInferior(int);

	bool eliminarPeliculasSolicitudInferior(int);
};

