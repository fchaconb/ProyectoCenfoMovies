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

    string pNewDatoString;
    int pNewDatoInt;
    float pNewDatoFloat;

    //Declaracion de variables para la lista de categorias:
    string cNombre;
    int cCantPeli;
    ////////////////////////////////////////////////

    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              PELICULAS" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar pelicula" << endl;
        cout << "(2) Eliminar pelicula" << endl;
        cout << "(3) Consultar informacion de una pelicula" << endl;
        cout << "(4) Modificar nombre de una pelicula" << endl;
        cout << "(5) Modificar director de una pelicula" << endl;
        cout << "(6) Modificar calificacion de una pelicula" << endl;
        cout << "(7) Modificar cantidad de solicitudes de una pelicula" << endl;
        cout << "(8) Modificar anno de estreno de una pelicula" << endl;
        cout << "(9) Modificar sinopsis de una pelicula" << endl;
        cout << "(10) Listar peliculas ascendentemente por nombre" << endl;
        cout << "(11) Listar peliculas descendentemente por nombre" << endl;
        cout << "(12) Listar peliculas ascendentemente por anno" << endl;
        cout << "(13) Listar peliculas descendentemente por anno" << endl;
        cout << "(14) Listar peliculas por hilera" << endl;
        cout << "(15) Listar peliculas por un rango de annos" << endl;
        cout << "(16) Listar peliculas con un menor numero de solicitudes" << endl;
        cout << "(17) Eliminar peliculas con un menor numero de solicitudes" << endl;
        cout << "" << endl;
        cout << "----------------------------------" << endl;
        cout << "              CATEGORIAS" << endl;
        cout << "----------------------------------" << endl;
        cout << "(18) Agregar categoria" << endl;
        cout << "(19) Eliminar categoria" << endl;
        cout << "(20) Listar categorias" << endl;
        cout << "(21) Consultar categoria" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada -> ";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {

        //Funciones de la lista de Peliculas. 
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
            cin >> pNewDatoString;
            listaPeli->modificarNombre(pNombre, pAnnoEstreno, pNewDatoString);
            break;
        }
        case 5: {
            cout << "Ingrese los siguientes datos de la pelicula a modificar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Nuevo director: ";
            cin >> pNewDatoString;
            listaPeli->modificarDirector(pNombre, pAnnoEstreno, pNewDatoString);
            break;
        }
        case 6: {
            cout << "Ingrese los siguientes datos de la pelicula a modificar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Nueva calificacion: ";
            cin >> pNewDatoFloat;
            listaPeli->modificarCalificacion(pNombre, pAnnoEstreno, pNewDatoFloat);
            break;
        }
        case 7: {
            cout << "Ingrese los siguientes datos de la pelicula a modificar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Nueva cantidad de solicitudes: ";
            cin >> pNewDatoInt;
            listaPeli->modificarSolicitudes(pNombre, pAnnoEstreno, pNewDatoInt);
            break;
        }
        case 8: {
            cout << "Ingrese los siguientes datos de la pelicula a modificar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Nuevo anno de estreno: ";
            cin >> pNewDatoInt;
            listaPeli->modificarAnnoEstreno(pNombre, pAnnoEstreno, pNewDatoInt);
            break;
        }
        case 9: {
            cout << "Ingrese los siguientes datos de la pelicula a modificar" << endl;
            cout << "Nombre: ";
            cin >> pNombre;
            cout << "Anno de estreno: ";
            cin >> pAnnoEstreno;
            cout << "Nueva sinopsis: ";
            cin >> pNewDatoString;
            listaPeli->modificarSinopsis(pNombre, pAnnoEstreno, pNewDatoString);
            break;
        }
        case 10: {
            listaPeli->listarPeliculasNombreAsc();
            break;
        }
        case 11: {
            listaPeli->listarPeliculasNombreDesc();
            break;
        }
        case 12: {
            listaPeli->listarPeliculasAnnoAsc();
            break;
        }
        case 13: {
            listaPeli->listarPeliculasAnnoDesc();
            break;
        }
        case 14: {
            cout << "Ingrese la palabra clave: ";
            cin >> hilera;
            listaPeli->listarPeliculasHilera(hilera);
            break;
        }
        case 15: {
            cout << "Ingrese el primer anno del rango: ";
            cin >> rango1;
            cout << "Ingrese el ultimo anno del rango: ";
            cin >> rango2;
            listaPeli->listarPeliculasRango(rango1, rango2);
            break;
        }
        case 16: {
            cout << "Ingrese el numero de solicitudes: ";
            cin >> pSolicitudes;
            listaPeli->listarPeliculasSolicitudInferior(pSolicitudes);
            break;
        }
        case 17: {
            cout << "Ingrese el numero de solicitudes: ";
            cin >> pSolicitudes;
            listaPeli->eliminarPeliculasSolicitudInferior(pSolicitudes);
            break;
        }
        
        //Funciones de la lista de Categorias. 
        case 18: {
            cout << "Ingrese los siguientes datos de la categoria" << endl;
            cout << "Nombre: ";
            cin >> cNombre;
            cout << "Numero de peliculas: ";
            cin >> cCantPeli;
            Categoria newCategoria(cNombre);
            newCategoria.setCantPeliculas(cCantPeli);
            if (listaCat->agregarCategoria(newCategoria)) {
                cout << "\nCategoria agregada a la lista!";
            }
            else {
                cout << "\nLa categoria no fue agregada a la lista.";
            }
            break;
        }
        case 19: {
            cout << "Escriba el nombre de la categoria que desea eliminar: ";
            cin >> cNombre;
            if (listaCat->eliminarCategoria(cNombre)) {
                cout << "\nSe ha eliminado la categoria correctamente!";
            }else {
                cout << "\nNo se ha podido eliminar la categoria!";
            }
            break;
        }
        case 20: {
            listaCat->listarCategorias();
            break;
        }
        case 21: {
            cout << "Escriba el nombre de la categoria que desea consultar: ";
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
