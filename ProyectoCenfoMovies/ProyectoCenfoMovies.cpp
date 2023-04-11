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
    int nSolicitudes;
    ////////////////////////////////////////////////

    //Declaracion de variables para la lista de categorias:
    string cNombre;
    int cCantPeli;

    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar pelicula ascendentemente" << endl;
        cout << "(2) Eliminar pelicula" << endl;
        cout << "(4) Listar peliculas por hilera" << endl;
        cout << "(5) Listar peliculas por un rango de años" << endl;
        cout << "(6) Listar peliculas con un menor número de solicitudes" << endl;
        cout << "(7) Eliminar peliculas con un menor número de solicitudes" << endl;
        cout << "(9) Listar peliculas ascendentemente por nombre" << endl;
        cout << "(10) Listar peliculas descendentemente por nombre" << endl;
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
        case 4: {
            cout << "Ingrese la palabra clave:" << endl;
            cin >> hilera;
            listaPeli->listarPeliculasHilera(hilera);
            break;
        }
        case 5: {
            cout << "Ingrese el primer año del rango:" << endl;
            cin >> rango1;
            cout << "Ingrese el ultimo año del rango:" << endl;
            cin >> rango2;
            listaPeli->listarPeliculasRango(rango1, rango2);
            break;
        }
        case 6: {
            cout << "Ingrese el núemro de solicitudes:" << endl;
            cin >> nSolicitudes;
            listaPeli->listarPeliculasSolicitudInferior(nSolicitudes);
            break;
        }
        case 7: {
            cout << "Ingrese el núemro de solicitudes:" << endl;
            cin >> nSolicitudes;
            listaPeli->eliminarPeliculasSolicitudInferior(nSolicitudes);
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
        case 17: {
            cout << "Ingrese los siguientes datos de la categoria" << endl;
            cout << "Nombre: ";
            cin >> cNombre;
            cout << "Número de peliculas: ";
            cin >> cCantPeli;
            Categoria newCategoria(cNombre);
            newCategoria.setCantPeliculas(cCantPeli);
            listaCat->agregarCategoria(newCategoria);
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
