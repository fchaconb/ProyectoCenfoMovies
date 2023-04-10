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

	bool agregarPelicula(Pelicula);

	void listarPeliculasNombreAsc();
	void listarPeliculasNombreDesc();
	void listarPeliculasHilera(string);
	void listarPeliculasRango(int, int);
	void listarPeliculasSolicitudInferior(int);

	void eliminarPeliculasSolicitudInferior(int);
};

