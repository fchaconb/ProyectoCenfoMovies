// ProyectoCenfoMovies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "listaPelicula.h"
#include "listaCategoria.h"

using namespace std;

void menu() {
    //Declaracion de las listas
    listaPelicula* listaPeli = new listaPelicula();
    listaCategoria* listaCat = new listaCategoria();
    int opc = -1;
    ////////////////////////////////////////////////

    //Declaracion de variables para la lista de peliculas:
    int pCodigo;
    string pNombre;
    string pDirector;
    float pCalificacion;
    int pSolicitudes;
    int pAnnoEstreno;
    string pSinopsis;
    string hilera;
    int rango1;
    int rango2;

    string pNewDato;

    //Declaracion de variables para la lista de categorias:
    string cNombre;
    int cCantPeli;
    ////////////////////////////////////////////////

    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar pelicula ascendentemente" << endl;
        cout << "(2) Eliminar pelicula" << endl;
        cout << "(3) Consultar informacion de una pelicula" << endl;
        cout << "(4) Modificar nombre de una pelicula" << endl;
        cout << "(5) Modificar director de una pelicula" << endl;
        cout << "(9) Listar peliculas ascendentemente por nombre" << endl;
        cout << "(10) Listar peliculas descendentemente por nombre" << endl;
        cout << "(13) Listar peliculas por hilera" << endl;
        cout << "(14) Listar peliculas por un rango de annos" << endl;
        cout << "(15) Listar peliculas con un menor numero de solicitudes" << endl;
        cout << "(16) Eliminar peliculas con un menor numero de solicitudes" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada -> ";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
        case 1: {
            cout << "Ingrese los siguientes datos de la pelicula" << endl;
            cout << "Codigo: ";
            cin >> pCodigo;
            cout << "Nombre de la pelicula: ";
            cin >> pNombre;
            cout << "Director: ";
            cin >> pDirector;
            cout << "Calificacion: ";
            cin >> pCalificacion;
            cout << "Cantidad de solicitudes: ";
            cin >> pSolicitudes;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Sinopsis: ";
            cin >> pSinopsis;
            Pelicula newPelicula(pCodigo, pNombre, pDirector, pCalificacion, pSolicitudes, pAnnoEstreno, pSinopsis);
            listaPeli->agregarPelicula(newPelicula);
            break;
        }
        case 2: {
            cout << "Ingrese los siguientes datos de la pelicula a eliminar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            listaPeli->eliminarPelicula(pNombre, pAnnoEstreno);    
            break;
        }
        case 3: {
            cout << "Ingrese los siguientes datos de la pelicula a consultar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            listaPeli->consultarPelicula(pNombre, pAnnoEstreno);
            break;
        }
        case 4: {
            cout << "Ingrese los siguientes datos de la pelicula a modificar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Nuevo nombre: ";
            cin >> pNewDato;
            listaPeli->modificarNombre(pNombre, pAnnoEstreno, pNewDato);
            break;
        }
        case 5: {
            cout << "Ingrese los siguientes datos de la pelicula a modificar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Nuevo director: ";
            cin >> pNewDato;
            listaPeli->modificarNombre(pNombre, pAnnoEstreno, pNewDato);
            break;
        }
        case 9: {
            listaPeli->listarPeliculasNombreAsc();
            break;
        }
        case 10: {
            listaPeli->listarPeliculasNombreDesc();
            break;
        }
        case 13: {
            cout << "Ingrese la palabra clave: ";
            cin >> hilera;
            listaPeli->listarPeliculasHilera(hilera);
            break;
        }
        case 14: {
            cout << "Ingrese el primer anno del rango: ";
            cin >> rango1;
            cout << "Ingrese el ultimo anno del rango: ";
            cin >> rango2;
            listaPeli->listarPeliculasRango(rango1, rango2);
            break;
        }
        case 15: {
            cout << "Ingrese el numero de solicitudes: ";
            cin >> pSolicitudes;
            listaPeli->listarPeliculasSolicitudInferior(pSolicitudes);
            break;
        }
        case 16: {
            cout << "Ingrese el numero de solicitudes: ";
            cin >> pSolicitudes;
            listaPeli->eliminarPeliculasSolicitudInferior(pSolicitudes);
            break;
        }
        case 17: {
            cout << "Ingrese los siguientes datos de la categoria" << endl;
            cout << "Nombre: ";
            cin >> cNombre;
            cout << "Número de peliculas: ";
            cin >> cCantPeli;
            Categoria newCategoria(cNombre);
            newCategoria.setCantPeliculas(cCantPeli);
            if (listaCat->agregarCategoria(newCategoria)){
                cout << "Se ha agregado la categoria correctamente!";
            }else {
                cout << "No se ha podido agregar la categoria!";
            }
            
            break;
        }
        case 18: {
            cout << "Escriba el nombre de la categoria que desea eliminar:" << endl;
            cin >> cNombre;
            if (listaCat->eliminarCategoria(cNombre)) {
                cout << "Se ha eliminado la categoria correctamente!";
            }else {
                cout << "No se ha podido eliminar la categoria!";
            }
            break;
        }
        case 19: {
            listaCat->listarCategorias();
            break;
        }
        case 20: {
            cout << "Escriba el nombre de la categoria que desea consultar: " << endl;
            cin >> cNombre;
            listaCat->consultarLista(cNombre);
            break;
        }
        case 0:
            cout << "Finalizando el programa... ";
            break;
        default:
            cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }


}

int main()
{
    menu();
}
