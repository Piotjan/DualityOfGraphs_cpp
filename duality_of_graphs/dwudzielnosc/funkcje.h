/** @file */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "struktury.h"
#include <iostream>
#include <string>

using namespace std;

/**Funkcja przypisuje wprowadzone w kosoli parametry plik�w i sprawdza ich poprawno��
@param argc ilo�� przyjmowanych parametr�w z konsoli
@param argv[] warto�ci parametr�w
@param[in,out] input zmienna do zapisania nazwy pliku z danymi wejsciowymi
@param[in,out] output zmienna do zapisania nazwy pliku wyj�ciowego
@result Funkcja zwraca TRUE w wypadku gdy wszystkie parametry zosta�y podane poprawnie, a pliki istniej�, w przeciwnym wypadku zwraca FALSE
*/
bool controlling(int argc, char* argv[], string& input, string& output);

/**Funkcja tworzy list� jednokierunkow� z�o�on� z w�z��w grafu, dane pobierane s� z plku wej�ciowego
@param[in,out] pHead adres pierwszego elementu listy w�z�ow
@param input nazwa pliku z danym wej�ciowymi
@return Funkcja zwraca FALSE, je�li plik wej�ciowy jest uszkodzony, TRUE je�eli wczytanie danych przebieg�o pomy�lnie
*/
bool download(wezel*& pHead, string input);

/**Funkcja sprawdza, czy w�ze� o warto�ci sczytanej z pliku ju� istnieje
@param pHead adres pierwszego elementu listy w�z��w
@param szukana wartosc szukanego w�z�a
@return adres w�z�a o szukanej warto�ci
*/
wezel* findWezel(wezel* pHead, int szukana);

/**Funkcja sprawdza, czy z aktualnego w�z�a istniej juz kraw�d� do w�z�a s�siaduj�cego
@param pHead adres pierwszego elementu listy kraw�dzi
@param szukana warto�� w�z�a, do ktorego po��czenie jest sprawdzane
@return adres kraw�dzi
*/
krawedz* findKrawedz(krawedz* pHead, int szukana);

/**Funkcja dodaje kraw�d�, do aktualnego w�z�a
@param pHead adres pierwszego elementu listy kraw�dzi
@param a warto�� w�z�a, do kt�rego kraw�d� wchodzi
@return adres nowo powsta�ej kraw�dzi
*/
krawedz* addKrawedz(krawedz* pHead, int a);

/**Funkcja rekurencyjnie usuwa list� w�z��w z pami�ci
@param[in,out] pHead adres pierwszego elementu listy w�z�ow
*/
void deleteGraph(wezel*& pHead);

/**Funkcja rekurencyjnie usuwa list� kraw�dzi dla danego w�z�a z pami�ci
@param[in,out] pHead adres pierwszego elementu listy kraw�dzi
*/
void deleteKrawedz(krawedz*& pHead);

/**Funkcja wypisuje do pliku graf (w�z�y oraz ich s�siad�w)
@param pHead adres pierwszego elementu listy w�z��w
@param nazwa pliku wyj�ciowego
*/
void printGraph(wezel* pHead, string output);

/**Funkcja dodaje dok ka�dej kraw�dzi adres w�z�a, do kt�rego dana kraw�d� wchodzi
@param pHead adres pierwszego elementu listy w�z��w
*/
void assignNeigh(wezel* pHead);

/**Funkcja sprawdza, czy graf jest dwudzielny
@param pHead adres pierwszego elementu listy w�z��w
@return w wypadku dwudzielno�ci funkcja zwraca TRUE, w przeciwnym wypadku FALSE
*/
bool coloring(wezel* pHead);

/**Funkcja sprawdza, czy dla danego zakolorowanie w�z�a i jego s�siad�w mo�e wyst�pi� dwudzielno�� ca�ego grafu
@param pHead adres pierwszego elementu listy kraw�dzi
@param current kolor w�z�a, dla kt�rego wykonywana jest funkcja
@return w wypadku nie przecz�cym dwudzielno�ci zwraca TRUE, w przeciwnym wypadku FALSE
*/
bool ifPossible(krawedz* pHead, kolor current);

/**Funkcja nadaje kolory s�siednim w�z�om
@param pHead adres pierwszego elementu listy kraw�dzi
@param current kolor w�z�a, dla ktorego wykonywana jest funkcja
*/
void makeColors(krawedz* pHead, kolor current);

/**Funkcja sprawdza, czy dla wszystkich w�z��w zosta�a wykonana funkcja coloring
@param pHead adres pierwszego elementu listy w�z��w
@return w wypadku wykonania funkcji coloring dla wszystkich w��w zwraca TRUE, w przeciwnym wypadku FALSE
*/
bool checkOut(wezel* pHead);

/**Funkcje, w wypadku dwudzielno�ci grafu, wypisuje do pliku informacj� o dwudzielno�ci oraz warto�ci w�z��w dla obu grup
@param pHead adres pierwszego elementu listy w�z��w
@param output nazwa pliku wyj�ciowego
*/
void printByColor(wezel* pHead, string output);

#endif