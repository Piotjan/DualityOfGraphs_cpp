/** @file */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "struktury.h"
#include <iostream>
#include <string>

using namespace std;

/**Funkcja przypisuje wprowadzone w kosoli parametry plików i sprawdza ich poprawnoœæ
@param argc iloœæ przyjmowanych parametrów z konsoli
@param argv[] wartoœci parametrów
@param[in,out] input zmienna do zapisania nazwy pliku z danymi wejsciowymi
@param[in,out] output zmienna do zapisania nazwy pliku wyjœciowego
@result Funkcja zwraca TRUE w wypadku gdy wszystkie parametry zosta³y podane poprawnie, a pliki istniej¹, w przeciwnym wypadku zwraca FALSE
*/
bool controlling(int argc, char* argv[], string& input, string& output);

/**Funkcja tworzy listê jednokierunkow¹ z³o¿on¹ z wêz³ów grafu, dane pobierane s¹ z plku wejœciowego
@param[in,out] pHead adres pierwszego elementu listy wêz³ow
@param input nazwa pliku z danym wejœciowymi
@return Funkcja zwraca FALSE, jeœli plik wejœciowy jest uszkodzony, TRUE je¿eli wczytanie danych przebieg³o pomyœlnie
*/
bool download(wezel*& pHead, string input);

/**Funkcja sprawdza, czy wêze³ o wartoœci sczytanej z pliku ju¿ istnieje
@param pHead adres pierwszego elementu listy wêz³ów
@param szukana wartosc szukanego wêz³a
@return adres wêz³a o szukanej wartoœci
*/
wezel* findWezel(wezel* pHead, int szukana);

/**Funkcja sprawdza, czy z aktualnego wêz³a istniej juz krawêdŸ do wêz³a s¹siaduj¹cego
@param pHead adres pierwszego elementu listy krawêdzi
@param szukana wartoœæ wêz³a, do ktorego po³¹czenie jest sprawdzane
@return adres krawêdzi
*/
krawedz* findKrawedz(krawedz* pHead, int szukana);

/**Funkcja dodaje krawêdŸ, do aktualnego wêz³a
@param pHead adres pierwszego elementu listy krawêdzi
@param a wartoœæ wêz³a, do którego krawêdŸ wchodzi
@return adres nowo powsta³ej krawêdzi
*/
krawedz* addKrawedz(krawedz* pHead, int a);

/**Funkcja rekurencyjnie usuwa listê wêz³ów z pamiêci
@param[in,out] pHead adres pierwszego elementu listy wêz³ow
*/
void deleteGraph(wezel*& pHead);

/**Funkcja rekurencyjnie usuwa listê krawêdzi dla danego wêz³a z pamiêci
@param[in,out] pHead adres pierwszego elementu listy krawêdzi
*/
void deleteKrawedz(krawedz*& pHead);

/**Funkcja wypisuje do pliku graf (wêz³y oraz ich s¹siadów)
@param pHead adres pierwszego elementu listy wêz³ów
@param nazwa pliku wyjœciowego
*/
void printGraph(wezel* pHead, string output);

/**Funkcja dodaje dok ka¿dej krawêdzi adres wêz³a, do którego dana krawêdŸ wchodzi
@param pHead adres pierwszego elementu listy wêz³ów
*/
void assignNeigh(wezel* pHead);

/**Funkcja sprawdza, czy graf jest dwudzielny
@param pHead adres pierwszego elementu listy wêz³ów
@return w wypadku dwudzielnoœci funkcja zwraca TRUE, w przeciwnym wypadku FALSE
*/
bool coloring(wezel* pHead);

/**Funkcja sprawdza, czy dla danego zakolorowanie wêz³a i jego s¹siadów mo¿e wyst¹piæ dwudzielnoœæ ca³ego grafu
@param pHead adres pierwszego elementu listy krawêdzi
@param current kolor wêz³a, dla którego wykonywana jest funkcja
@return w wypadku nie przecz¹cym dwudzielnoœci zwraca TRUE, w przeciwnym wypadku FALSE
*/
bool ifPossible(krawedz* pHead, kolor current);

/**Funkcja nadaje kolory s¹siednim wêz³om
@param pHead adres pierwszego elementu listy krawêdzi
@param current kolor wêz³a, dla ktorego wykonywana jest funkcja
*/
void makeColors(krawedz* pHead, kolor current);

/**Funkcja sprawdza, czy dla wszystkich wêz³ów zosta³a wykonana funkcja coloring
@param pHead adres pierwszego elementu listy wêz³ów
@return w wypadku wykonania funkcji coloring dla wszystkich wê³ów zwraca TRUE, w przeciwnym wypadku FALSE
*/
bool checkOut(wezel* pHead);

/**Funkcje, w wypadku dwudzielnoœci grafu, wypisuje do pliku informacjê o dwudzielnoœci oraz wartoœci wêz³ów dla obu grup
@param pHead adres pierwszego elementu listy wêz³ów
@param output nazwa pliku wyjœciowego
*/
void printByColor(wezel* pHead, string output);

#endif