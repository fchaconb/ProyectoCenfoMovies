#include "nodoPelicula.h"

nodoPelicula::nodoPelicula()
{
	this->pelicula = Pelicula();
	this->pSgte = NULL;
	this->pAnte = NULL;
}

nodoPelicula::nodoPelicula(Pelicula _pelicula)
{
	this->pelicula = _pelicula;
	this->pSgte = NULL;
	this->pAnte = NULL;
}

Pelicula nodoPelicula::getPelicula()
{
	return this->pelicula;
}

void nodoPelicula::setPelicula(Pelicula _pelicula)
{
	this->pelicula = _pelicula;
}

nodoPelicula* nodoPelicula::getPSgte()
{
	return this->pSgte;
}

void nodoPelicula::setPSgte(nodoPelicula* ptr)
{
	this->pSgte = ptr;
}

nodoPelicula* nodoPelicula::getPAnte()
{
	return this->pAnte;
}

void nodoPelicula::setPAnte(nodoPelicula* ptr)
{
	this->pAnte = ptr;
}
