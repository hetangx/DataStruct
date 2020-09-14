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

int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
//将元素插入P之后
void Insert(ElementType X, List L, Position P);
//将元素插入P之前
void InsertPrev(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
//打印L中所有元素
void Travel(List L);
//以P的值为下标打印L中元素
void PrintLots(List L, List P);
//交换P后的两个结点
void SwapWithNext(List L, Position BeforeP);
//打印L1、L2的交集
List Intersect(List L1, List L2);
//打印L1、L2的并集
List Union(List L1, List L2);
#endif // _LIST_H