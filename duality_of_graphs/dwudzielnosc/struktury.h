/**@file*/

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream>

using namespace std;

/**Typ reprezentuj�cy grup� dwudzielno�ci, do kt�rej nale�� poszczeg�lne w�z�y grafu.*/
enum kolor
{
    white,  ///< grupa neutralna, przydzielana od razu po utworzeniu w�z�a
    red,    ///< grupa "czerwona"
    green   ///< grupa "zielona"
};

struct krawedz;

/**W�ze� grafu.*/
struct wezel
{
    int wartosc;    ///< warto�� w�z�a
    kolor grupa;    ///< kolor grupy, do kt�rej nale�y w�ze�
    krawedz* pNeighbour;    ///< wska�nik na list� kraw�dzi wychodz�cych z w�z�a
    wezel* pNext; ///< wska�nik na nast�pny w�ze� w li�cie
    int done; ///< parametr, okre�laj�cy czy dla danego w�z�a zosta�a wykonana funkcja coloring
};

/**Kraw�d� grafu.*/
struct krawedz
{
    int wyjscie;    ///< warto�� w�z�a, do kt�rego wchodzi podana kraw�d�
    wezel* pNeighbour;  ///< wska�nik na w�ze�, do kt�rego wchodzi podana kraw�d�
    krawedz* pNext; ///< wska�nik na nast�pn� kraw�d� w li�cie
};

#endif