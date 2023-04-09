#pragma once
#include <iostream>
#include<string>
using namespace std;

class Pelicula
{
private:
	int pCodigo;
	string pNombre;
	string pDirector;
	float pCalificacion;
	int pSolicitudes;
	int pAnnoEstreno;
	string pSinopsis;

public:
	Pelicula();
	Pelicula(int, string, string, float, int, int, string);

	int getPCodigo();
	void setPCodigo(int);

	string getPNombre();
	void setPNombre(string);

	string getPDirector();
	void setPDirector(string);

	float getPCalificacion();
	void setPCalificacion(float);

	int getPSolicitudes();
	void setPSolicitudes(int);

	int getPAnnoEstreno();
	void setPAnnoEstreno(int);

	string getPSinopsis();
	void setPSinopsis(string);

};

