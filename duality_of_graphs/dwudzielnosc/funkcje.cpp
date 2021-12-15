#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "funkcje.h"
#include "struktury.h"

using namespace std;

bool controlling(int argc, char* argv[], string& input, string& output)
{
    if (argc < 4)
    {
        cerr << "Prawidlowa komenda: " << argv[0] << " -i/-o [nazwa pliku] -i/-o [nazwa pliku]" << endl;
        return false;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            i++;
            if (i < argc)
                input.assign(argv[i]);
        }
        else if (strcmp(argv[i], "-o") == 0)
        {
            i++;
            if (i < argc)
                output.assign(argv[i]);
        }
        else
        {
            cerr << "Prawid³owa komenda: " << argv[0] << " -i/-o [nazwa pliku] -i/-o [nazwa pliku]" << endl;
            return false;
        }
    }
    if (input.size() == 0 || output.size() == 0)
    {
        cerr << "Podano dwa razy plik wejsciowy/wyjsciowy." << endl;
        return false;
    }

    fstream file;
    file.open(input);
    if (!file)
    {
        cerr << "Podany plik wejsciowy nie istnieje!" << endl;
        file.close();
        return false;
    }
    file.close();
    return true;
}

wezel* findWezel(wezel* pHead, int szukana)
{
    while (pHead)
    {
        if (pHead->wartosc == szukana)
            return pHead;
        else
            pHead = pHead->pNext;
    }
    return nullptr;
}

krawedz* findKrawedz(krawedz* pHead, int szukana)
{
    while (pHead)
    {
        if (pHead->wyjscie == szukana)
            return pHead;
        else
            pHead = pHead->pNext;
    }
    return nullptr;
}

krawedz* addKrawedz(krawedz* pHead, int a)
{
    pHead = new krawedz{ a,nullptr,pHead };
    return pHead;
}

bool download(wezel*& pHead, string input)
{
    ifstream file;
    file.open(input);

    if (file)
    {
        int a, b;
        while (file >> a >> b)
        {
            if (a != b)
            {
                auto p = findWezel(pHead, a);
                if (p == nullptr)
                {
                    pHead = new wezel{ a,white,addKrawedz(nullptr,b),pHead,0 };
                }
                else
                {
                    auto q = findKrawedz(p->pNeighbour, b);
                    if (q == nullptr)
                    {
                        p->pNeighbour = addKrawedz(p->pNeighbour, b);
                    }
                }

                p = findWezel(pHead, b);
                if (p == nullptr)
                {
                    pHead = new wezel{ b,white,addKrawedz(nullptr,a),pHead,0 };
                }
                else
                {
                    auto q = findKrawedz(p->pNeighbour, a);
                    if (q == nullptr)
                    {
                        p->pNeighbour = addKrawedz(p->pNeighbour, a);
                    }
                }
            }
            else
            {
                cout << "Plik wejsciowy nie moze zawierac samych wierzcholkow." << endl;
                file.close();
                return false;
            }
        }
    }
    file.close();
    return true;
}

void deleteKrawedz(krawedz*& pHead)
{
    if (pHead)
    {
        deleteKrawedz(pHead->pNext);
        delete pHead;
        pHead = nullptr;
    }
}

void deleteGraph(wezel*& pHead)
{
    if (pHead)
    {
        deleteGraph(pHead->pNext);
        deleteKrawedz(pHead->pNeighbour);
        delete pHead;
        pHead = nullptr;
    }
}


void printGraph(wezel* pHead, string output)
{
    ofstream file;
    file.open(output);
    while (pHead)
    {
        file << pHead->wartosc << endl;
        krawedz* p = pHead->pNeighbour;
        while (p)
        {
            file << p->wyjscie << " ";
            p = p->pNext;
        }
        file << endl << endl;
        pHead = pHead->pNext;
    }
}

void assignNeigh(wezel* pHead)
{
    wezel* poczatek = pHead;
    while (pHead)
    {
        krawedz* p = pHead->pNeighbour;
        while (p)
        {
            p->pNeighbour = findWezel(poczatek, p->wyjscie);
            p = p->pNext;
        }
        pHead = pHead->pNext;
    }
}


bool ifPossible(krawedz* pHead, kolor current)
{
    while (pHead)
    {
        wezel* q = pHead->pNeighbour;

        if (q->grupa == current)
            return false;
        pHead = pHead->pNext;
    }
    return true;
}

void makeColors(krawedz* pHead, kolor current)
{
    while (pHead)
    {
        wezel* q = pHead->pNeighbour;

        if (current == red)
        {
            q->grupa = green;
        }
        else
        {
            q->grupa = red;
        }
        pHead = pHead->pNext;
    }
}

bool checkOut(wezel* pHead)
{
    while (pHead)
    {
        if (pHead->done == 0)
            return false;
        else
            pHead = pHead->pNext;
    }
    return true;
}

bool coloring (wezel* pHead)
{
    wezel* start = pHead;
    bool colors = false;
    bool gotowosc = false;
    while (!gotowosc)
    {
        if (colors == false)
        {
            pHead = start;
            while (pHead)
            {
                if (pHead->done == 0 && colors == false)
                {
                    pHead->grupa = red;
                    makeColors(pHead->pNeighbour, pHead->grupa);
                    colors = true;
                    pHead->done = 1;
                }
                pHead = pHead->pNext;
            }
        }

        pHead = start;
        colors = false;
        while (pHead)
        {
            if (pHead->done == 0 && pHead->grupa != white)
            {
                if (ifPossible(pHead->pNeighbour, pHead->grupa))
                {
                    makeColors(pHead->pNeighbour, pHead->grupa);
                    colors = true;
                    pHead->done = 1;
                }
                else
                {
                    return false;
                }
            }
            pHead = pHead->pNext;
        }
        gotowosc = checkOut(start);
    }
    return true;
}

void printByColor(wezel* pHead, string output)
{
    ofstream file;
    file.open(output, ios::out | ios::app);
    wezel* start = pHead;
    file << "Graf jest dwudzielny" << endl;

    file << "Grupa pierwsza:" << endl;
    while (pHead)
    {
        if (pHead->grupa == red)
            file << pHead->wartosc << " ";
        pHead = pHead->pNext;
    }
    
    pHead = start;
    file << endl << endl << "Grupa druga:" << endl;
    while (pHead)
    {
        if (pHead->grupa == green)
            file << pHead->wartosc << " ";
        pHead = pHead->pNext;
    }
    file.close();
}