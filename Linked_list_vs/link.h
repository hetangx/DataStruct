#ifndef _LIST_H
#define _LIST_H
typedef int ElementType;
typedef struct __Node
{
	ElementType Element;
	struct __Node *Next;
}Node;

typedef struct __Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void DeleteList(List L);
List MakeEmpty(List L);

//先自己写然后与书比对
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
//EXERCISE
void Travel(List L);
void PrintLots(List L, List P);
void SwapWithNext(List L, Position BeforeP);
#endif // _LIST_H