#include "Pelicula.h"

Pelicula::Pelicula()
{
	this->pCodigo = 0;
	this->pNombre = " ";
	this->pDirector = " ";
	this->pCalificacion = 0;
	this->pSolicitudes = 0;
	this->pAnnoEstreno = 0;
	this->pSinopsis = " ";
}

Pelicula::Pelicula(int _pCodigo, string _pNombre, string _pDirector, float _pCalificacion, int _pSolicitudes, int _pAnnoEstreno, string _pSinopsis)
{
	this->pCodigo = _pCodigo;
	this->pNombre = _pNombre;
	this->pDirector = _pDirector;
	this->pCalificacion = _pCalificacion;
	this->pSolicitudes = _pSolicitudes;
	this->pAnnoEstreno = _pAnnoEstreno;
	this->pSinopsis = _pSinopsis;
}

int Pelicula::getPCodigo()
{
	return this->pCodigo;
}

void Pelicula::setPCodigo(int _pCodigo)
{
	this->pCodigo = _pCodigo;
}

string Pelicula::getPNombre()
{
	return this->pNombre;
}

void Pelicula::setPNombre(string _pNombre)
{
	this->pNombre = _pNombre;
}

string Pelicula::getPDirector()
{
	return this->pDirector;
}

void Pelicula::setPDirector(string _pDirector)
{
	this->pDirector = _pDirector;
}

float Pelicula::getPCalificacion()
{
	return this->pCalificacion;
}

void Pelicula::setPCalificacion(float _pCalificacion)
{
	this->pCalificacion = _pCalificacion;
}

int Pelicula::getPSolicitudes()
{
	return this->pSolicitudes;
}

void Pelicula::setPSolicitudes(int _pSolicitudes)
{
	this->pSolicitudes = _pSolicitudes;
}

int Pelicula::getPAnnoEstreno()
{
	return this->pAnnoEstreno;
}

void Pelicula::setPAnnoEstreno(int _pAnnoEstreno)
{
	this->pAnnoEstreno = _pAnnoEstreno;
}

string Pelicula::getPSinopsis()
{
	return this->pSinopsis;
}

void Pelicula::setPSinopsis(string _pSinopsis)
{
	this->pSinopsis = _pSinopsis;
}
