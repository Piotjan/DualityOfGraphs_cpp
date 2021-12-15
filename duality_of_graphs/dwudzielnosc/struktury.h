/**@file*/

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream>

using namespace std;

/**Typ reprezentuj¹cy grupê dwudzielnoœci, do której nale¿¹ poszczególne wêz³y grafu.*/
enum kolor
{
    white,  ///< grupa neutralna, przydzielana od razu po utworzeniu wêz³a
    red,    ///< grupa "czerwona"
    green   ///< grupa "zielona"
};

struct krawedz;

/**Wêze³ grafu.*/
struct wezel
{
    int wartosc;    ///< wartoœæ wêz³a
    kolor grupa;    ///< kolor grupy, do której nale¿y wêze³
    krawedz* pNeighbour;    ///< wskaŸnik na listê krawêdzi wychodz¹cych z wêz³a
    wezel* pNext; ///< wska¿nik na nastêpny wêze³ w liœcie
    int done; ///< parametr, okreœlaj¹cy czy dla danego wêz³a zosta³a wykonana funkcja coloring
};

/**KrawêdŸ grafu.*/
struct krawedz
{
    int wyjscie;    ///< wartoœæ wêz³a, do którego wchodzi podana krawêdŸ
    wezel* pNeighbour;  ///< wskaŸnik na wêze³, do którego wchodzi podana krawêdŸ
    krawedz* pNext; ///< wskaŸnik na nastêpn¹ krawêdŸ w liœcie
};

#endif