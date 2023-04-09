#pragma once
#include <iostream>
#include<string>
using namespace std;

class Categoria
{
private:
	string nombre;
	int cantPeliculas;
public:
	Categoria();
	Categoria(string);

	void setNombre(string);
	string getNombre();
	void setCantPeliculas(int);
	int getCantPeliculas();

	bool esIgual(string);
};

