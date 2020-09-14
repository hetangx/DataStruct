#include <stdio.h>
#include <stdlib.h>
#include "link.h"


int main()
{
    /*List L = malloc(sizeof(Node));
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
    PrintLots(L, P);*/



    /*验证以下两个函数
    void SwapWithNext(List L, Position BeforeP);
    List Intersect(List L1, List L2);*/
    List L1 = MakeEmpty(NULL);
    Position L1Pos = Header(L1);
    List L2 = MakeEmpty(NULL);
    Position L2Pos = Header(L2);
    
    int list[] = { 3,4,6 };
    int list2[] = { 2,4, 6};

    for (int i = 0; i < 3; i++)
    {  
        Insert(list[i], L1, L1Pos);
        L1Pos = Advance(L1Pos);
    }
    for (int i = 0; i < 3; i++)
    {
        Insert(list2[i], L2, L2Pos);
        L2Pos = Advance(L2Pos);
    }

    Travel(L1);
    Travel(L2);
    List L3 = Intersect(L1, L2);
    Travel(L3);
    return 0;
}
