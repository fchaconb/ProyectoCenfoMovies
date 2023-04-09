#pragma once
#include "Pelicula.h"

class nodoPelicula
{
private:
	Pelicula pelicula;
	nodoPelicula* pSgte;
	nodoPelicula* pAnte;

public:
	nodoPelicula();
	nodoPelicula(Pelicula);

	Pelicula getPelicula();
	void setPelicula(Pelicula);

	nodoPelicula* getPSgte();
	void setPSgte(nodoPelicula*);

	nodoPelicula* getPAnte();
	void setPAnte(nodoPelicula*);
};

