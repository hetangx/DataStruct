#include <stdio.h>
#include <stdlib.h>
#include "dlink.h"

void DeleteList(List L);

List MakeEmpty(List L);


int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

void Travel(List L);
void PrintLots(List L, List P);