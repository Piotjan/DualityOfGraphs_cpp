#include <iostream>
#include <string>
#include <cstring>

#include "funkcje.h"
#include "struktury.h"

using namespace std;

int main(int argc, char* argv[])
{
    string input, output;

    if (!controlling(argc, argv, input, output))
        return 1; 

    wezel* pHead = nullptr;

    if (!download(pHead, input))
        return 1;

    if (pHead)
    {
        assignNeigh(pHead);
        printGraph(pHead, output);
        if (coloring(pHead))
            printByColor(pHead, output);
        deleteGraph(pHead);
    }

    return 0;
}