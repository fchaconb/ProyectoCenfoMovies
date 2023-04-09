#include "Categoria.h"

Categoria::Categoria()
{
	this->nombre = " ";
	this->cantPeliculas = 0;
}

Categoria::Categoria(string pNombre)
{
	this->nombre = pNombre;
	this->cantPeliculas = 0;
}

void Categoria::setNombre(string pNombre)
{
	this->nombre = pNombre;
}

string Categoria::getNombre()
{
	return this->nombre;
}

void Categoria::setCantPeliculas(int pCantPeliculas)
{
	this->cantPeliculas = pCantPeliculas;
}

int Categoria::getCantPeliculas()
{
	return this->cantPeliculas;
}

bool Categoria::esIgual(string c)
{
	return this->getNombre() == c;
}
