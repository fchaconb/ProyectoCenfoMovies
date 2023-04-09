#include "nodoCategoria.h"

nodoCategoria::nodoCategoria()
{
	this->categoria = Categoria();
	this->cSgte = NULL;
}

nodoCategoria::nodoCategoria(Categoria pCategoria)
{
	this->categoria = pCategoria;
	this->cSgte = NULL;
}

void nodoCategoria::setCategoria(Categoria pCategoria)
{
	this->categoria = pCategoria;
}

Categoria nodoCategoria::getCategoria()
{
	return this->categoria;
}

void nodoCategoria::setCSgte(nodoCategoria* ptr)
{
	this->cSgte = ptr;
}

nodoCategoria* nodoCategoria::getCSgte()
{
	return this->cSgte;
}

