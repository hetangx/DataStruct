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
//��Ԫ�ز���P֮��
void Insert(ElementType X, List L, Position P);
//��Ԫ�ز���P֮ǰ
void InsertPrev(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
//��ӡL������Ԫ��
void Travel(List L);
//��P��ֵΪ�±��ӡL��Ԫ��
void PrintLots(List L, List P);
//����P����������
void SwapWithNext(List L, Position BeforeP);
//��ӡL1��L2�Ľ���
List Intersect(List L1, List L2);
//��ӡL1��L2�Ĳ���
List Union(List L1, List L2);
#endif // _LIST_H