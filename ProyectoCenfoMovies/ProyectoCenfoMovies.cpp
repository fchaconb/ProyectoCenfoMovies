// ProyectoCenfoMovies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

#include "listaPelicula.h"

using namespace std;

void menu() {
    listaPelicula* listaPeli = new listaPelicula();
    int opc = -1;
    int pCodigo;
    string pNombre;
    string pDirector;
    float pCalificacion;
    int pSolicitudes;
    int pAnnoEstreno;
    string pSinopsis;

    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar pelicula ascendentemente" << endl;
        cout << "(2) Listar peliculas ascendentemente por nombre" << endl;
        cout << "(3) Listar peliculas descendentemente por nombre" << endl;
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
            listaPeli->listarPeliculasNombreAsc();
            break;
        }
        case 3: {
            listaPeli->listarPeliculasNombreDesc();
            break;
        }
        case 0:
            cout << "Finalizando el programa... ";
            break;
        default:
            cout << "Opcion no v�lida..." << endl;
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
