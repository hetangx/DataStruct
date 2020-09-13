#include <stdio.h>
#include <stdlib.h>
#include "link.h"


int main()
{
    List L = malloc(sizeof(Node));
    if (L)
        L->Next = NULL;
    List P = malloc(sizeof(Node));
    if (P)
        P->Next = NULL;
    int pArray[] = { 1,3,4,6 };
    int lArray[] = { 9,8,7,6,5,4,3,2,1 };
    for (int i = 3; i >= 0; i--)
        Insert(pArray[i], P, P);
    for (int i = 8; i >= 0; i--)
        Insert(lArray[i], L, L);

    Travel(P);
    Travel(L);
    PrintLots(L, P);
    return 0;
}
